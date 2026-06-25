class Solution {
public:
    vector<vector<int>> ans;

    void bt(vector<int>& nums, vector<int> temp, int i){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }

        bt(nums,temp,i+1);
        temp.push_back(nums[i]);
        bt(nums,temp,i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        bt(nums,{},0);
        return ans;
    }
};