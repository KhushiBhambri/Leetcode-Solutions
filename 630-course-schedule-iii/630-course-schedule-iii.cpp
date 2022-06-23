class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        priority_queue<int> pq;
        int last=0;
        int ans=0;
        sort(courses.begin(),courses.end(),comp);
        for(int i=0;i<n;i++){
            if(last+courses[i][0]<=courses[i][1]) {
                ans++;
                last+= courses[i][0];
                pq.push(courses[i][0]);
            }
            else{
                if(pq.size() && pq.top()>courses[i][0]){
                    last+=courses[i][0]-pq.top();
                    pq.pop();
                    pq.push(courses[i][0]);
                }
            }
        }
        return ans;
    }
};