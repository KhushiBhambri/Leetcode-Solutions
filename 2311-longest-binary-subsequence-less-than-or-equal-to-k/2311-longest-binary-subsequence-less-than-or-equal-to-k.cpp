class Solution {
public:

    int longestSubsequence(string s, int k) {
         int n =s.size();
         int i=n-1,c=0;
        long long pow=1;
        int num=0;
        while(i>=0){
            if(s[i]=='1') num+= pow;
            if( num>k || pow>k) break;
            i--; c++;
            pow<<=1;
        }

        while(i>=0){
            if(s[i]=='0') c++;
            i--;
        }
        return c;
    }
};