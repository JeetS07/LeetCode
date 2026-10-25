class Solution {
public:
    bool isValid(vector<vector<int>>& grid, int i, int j){
        int x=grid.size(), y=grid[0].size();
        return (i>=0 && i<x && j>=0 && j<y && grid[i][j]==0);
    }

    void dfs(vector<vector<int>>& grid, int i, int j){ 
        grid[i][j]=1;
        if(isValid(grid,i+1,j)) dfs(grid,i+1,j);
        if(isValid(grid,i,j+1)) dfs(grid,i,j+1);
        if(isValid(grid,i-1,j)) dfs(grid,i-1,j);
        if(isValid(grid,i,j-1)) dfs(grid,i,j-1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int x=grid.size(), y=grid[0].size(), ans=0;
        for(int i=0;i<x;i++){ 
            int j=0;
            if(grid[i][j]==0) dfs(grid,i,j);
            j=y-1;
            if(grid[i][j]==0) dfs(grid,i,j);
        }

        for(int j=0;j<y;j++){ 
            int i=0;
            if(grid[i][j]==0) dfs(grid,i,j);
            i=x-1;
            if(grid[i][j]==0) dfs(grid,i,j);
        }

        for(int i=0;i<x;i++){ 
            for(int j=0;j<y;j++){
                if(grid[i][j]==0){
                    dfs(grid,i,j);
                    ans++;
                }
            }
        }

        return ans;
    }
};
