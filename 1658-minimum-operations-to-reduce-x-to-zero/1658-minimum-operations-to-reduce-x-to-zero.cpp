class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total<x) return -1;
        // if(total==x) return nums.size();
        total-=x;
        
        int l=0;
        int r=0;
        int ans=-1;
        int sum=0;
        while(l<=r && r<nums.size()){
            sum+=nums[r];
            while(l<=r && sum>total){
                 sum-=nums[l]; l++;
            }
            if(sum==total) {
                //cout<<l<<" "<<r;
                ans= max(ans,r-l+1);
            }
            r++;
        }
        ans=nums.size()-ans;
        return ans<=nums.size()?ans:-1;
          
        
    }
};