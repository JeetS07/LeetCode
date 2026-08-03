class Solution {
public:
    int dp[50001];
    int recursion(vector<int>& nums, int i){
        int n=nums.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int result=nums[i]-recursion(nums,i+1);
        if(i+1<n)
            result=max(result,nums[i]+nums[i+1]-recursion(nums,i+2));
        if(i+2<n)
            result=max(result,nums[i]+nums[i+1]+nums[i+2]-recursion(nums,i+3));
        
        return dp[i]=result;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        int ans = recursion(stoneValue,0);
        if(ans>0) return "Alice";
        else if(ans<0) return "Bob";
        else return "Tie";
    }
};