class Solution {
public:
    int dp[50001];
    int recursion(vector<int>& nums, int i){
        int n=nums.size();
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int result=nums[i]-recursion(nums,i+1); // Alice-Bob score(if current player takes 1 element)
        if(i+1<n)
            result=max(result,nums[i]+nums[i+1]-recursion(nums,i+2)); // Alice-Bob score(if current player takes 2 element)
        if(i+2<n)
            result=max(result,nums[i]+nums[i+1]+nums[i+2]-recursion(nums,i+3)); // Alice-Bob score(if current player takes 3 element)
        
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

// Recursion, DP
// for each step player can,
// choose first element and leave rest for other player (nums[i]-recursion(nums,i+1))
// choose first+second element and leave rest for other player (nums[i]+nums[i+1]-recursion(nums,i+2))
// choose first+second+third element and leave rest for other player (nums[i]+nums[i+1]+nums[i+2]-recursion(nums,i+3))
// we subtract as we are finding Alice-Bob for each step and recursion calculates rest
