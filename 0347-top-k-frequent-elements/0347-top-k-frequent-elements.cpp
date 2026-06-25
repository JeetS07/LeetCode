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

// O(n) O(n)
// we are using a array temp of nums size, index of temp represent freq
// while iterating throuhg freq map, we push the element to that in temp on the index of its freq
// eg. nums={2,3,2,2,4} m={2->3},{3->1},{4->1}
// temp={{},{4,3},{},{2}}
//       0    1   2   3
// then traversing back from temp and adding elements until ans size==k