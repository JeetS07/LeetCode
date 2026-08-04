class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mx=INT_MIN, mn=INT_MAX;
        unordered_set<int> s;
        for(int i:nums){
            mx=max(mx,i);
            mn=min(mn,i);
            s.insert(i);
        }

        vector<int> ans;
        for(int i=mn;i<=mx;i++){
            if(s.count(i)==0) ans.push_back(i);
        }

        return ans;
    }
};

// O(n) O(n)