class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum=0;
        priority_queue<int> pq;
        int n = target.size();
        for(int i=0;i<n;i++) { sum+=target[i]; pq.push(target[i]); }
        while(pq.size()){
            int t = pq.top();
            pq.pop();
            sum-=t;
            if(sum==1 || t==1) return true;
            if(sum>=t || sum<=0|| t%sum<=0 ) return false;
            t=t%sum;
            pq.push(t);
            sum+=t;
        }
        return false;
    }
};
