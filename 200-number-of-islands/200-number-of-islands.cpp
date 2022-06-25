class Solution {
public:
    void visit(vector<vector<char>>& grid,vector<vector<bool>> & visited,int i,int j,int n ,int m){
        visited[i][j]=true;
        if(i<n-1 && grid[i+1][j]=='1' && !visited[i+1][j]) visit(grid,visited,i+1,j,n,m);
        if(j<m-1 && grid[i][j+1]=='1' && !visited[i][j+1]) visit(grid,visited,i,j+1,n,m);
        if(i>0 && grid[i-1][j]=='1' && !visited[i-1][j]) visit(grid,visited,i-1,j,n,m);
        if(j>0 && grid[i][j-1]=='1' && !visited[i][j-1]) visit(grid,visited,i,j-1,n,m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        vector<vector<bool>> visited(n,vector<bool> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    count++;
                    visit(grid,visited,i,j,n,m);
                }
            }
        }
        return count;
    }
};