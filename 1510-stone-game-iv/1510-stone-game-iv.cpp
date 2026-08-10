class Solution {
public:
    int dp[100001];
    bool solve(int n){
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        for(int i=1;i*i<=n;i++){
            // if second player return false, first player wins
            if(solve(n-i*i)==0) return dp[n] = 1;
        }
        return 0;
    }

    bool winnerSquareGame(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};