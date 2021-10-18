class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
       int n=nums.size();
        // unordered_map <int, int> map;
        // for(int i=0 ;i <n ;i++)
        // {
        //     map[nums[i]]++;
        // }
        // for(int i=0 ; i<n ; i++)
        // {
        //     if(map[nums[i]] == 1)
        //         return nums[i];
        // }  
        int ans=0;
         for(int i=0 ; i<n ; i++)
        {
            ans ^=nums[i];
        }  
        return ans;
        
    }
};