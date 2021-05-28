//problem : 211. Design Add and Search Words Data Structure

// Design a data structure that supports adding new words and finding if a string matches any previously added string.

// Implement the WordDictionary class:

// WordDictionary() Initializes the object.
// void addWord(word) Adds word to the data structure, it can be matched later.
// bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. 
// word may contain dots '.' where dots can be matched with any letter.
 

// Example:

// Input
// ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
// [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
// Output
// [null,null,null,null,false,true,true,true]

// Explanation
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("bad");
// wordDictionary.addWord("dad");
// wordDictionary.addWord("mad");
// wordDictionary.search("pad"); // return False
// wordDictionary.search("bad"); // return True
// wordDictionary.search(".ad"); // return True
// wordDictionary.search("b.."); // return True
 

// Constraints:

// 1 <= word.length <= 500
// word in addWord consists lower-case English letters.
// word in search consist of  '.' or lower-case English letters.
// At most 50000 calls will be made to addWord and search.



class trienode{
   public:
        trienode* arr[26];
        bool eow;
    trienode(){
    for(int i=0;i<26;i++)
         this->arr[i]=nullptr;
        this->eow=0;   
    }
  };
class WordDictionary {
public:
    trienode* root; 
    WordDictionary() {
         root= new trienode();   
    }
    bool searchs(trienode *start,string word,int i) {
         trienode * ptr=start;
        if(i==word.length()) return (ptr->eow);
            if(word[i]!='.'){ 
            if(ptr->arr[word[i]-'a']==nullptr)                
                return 0;
            else 
               if(! searchs(ptr->arr[word[i]-'a'],word,i+1)) return 0;
            }
         else{  
             int j=0;
             for(;j<26;j++){
                 if(ptr->arr[j] && searchs(ptr->arr[j],word,i+1))
                   break;
             }   if(j==26) return false;         
           }
         return true;
    }
    
    void addWord(string word) {
         trienode* ptr=root;
        for(int i=0;i<word.length();i++){
            if(ptr->arr[word[i]-'a']== nullptr)
                ptr->arr[word[i]-'a']= new trienode();
            ptr=ptr->arr[word[i]-'a'];
        }
        ptr->eow=1;
    }
    
    bool search(string word) {
       return searchs(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
