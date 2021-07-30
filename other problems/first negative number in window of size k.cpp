vector<long long> printFirstNegativeInteger(long long int Arr[],
                                             long long int N, long long int K) {
             int i=0;
        int j=0;
   vector<long long int>ans;
   deque<int>q;
   
        int k=K;
        while(j<N){
            
            if(Arr[j]<0){
                q.push_back(j);
            }
            
            if(j-i+1==k){
                if(q.size()>=1){
                    ans.push_back(Arr[q.front()]);
                }
                else 
                ans.push_back(0);
                
                if(q.size()>0&&q.front()==i){
                    q.pop_front();
                }
                i++;
            }
            
            j++;
            
        }
        
        
        return ans;                                      
 }
