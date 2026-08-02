class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& nums, int i, int j){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];

        int take_i=nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));
        int take_j=nums[j]+min(solve(nums,i+1,j-1),solve(nums,i,j-2));

        return dp[i][j]=max(take_i,take_j);
    }
    bool stoneGame(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int total=0, n=nums.size();
        for(int i:nums) total+=i;

        int player1=solve(nums,0,n-1);
        int player2=total-player1;

        return player1>player2;
    }
};