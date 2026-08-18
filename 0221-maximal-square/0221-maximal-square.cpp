class Solution {
public:
    int dp[301][301];
    int solve(int i, int j, int &maxSide, vector<vector<char>> &matrix){
        if(i>=matrix.size() || j>=matrix[0].size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int right=solve(i,j+1,maxSide,matrix);
        int diagonal=solve(i+1,j+1,maxSide,matrix);
        int bottom=solve(i+1,j,maxSide,matrix);

        if(matrix[i][j]=='1'){
            int ans = 1 + min({right,diagonal,bottom});
            maxSide=max(maxSide,ans);
            return dp[i][j] = ans;
        }
        else return dp[i][j] = 0;
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        solve(0,0,ans,matrix);
        return ans*ans;
    }
};