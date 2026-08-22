class Solution {
public:
    void solve(int i, vector<vector<int>> &ans, vector<int> &nums){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        } 

        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            solve(i+1,ans,nums);
            swap(nums[i],nums[j]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0,ans,nums);
        return ans;
    }
};