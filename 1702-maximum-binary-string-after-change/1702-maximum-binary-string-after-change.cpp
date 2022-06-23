class Solution {
public:
    string maximumBinaryString(string b) {
        int n = b.size();
        string ans="";
        int i=0;
        while(i<n){
           if(b[i]=='1') ans+="1";
            else break;
            i++;
        }
        // cout<<i<<endl;
        int z=0,o=0;
        while(i<n){
            if(b[i]=='1') o++;
            else z++;
            if(z>1) { ans+="1"; z--;}
            i++;
        }
        if(z) ans+="0";
        while(o--) ans+="1";
        return ans;
        
        
    }
};