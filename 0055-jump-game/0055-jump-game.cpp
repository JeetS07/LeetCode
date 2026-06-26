class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPath=0;
        for(int i=0;i<nums.size();i++){
            if(i>maxPath) return 0;
            maxPath=max(maxPath,i+nums[i]);
        }
        return 1;
    }
};