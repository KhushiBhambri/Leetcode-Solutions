class Solution {
public:
    int findDuplicate(vector<int>& nums) {
     unordered_map<int , int> map;
        int n = nums.size();
        int ans;
        for(int i=0 ; i<n+1 ; i++)
        {
            map[nums[i]]++;
            if(map[nums[i]] > 1 ){
                ans = nums[i];
                break;
            }
                
        }
        return ans;
    }
};