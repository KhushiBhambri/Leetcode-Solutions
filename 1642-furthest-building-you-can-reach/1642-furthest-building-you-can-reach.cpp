class Solution {
public:
    int furthestBuilding(vector<int>& heights, int b, int l) {
      priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=1;i<heights.size();i++){
            if(heights[i]>heights[i-1]) pq.push(heights[i]-heights[i-1]);
            if(pq.size()>l){
                int t=pq.top(); pq.pop();
                if(b>=t) b-=t;
                else return i-1;
            }
        }
        return heights.size()-1;
    }
};