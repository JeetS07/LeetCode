class Solution {
public:
    int dp[201][201][201];
    int MOD = 1e9 + 7;
    int recursion(vector<int>& nums, int i, int first, int second){
        if(i==nums.size()){
            bool noSeqEmpty = (first!=0 && second!=0);
            bool isEqualGcd = (first==second);

            return (noSeqEmpty && isEqualGcd) ? 1 : 0;
        }
        if(dp[i][first][second]!=-1) return dp[i][first][second];

        int skip = recursion(nums,i+1,first,second);
        int take1 = recursion(nums,i+1,__gcd(first,nums[i]),second);
        int take2 = recursion(nums,i+1,first,__gcd(second,nums[i]));

        return dp[i][first][second] = (0LL + skip + take1 + take2) % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return recursion(nums,0,0,0);
    }
};