class Solution {
public:
    int dp1[101];
    int dp2[101];

    int solve1(vector<int>& nums, int n){
        if(n<=1) return 0;
        if(dp1[n]!=-1) return dp1[n];

        return dp1[n] = max(
            (nums[n-1]+solve1(nums,n-2)),
            solve1(nums,n-1)
        );
    }

    int solve2(vector<int>& nums, int n){
        if(n<=0) return 0;
        if(dp2[n]!=-1) return dp2[n];

        return dp2[n] = max(
            (nums[n-1]+solve2(nums,n-2)),
            solve2(nums,n-1)
        );
    }

    int rob(vector<int>& nums) {
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        
        int n=nums.size();
        if(n==1) return nums[0];

        return max(
            solve1(nums,n),
            solve2(nums,n-1)
        );
    }
};