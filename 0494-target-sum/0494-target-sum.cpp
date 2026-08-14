class Solution {
public:
    int dp[21][2001];
    int solve(int i, int sum, vector<int>& nums, int &target){
        if(i==nums.size()){
            if(sum==target) return 1;
            return 0;
        }
        if(dp[i][sum+1000]!=-1) return dp[i][sum+1000];

        int ans=0;

        ans+= nums[i] + solve(i+1,sum+nums[i],nums,target);
        ans+= -nums[i] + solve(i+1,sum-nums[i],nums,target);

        return dp[i][sum+1000] = ans;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,nums,target);
    }
};

// DP, Recursion
// when we reach end of nums, we return 1 if target found else 0
// at each step we have 2 choices, take nums[i] and -nums[i] ans keep appending ans