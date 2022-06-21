class Solution {
public:
    int maxProduct(vector<int>& nums) {     
        int n = nums.size();
        int firstMax = INT_MIN ,  secondMax = INT_MIN;
        for(int i=0 ; i< n ; i++)
        {  
            //finding first maximum number
            if(nums[i] > firstMax)
            {    
                secondMax = firstMax;
                firstMax = nums[i];
             }
            //finding second maximum number
            else if(nums[i] > secondMax and nums[i] <= firstMax)
            {
                secondMax = nums[i];
            }
            
        }
       return (firstMax-1)* (secondMax-1);
    }
};