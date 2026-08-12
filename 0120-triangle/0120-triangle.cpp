class Solution {
public:
    int dp[201][201];

    int solve(int i, int j, int n, vector<vector<int>>& triangle){
        if(i==n-1) return triangle[i][j];
        if(dp[i][j]!=INT_MAX) return dp[i][j];

        return dp[i][j] = triangle[i][j] + min(
            solve(i+1,j,n,triangle),
            solve(i+1,j+1,n,triangle)
        );
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=0;i<201;i++){
            for(int j=0;j<201;j++){
                dp[i][j]=INT_MAX;
            }
        }

        int n=triangle.size();
        return solve(0,0,n,triangle);
    }
};