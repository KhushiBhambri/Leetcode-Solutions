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
            int RestSum=sum-top;
            if(top==1 || RestSum==1) return true;
            if(RestSum>=top || RestSum<=0) return false;
            int num=top%RestSum;
            if(num<=0) return false;
            sum=RestSum+num;
            pq.push(num);
        }
        return false;
    }
};