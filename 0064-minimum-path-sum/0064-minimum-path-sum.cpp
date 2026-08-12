class Solution {
public:
    int dp[201][201];
    int dfs(int i, int j, int r, int c, vector<vector<int>>& grid){
        if(i==r-1 && j==c-1) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        if(i==r-1) return dp[i][j]=grid[i][j]+dfs(i,j+1,r,c,grid);
        else if(j==c-1) return dp[i][j]=grid[i][j]+dfs(i+1,j,r,c,grid);
        else return dp[i][j]=grid[i][j]+min(dfs(i,j+1,r,c,grid),dfs(i+1,j,r,c,grid));
    }

    int minPathSum(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return dfs(0,0,grid.size(),grid[0].size(),grid);
    }
};