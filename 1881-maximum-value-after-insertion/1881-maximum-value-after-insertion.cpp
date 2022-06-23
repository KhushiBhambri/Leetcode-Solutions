class Solution {
public:
    string maxValue(string n, int x) {
        string ans="";
        int i=0;
        char c = to_string(x)[0];
        if(n[0]=='-') 
        {
            ans+="-"; 
            i=1;
           
          for(;i<n.length();i++)
            {
                if(n[i]>c) break;
                ans+=n[i];
            }
        }
        else{
            for(;i<n.length();i++)
            {
                if(n[i]<c) break;
                ans+=n[i];
            }
          
        }
        ans+=c;
        if(i<n.length()) ans+= n.substr(i);
        return ans;
    }
};