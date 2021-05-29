//648. Replace Words

// Given a dictionary consisting of many roots and a sentence consisting of words separated by spaces, replace all the successors in the sentence with the root forming it.
// If a successor can be replaced by more than one root, replace it with the root that has the shortest length.

// Return the sentence after the replacement.

 
// Example 1:
// Input: dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"

// Example 2:
// Input: dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
// Output: "a a b c"

// Example 3:
// Input: dictionary = ["a", "aa", "aaa", "aaaa"], sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
// Output: "a a a a a a a a bbb baba a"

// Example 4:
// Input: dictionary = ["catt","cat","bat","rat"], sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"

// Example 5:
// Input: dictionary = ["ac","ab"], sentence = "it is abnormal that this solution is accepted"
// Output: "it is ab that this solution is ac"
 

// Constraints:

// 1 <= dictionary.length <= 1000
// 1 <= dictionary[i].length <= 100
// dictionary[i] consists of only lower-case letters.
// 1 <= sentence.length <= 10^6
// sentence consists of only lower-case letters and spaces.
// The number of words in sentence is in the range [1, 1000]
// The length of each word in sentence is in the range [1, 1000]
// Each two consecutive words in sentence will be separated by exactly one space.
// sentence does not have leading or trailing spaces.



class trienode{
        public:
        trienode* arr[26];
        bool endword=0;
         trienode(){
        for(int i=0;i<26;i++)
            this->arr[i]=nullptr;
         this->endword=0;
         }
    };
void insert(trienode* root,string s){
        for(int i=0;i<s.length();i++){
        if(root->arr[s[i]-'a']==nullptr) 
            root->arr[s[i]-'a']= new trienode();
         root=root->arr[s[i]-'a'];
        }
        root->endword= true;
    }
class Solution {       
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string res="";
        trienode* root= new trienode();
        for(int i=0;i<dict.size();i++){
            insert(root,dict[i]);
        }
        trienode* ptr=root;
        for(int i=0;i<sentence.length();i++){
            if(sentence[i]==' ') {res+=" "; ptr=root; continue;}
            if (ptr->endword ==1) {
                res+=" ";
               //cout<<res;
               while(sentence[i]!=' ' && i<sentence.length()){
                    i++;
                }
                ptr=root;
            }
          else if(sentence[i]!=' ' && ptr->arr[sentence[i]-'a']==nullptr){
                while(sentence[i]!=' ' && i<sentence.length() ){
                    res+=sentence[i];
                    i++;
                }
                res+=" ";
              ptr=root;
            }
            else {
             
               ptr=ptr->arr[sentence[i]-'a'];
                res+=sentence[i];
            }
        }
       if(res[res.length()-1]==' ') res.pop_back();
        return res;
    }
};
