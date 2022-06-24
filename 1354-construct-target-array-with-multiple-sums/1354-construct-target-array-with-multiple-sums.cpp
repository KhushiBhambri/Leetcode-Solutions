class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum=0;
        priority_queue<int>pq;
        for(auto it:target){
            sum+=it;
            pq.push(it);
        }
        while(1){
            int top=pq.top();
            pq.pop();
            sum-=top;
            if(top==1 || sum==1) return true;
            if(sum>=top ||sum<=0) return false;
            int num=top%sum;
            if(num<=0) return false;
            sum+=num;
            pq.push(num);
        }
        return false;
    }
};