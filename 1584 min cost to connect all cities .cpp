//1584. Min Cost to Connect All Points
//Medium
//
//468
//
//28
//
//Add to List
//
//Share
//You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
//
//The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
//
//Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.
//
// 
//
//Example 1:
//
//
//
//Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
//Output: 20
//Explanation:
//
//We can connect the points as shown above to get the minimum cost of 20.
//Notice that there is a unique path between every pair of points.
//Example 2:
//
//Input: points = [[3,12],[-2,5],[-4,1]]
//Output: 18
//Example 3:
//
//Input: points = [[0,0],[1,1],[1,0],[-1,1]]
//Output: 4
//Example 4:
//
//Input: points = [[-1000000,-1000000],[1000000,1000000]]
//Output: 4000000
//Example 5:
//
//Input: points = [[0,0]]
//Output: 0
class Solution {
public:
struct edge {
	int a;
	int b;
	int w;
};
    edge arr[1000000];
int par[10001];
   static  bool cmp(edge a ,edge b){
	return a.w<b.w;
}
int find(int a){
	if(par[a]==-1)
	return a;
	return par[a]=find(par[a]);
}
void merge (int a,int b){
	par[a]=b;
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        for(int i=0;i<1001;i++){
	par[i]=-1;
}
        int k=0;
        for(int i=0;i<points.size();i++){
            for(int j=0;j<points.size();j++){
                if(i>j){
            arr[k].a=i;
              arr[k].b=j;
              arr[k].w=((abs(points[j][1]-points[i][1]))+(abs(points[j][0]-points[i][0])));
                k++;}}
        }
        sort(arr,arr+k,cmp);
int sum=0;
for(int i=0;i<k;i++){
	int  a=find(arr[i].a);
	int   b=find(arr[i].b);
	  if(a!=b){
	  	sum+=arr[i].w;
	  	merge(a,b);
	  }
}
        
        return sum;
    }
};



