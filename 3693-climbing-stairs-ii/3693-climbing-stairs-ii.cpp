class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n+1, 0);

        for(int i=n-1; i>=0; i--) {
            int a = costs[i] + 1 + dp[i+1];

            int b = INT_MAX, c = INT_MAX;

            if(i+2 <= n)
                b = costs[i+1] + 4 + dp[i+2];

            if(i+3 <= n)
                c = costs[i+2] + 9 + dp[i+3];

            dp[i] = min({a,b,c});
        }

        return dp[0];
    }
};