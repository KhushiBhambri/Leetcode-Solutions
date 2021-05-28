
//Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i = j < n.
//
//Follow up: Could you do this in O(n) runtime?
//
// 
//
//Example 1:
//
//Input: nums = [3,10,5,25,2,8]
//Output: 28
//Explanation: The maximum result is 5 XOR 25 = 28.
//Example 2:
//
//Input: nums = [0]
//Output: 0
//Example 3:
//
//Input: nums = [2,4]
//Output: 6
//Example 4:
//
//Input: nums = [8,10,2]
//Output: 10
//Example 5:
//
//Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
//Output: 127

class trie{
    public :
   
    trie * next[2];
    bool e;
}
;
class Solution {
public:
    
      trie * root;
   
     trie * getnode(){
          trie * root1=new trie();
    
            root1->next[0]=NULL;
         root1->next[1]=NULL;
       root1->e=0;
        return root1;
    }
    
     void insert(int n) {
        trie * temp=root;
      for(int j=31;j>=0;j--){
          int r=(n>>j)&1;
          if(temp->next[r]==NULL){
             
          temp->next[r]=getnode();}
          
              temp=temp->next[r];
          
      }
        temp->e=1;
    }
    
    int find(int n){
        int ans=0;
            trie * temp=root;
        int j=0;
        for(j=31;j>=0&&temp!=NULL;j--){
            int r=(n>>j)&1;
       
        if(r==0){
            if(temp->next[1]!=NULL){
               ans+=pow(2,j);
                temp=temp->next[1];
            }
            else {
                temp=temp->next[0];
            }
        }
            else { if(temp->next[0]!=NULL){
                  ans+=pow(2,j);
                temp=temp->next[0];
            }
            else {
                temp=temp->next[1];
            }
                
            }
        }
            
        
      
        return ans;
    }
    
    int findMaximumXOR(vector<int>& nums) { root=new trie();
        for(int i=0;i<2;i++){
           root->next[i]=NULL;
        }
      root->e=0;
        for(int a:nums){
            insert(a);
        }
                                          
        int ans=0;
        for(int i=0;i<nums.size();i++){
            ans=max(ans,find(nums[i]));
        }
                                          
        return ans;
    }
};
