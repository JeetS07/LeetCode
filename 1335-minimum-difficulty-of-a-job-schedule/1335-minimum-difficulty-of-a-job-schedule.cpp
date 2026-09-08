class Solution {
public:
    int dp[301][11];
    int solve(int idx, int &n, vector<int> &jd, int d){
        if(d==1){
            int mx=jd[idx];
            for(int i=idx;i<n;i++) mx=max(mx,jd[i]);
            return mx;
        }
        if(dp[idx][d]!=-1) return dp[idx][d];

        int mx=jd[idx];
        int result=INT_MAX;

        for(int i=idx;i<=n-d;i++){
            mx=max(mx,jd[i]);
            int curr = mx + solve(i+1,n,jd,d-1);
            result=min(result,curr);
        }

        return dp[idx][d] = result;
    }

    int minDifficulty(vector<int>& jd, int d) {
        memset(dp,-1,sizeof(dp));
        int n=jd.size();
        if(n<d) return -1;

        return solve(0,n,jd,d);
    }
};

// Recursion
// first keeping 1 job in first day and calling recusrion for rest
// then keeping 2 jobs in first and recursion for rest
// ....