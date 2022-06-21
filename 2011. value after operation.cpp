class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        //operations = ["++X","++X","X++"]
        int X=0;
        int n= operations.size();
        for(int i=0 ; i<n ; i++){
               if(operations[i] == "X--" || operations[i] == "--X" )     
                   X--;
               if(operations[i] == "X++" || operations[i] == "++X" )     
                   X++;
        }
        
        return X;
    }
};