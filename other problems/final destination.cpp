class Solution {
  public:
    int canReach(long long a, long long b, long long x) {
        // code here
        a=abs(a);
        b=abs(b);
        if(a+b==x)
        return 1;
        else if(a+b>x){
            return 0;
        }
        else if((a+b-x)%2==0)
        return 1;
        else return 0;
    }
};
