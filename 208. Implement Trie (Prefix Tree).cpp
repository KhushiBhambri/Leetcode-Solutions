//problem: 208. Implement Trie (Prefix Tree)

// A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings.
// There are various applications of this data structure, such as autocomplete and spellchecker.

// Implement the Trie class:

// Trie() Initializes the trie object.
// void insert(String word) Inserts the string word into the trie.
// boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
// boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 

// Example 1:

// Input
// ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
// [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
// Output
// [null, null, true, false, true, null, true]

// Explanation
// Trie trie = new Trie();
// trie.insert("apple");
// trie.search("apple");   // return True
// trie.search("app");     // return False
// trie.startsWith("app"); // return True
// trie.insert("app");
// trie.search("app");     // return True
 

// Constraints:

// 1 <= word.length, prefix.length <= 2000
// word and prefix consist only of lowercase English letters.
// At most 3 * 104 calls in total will be made to insert, search, and startsWith.


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

class Trie {
public:
    trienode* root; 
    Trie() {
          root= new trienode();       
    }
    
    void insert(string word) {
        trienode* ptr=root;
        for(int i=0;i<word.length();i++){
            if(ptr->arr[word[i]-'a']== nullptr)
                ptr->arr[word[i]-'a']= new trienode();
            ptr=ptr->arr[word[i]-'a'];
        }
        ptr->eow=1;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
         trienode * ptr=root;
        for(int i=0;i<word.length();i++){
            if(ptr->arr[word[i]-'a']==nullptr) return 0;
         ptr=ptr->arr[word[i]-'a'];
        }
        return (ptr->eow);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        trienode * ptr=root;
        for(int i=0;i<prefix.length();i++){
            if(ptr->arr[prefix[i]-'a']==nullptr) return 0;
         ptr=ptr->arr[prefix[i]-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
