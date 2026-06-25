class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        priority_queue<pair<int,int>> h;
        vector<int> ans;

        for(int i:nums) m[i]++;
        for(auto i:m) h.push({i.second,i.first});

        while(k--){
            ans.push_back(h.top().second);
            h.pop();
        }

        return ans;
    }
};