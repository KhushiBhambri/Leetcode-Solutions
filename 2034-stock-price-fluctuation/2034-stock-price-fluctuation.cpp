class StockPrice {
public:
    map<int,int> m;
    priority_queue<pair<int,int>> maxi;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> mini;
    int curr;
    StockPrice() 
    {
       curr=0;
    }
    
    void update(int timestamp, int price) 
    {
          maxi.push({price,timestamp});
          mini.push({price,timestamp}); 
          m[timestamp]=price;
          if(timestamp > curr) curr=timestamp;
    }
    
    int current() {
        return m[curr];
    }
    
    int maximum() {
        int t=maxi.top().second;
        int p = maxi.top().first;
        while(m[t]!=p) {
            maxi.pop();
            t=maxi.top().second;
            p = maxi.top().first;
        }
        
        return p;
    }
    
    int minimum() {
      int t=mini.top().second;
        int p = mini.top().first;
        while(m[t]!=p) {
            mini.pop();
            t=mini.top().second;
            p = mini.top().first;
        }
        
        return p;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */