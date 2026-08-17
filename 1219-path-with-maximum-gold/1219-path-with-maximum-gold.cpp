class Solution {
public:
    int dfs(int i, int j, int &m, int &n, vector<vector<int>>& grid){
        if(i>=m or i<0 or j>=n or j<0 or grid[i][j]==0) return 0;

        int curr=grid[i][j];
        grid[i][j]=0;
        int localGold=curr;

        localGold = max(localGold, curr+dfs(i,j+1,m,n,grid));
        localGold = max(localGold, curr+dfs(i+1,j,m,n,grid));
        localGold = max(localGold, curr+dfs(i,j-1,m,n,grid));
        localGold = max(localGold, curr+dfs(i-1,j,m,n,grid));

        grid[i][j]=curr;
        return localGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int m=grid.size(), n=grid[0].size();
        int gold=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0) gold=max(gold,dfs(i,j,m,n,grid));
            }
        }

        return gold;
    }
};

// O(n*(3^n)) O(n) DFS, Backtracking
// We try all non zero elements as starting points of dfs
// for each we exlore all 4 direction and keep adding the max score
// after a dfs we backtrack and reset the old value of grid