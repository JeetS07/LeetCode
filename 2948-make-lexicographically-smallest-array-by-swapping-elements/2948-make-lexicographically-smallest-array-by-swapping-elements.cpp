class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();

        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({nums[i],i});
        sort(v.begin(),v.end());

        int start=0;
        while(start<n){
            int end=start;
            while(end+1<n && (v[end+1].first - v[end].first)<=limit) end++;

            vector<int> values, indices;
            for(int i=start;i<=end;i++){
                values.push_back(v[i].first);
                indices.push_back(v[i].second);
            }

            sort(indices.begin(),indices.end());

            for(int i=0;i<indices.size();i++) nums[indices[i]]=values[i];

            start=end+1;
        }

        return nums;
    }
};

// Sorting
// nlogn, n

// first we create mapping of value to index in v, then we sort it
// now finding each group and extracting the indexes involved in the grp
// and sorting those, values are already sorted, now we place the values
// in respective index