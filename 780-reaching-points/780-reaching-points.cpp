class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(sx<=tx && sy<=ty){
           // if(sx==tx && sy==ty) return true;
           // cout<<tx<<" "<<ty<<endl;
            if(tx>ty){
                if(sy == ty) return (tx - sx) % ty == 0;
                tx=tx%ty;
            }
            else{
                if(sx == tx) return (ty - sy) % tx == 0;
                ty=ty%tx;
            }
        }
        return false;
    }
};