class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        if(num<k) return -1;
        int x=num%10;
        for(int i=1;i<=10;i++){
            if((k*i)%10==x) return (num>=k*i)?i:-1;
        }
        return -1;
    }
};