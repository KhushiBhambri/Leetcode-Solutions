class Solution {
  public:
    int kLevelSum(int K, string S) {
        // code here
        stack<char>st;
        int ans=0;
        for(int i=0;i<S.size();i++){
            if(S[i]=='('){
                st.push(S[i]);
                
            }
            else if(S[i]==')')
            st.pop();
            
            else {
                int e=0;
                while(i<S.size()&&S[i]!='('&&S[i]!=')'){
                    e=e*10;
                    e+=S[i]-'0';
                 i++;   
                }
                i--;
                if(st.size()==K+1){
                 
                    ans+=e;
                }
            }
        }
        return ans;
    }
};
