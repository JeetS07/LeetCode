class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        ios::sync_with_stdio(0); // ignore
        cin.tie(0); // ignore

        if(arr.size()==0) return {};

        vector<int> rank(arr.size()), nums=arr;
        unordered_map<int,int> m;

        sort(nums.begin(),nums.end());
        rank[0]=1;
        int position=1;
        m[nums[0]]=1;

        for(int i=1;i<nums.size();i++){ 
            if(nums[i]>nums[i-1]) position++; 
            rank[i]=position; // calculating rank on sorted array

            m[nums[i]]=position; // mapping elements to rank
        }

        vector<int> ans;
        for(int i:arr) ans.push_back(m[i]);

        return ans;
    }
};