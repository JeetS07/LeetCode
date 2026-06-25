class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> ans;
        vector<vector<int>> temp(nums.size()+1);

        for(int i:nums) m[i]++;
        for(auto i:m) temp[i.second].push_back(i.first);
        
        for(int i=temp.size()-1;i>=0;i--){
            for(int j:temp[i]){
                ans.push_back(j);
                if(ans.size()==k) return ans;
            }
        }
        
        return ans;
    }
};