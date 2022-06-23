class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n,vector<bool> (n,false));
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                int l = j-i+1;
                if(l==1) dp[i][j]=true;
                else if(l==2) dp[i][j]= (s[i]==s[j]);
                else dp[i][j]= (s[i]==s[j]) && dp[i+1][j-1];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int k=i+2;k<n;k++){
                bool  a = dp[0][i];
                bool b = dp[i+1][k-1];
                bool c = dp[k][n-1];
                if( a && b && c) return true;
            }
        }
        return false;
    }
};

