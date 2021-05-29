//problem: 677. Map Sum Pairs

// Implement the MapSum class:

// MapSum() Initializes the MapSum object.
// void insert(String key, int val) Inserts the key-val pair into the map. If the key already existed, the original key-value pair will be overridden to the new one.
// int sum(string prefix) Returns the sum of all the pairs' value whose key starts with the prefix.
 

// Example 1:

// Input
// ["MapSum", "insert", "sum", "insert", "sum"]
// [[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
// Output
// [null, null, 3, null, 5]

// Explanation
// MapSum mapSum = new MapSum();
// mapSum.insert("apple", 3);  
// mapSum.sum("ap");           // return 3 (apple = 3)
// mapSum.insert("app", 2);    
// mapSum.sum("ap");           // return 5 (apple + app = 3 + 2 = 5)
 

// Constraints:

// 1 <= key.length, prefix.length <= 50
// key and prefix consist of only lowercase English letters.
// 1 <= val <= 1000
// At most 50 calls will be made to insert and sum.





class trienode{
    public:
        trienode* arr[26];
        int eow;
    trienode(){
    for(int i=0;i<26;i++)
            this->arr[i]=nullptr;
        this->eow=0;   
    }
  };

class MapSum {
public:
    trienode* root; 
    MapSum() {
         root= new trienode();   
    }
    
    void insert(string word, int val) {
        trienode* ptr=root;
        for(int i=0;i<word.length();i++){
            if(ptr->arr[word[i]-'a']== nullptr)
                ptr->arr[word[i]-'a']= new trienode();
            ptr=ptr->arr[word[i]-'a'];
        }
        ptr->eow=val;
    }
    int sump(trienode *start){
        if(!start) return 0;
        int x=start->eow;
        trienode* ptr=start;
        for(int j=0;j<26;j++){
            if(ptr->arr[j]) {
               x+=sump(ptr->arr[j]);
            }
        }
        return x;
    }
    int sum(string word) {
           trienode * ptr=root;
        for(int i=0;i<word.length();i++){
         if(ptr)ptr=ptr->arr[word[i]-'a'];
        }        
            return sump(ptr);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
