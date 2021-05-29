// problem: 1584. Min Cost to Connect All Points

// You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

// The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|,
// where |val| denotes the absolute value of val.

// Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

 
// Example 1:

// Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
// Output: 20
// Explanation:

// We can connect the points as shown above to get the minimum cost of 20.
// Notice that there is a unique path between every pair of points.
// Example 2:

// Input: points = [[3,12],[-2,5],[-4,1]]
// Output: 18
// Example 3:

// Input: points = [[0,0],[1,1],[1,0],[-1,1]]
// Output: 4
// Example 4:

// Input: points = [[-1000000,-1000000],[1000000,1000000]]
// Output: 4000000
// Example 5:

// Input: points = [[0,0]]
// Output: 0
 

// Constraints:

// 1 <= points.length <= 1000
// -106 <= xi, yi <= 106
// All pairs (xi, yi) are distinct.

class Solution {
public:
int min_vertex(int dist[], bool included[],int V)
{  int min = INT_MAX, mx;
    for (int i = 0; i < V; i++)
        if (included[i] == false && dist[i] < min)
            {min = dist[i], mx = i;}
    return mx;
}
int  prims_MST(int V, vector<vector<int>> &graph) {
    int cost=0;
    int  parent [V],dist [V];
    bool included[V];
    for (int i = 0; i < V; i++)
       {
        dist[i] = INT_MAX;
        included[i] = false;
        }
       dist[0] = 0;
       parent[0] = -1;
    for (int x = 0; x <V-1; x++) {
        int u = min_vertex(dist, included,V);
        included[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && included[v] == false && graph[u][v] <dist[v]){
                parent[v] = u;
                dist[v] = graph[u][v];  }
       }
    for (int i = 1; i < V; i++)
        cost+=graph[parent[i]][i];
    return cost;
  }
int minCostConnectPoints(vector<vector<int>>& points) {
 int V = points.size();         
 vector<vector<int>> graph(V, vector<int>(V));  
  for(int i=0; i<V; i++) {
    for(int j=0; j<V; j++) { 
     graph[i][j] = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
            }
        }
    return prims_MST(V,graph);
        
    }
};
