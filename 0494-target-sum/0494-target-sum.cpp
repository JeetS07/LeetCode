class Solution {
public:
    int solve(int i, int sum, vector<int>& nums, int &target){
        if(i==nums.size()){
            if(sum==target) return 1;
            return 0;
        }

        int ans=0;

        ans+= nums[i] + solve(i+1,sum+nums[i],nums,target);
        ans+= -nums[i] + solve(i+1,sum-nums[i],nums,target);

        return ans;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,0,nums,target);
    }
};