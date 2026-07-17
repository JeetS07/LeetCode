class Solution {
public:
    int dp[2501][2501];
    int recursion(vector<int>& nums, int prev, int curr){
        if(curr>=nums.size()) return 0;
        if(dp[prev+1][curr]!=-1) return dp[prev+1][curr];

        int take=0;
        if(prev==-1 || nums[curr]>nums[prev])
            take = 1+recursion(nums,curr,curr+1);
        int notTake=recursion(nums,prev,curr+1);

        return dp[prev+1][curr] = max(take,notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return recursion(nums,-1,0);
    }
};

// Recursion + Memoisation
// storing in dp[prev+1][curr] and not dp[prev][curr] as we are staring
// (prev,curr) from (-1,0) and dp arr index cant store in dp[-1][0]