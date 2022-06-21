class Solution {
public:
    int solve(string s,vector<vector<bool>>& dp,int i,vector<int> & d) {
        if(i==s.size()) return -1;
        if(d[i]!=1e9) return d[i];
        for(int k=0;k<s.size();k++){
            if(dp[i][k])  d[i] = min(d[i],1+solve(s,dp,k+1,d));
        }
        return d[i];
    }
    int minCut(string s){
    
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool> (n,false));
        vector<int> d(n,1e9);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i;j<n;j++){
                int l = j-i+1;
                if(l==1) dp[i][j]=true;
                else if(l==2) dp[i][j]= (s[i]==s[j]);
                else dp[i][j] = (s[i]==s[j]) && dp[i+1][j-1];
            }
        }
        solve(s,dp,0,d);
        return d[0];
    }
};