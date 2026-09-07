class Solution {
public:
    bool canJump(vector<int>& nums) {
        int mx=0;
        for(int i=0;i<nums.size();i++){
            if(i>mx) return 0;
            mx=max(mx,i+nums[i]);
        }

        return 1;
    }
};