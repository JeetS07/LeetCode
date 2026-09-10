class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i:nums) m[i]++;

        vector<vector<int>> v(nums.size()+1);
        for(auto i:m) v[i.second].push_back(i.first);

        vector<int> ans;
        for(int i=v.size()-1;i>0;i--){
            for(int j:v[i]){
                ans.push_back(j);
                if(ans.size()==k) return ans;
            }
        }

        return ans;
    }
};

// O(n) O(n)
// Hashing

// first we are finding freq of all elements, then creating a vector v
// where all elements are stored according to their freq(which is the index)
// now traversing v from last so we get the highest freq at first and appending 
// each element in ans till ans size reaches k