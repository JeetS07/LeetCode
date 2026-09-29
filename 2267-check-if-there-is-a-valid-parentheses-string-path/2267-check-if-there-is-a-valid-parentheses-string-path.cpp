class Solution {
public:
    int m,n;
    int dp[101][101][201];

    bool solve(int i, int j, int openCount, vector<vector<char>>& grid){
        if(grid[i][j]=='(') openCount++;
        else openCount--;

        // base case
        if(openCount<0) return false;
        if(i==m-1 && j==n-1) return openCount==0;
        if(dp[i][j][openCount]!=-1) return dp[i][j][openCount];

        if(i+1<m && solve(i+1,j,openCount,grid)) return dp[i][j][openCount] = true; // move down
        if(j+1<n && solve(i,j+1,openCount,grid)) return dp[i][j][openCount] = true; // move right

        return dp[i][j][openCount] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size(), n=grid[0].size();

        // if((m+n-1) % 2 == 1) return false;
        // if(grid[0][0]==')' or grid[m-1][n-1]=='(') return false;

        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,grid);
    }
};

// Dp, Recursion
// exploring all possible path using recursion and returning true when a valid is found
// using openCount to track if current parenthesis string is valid, when we find a '(', openCount++
// when we find a ')', openCount--, so openCount==0 give a valid sequence, we also terminate if
// openCount<0, eg. ))((