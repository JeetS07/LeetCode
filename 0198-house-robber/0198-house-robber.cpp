class Solution {
public:
    int recursion(vector<int>& nums, int n, vector<int> &dp){
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        
        return dp[n]= max(
            recursion(nums,n-1,dp), // not taking current house
            nums[n-1]+recursion(nums,n-2,dp) // taking current house
        );
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return recursion(nums,n,dp);
    }
};

// DP Memoisation