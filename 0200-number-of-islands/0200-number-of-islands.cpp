class Solution {
public:
    bool isValid(int i, int j, int &m, int &n, vector<vector<char>>& grid){
        return (i>=0 && i<m && j>=0 && j<n && grid[i][j]=='1');
    }

    void dfs(int i, int j, int &m, int &n, vector<vector<char>>& grid){
        grid[i][j]='0';
        if(isValid(i+1,j,m,n,grid)) dfs(i+1,j,m,n,grid);
        if(isValid(i,j+1,m,n,grid)) dfs(i,j+1,m,n,grid);
        if(isValid(i-1,j,m,n,grid)) dfs(i-1,j,m,n,grid);
        if(isValid(i,j-1,m,n,grid)) dfs(i,j-1,m,n,grid);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        int m=grid.size(), n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(i,j,m,n,grid);
                }
            }
        }

        return ans;
    }
};