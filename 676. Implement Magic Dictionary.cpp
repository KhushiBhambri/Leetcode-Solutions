//problem: 676. Implement Magic Dictionary

// Design a data structure that is initialized with a list of different words. Provided a string, 
// you should determine if you can change exactly one character in this string to match any word in the data structure.

// Implement the MagicDictionary class:

// MagicDictionary() Initializes the object.
// void buildDict(String[] dictionary) Sets the data structure with an array of distinct strings dictionary.
// bool search(String searchWord) Returns true if you can change exactly one character in searchWord to match any string in the data structure, otherwise returns false.
 

// Example 1:

// Input
// ["MagicDictionary", "buildDict", "search", "search", "search", "search"]
// [[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
// Output
// [null, null, false, true, false, false]

// Explanation
// MagicDictionary magicDictionary = new MagicDictionary();
// magicDictionary.buildDict(["hello", "leetcode"]);
// magicDictionary.search("hello"); // return False
// magicDictionary.search("hhllo"); // We can change the second 'h' to 'e' to match "hello" so we return True
// magicDictionary.search("hell"); // return False
// magicDictionary.search("leetcoded"); // return False
 

// Constraints:

// 1 <= dictionary.length <= 100
// 1 <= dictionary[i].length <= 100
// dictionary[i] consists of only lower-case English letters.
// All the strings in dictionary are distinct.
// 1 <= searchWord.length <= 100
// searchWord consists of only lower-case English letters.
// buildDict will be called only once before search.
// At most 100 calls will be made to search.



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

class MagicDictionary {
public:
    trienode* root;     
    void insert(string word) {
        trienode* ptr=root;
        for(int i=0;i<word.length();i++){
            if(ptr->arr[word[i]-'a']== nullptr)
                ptr->arr[word[i]-'a']= new trienode();
            ptr=ptr->arr[word[i]-'a'];
        }
        ptr->eow=1;
    }

    MagicDictionary() {
            root= new trienode();   
    }
    
    void buildDict(vector<string> dict) {
        for(int i=0;i<dict.size();i++){
            insert(dict[i]);
        }
    }
    bool searchs(string st){
        trienode* ptr=root;
        for(int i=0;i<st.length();i++){
            if(ptr->arr[st[i]-'a']==nullptr) return 0;
            ptr=ptr->arr[st[i]-'a'];
        }
        return ptr->eow;
    }
    
    bool search(string s) {
        for(int i=0;i<s.size();i++){
            for(int j=0;j<26;j++){
                if(s[i]!='a'+j) 
                { char p=s[i]; 
                    s[i]=j+'a';
                if(searchs(s)) return 1;
                 s[i]=p;
            }
        }
        }
        return 0;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
