
class Solution{
    public:
    vector<int>polyMultiply(int Arr1[], int Arr2[], int M, int N)
    {
        // code here
        map<int,int>mp;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                int t=Arr1[i]*Arr2[j];
               mp[i+j]+=t;
            }
        }
        vector<int>vec;
        M--;
        N--;
        for(int i=0;i<=M+N;i++){
            vec.push_back(mp[i]);
            
        }
        return vec;
        
    }
};
