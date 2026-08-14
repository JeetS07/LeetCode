class Solution {
public:
    int dp[301][301];
    int MOD = 1e9+7;

    long long findPower(int base, int x){
        long long res=1;
        for(int i=0;i<x;i++) res*=base;
        return res;
    }

    int solve(int i, int curr, int &n, int &x){
        if(curr==n) return 1;
        if(curr>n or i>n) return 0;
        if(dp[i][curr]!=-1) return dp[i][curr];

        long long power = findPower(i,x);
        if(power>n) return dp[i][curr] = 0;

        long long take = solve(i+1,curr+(int)power,n,x);
        long long skip = solve(i+1,curr,n,x);

        return dp[i][curr] = (take+skip) % MOD;
    }

    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        return solve(1,0,n,x) % MOD;
    }
};