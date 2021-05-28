//.Given a weighted undirected graph. Find the sum of weights of edges of a Minimum Spanning Tree.
//
//Input:
//Given 2 integers N and M. N represents the number of vertices in the graph. M represents the number of edges between any 2 vertices.
//Then M lines follow, each line has 3 space separated integers  , ,  where  and  represents an edge from a vertex  to a vertex  and  respresents the weight of that edge.
//
//Output:
//Print the summation of edges weights in the MST.



#include<bits/stdc++.h>
using namespace std;
#define db double
#define ll long long
struct edge {
	int a;
	int b;
	int w;
};
edge arr[100000];
int par[10001];
bool cmp(edge a ,edge b){
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

int main(){
int n,m,a,b,w;
cin>>n;
cin>>m;
for(int i=0;i<n;i++){
	par[i]=-1;
}

for(int i=0;i<m;i++){
	cin>>arr[i].a>>arr[i].b>>arr[i].w;
}

sort(arr,arr+m,cmp);
int sum=0;
for(int i=0;i<m;i++){
	 a=find(arr[i].a);
	  b=find(arr[i].b);
	  if(a!=b){
	  	sum+=arr[i].w;
	  	merge(a,b);
	  }
}
cout<<sum<<endl;

return 0;}
