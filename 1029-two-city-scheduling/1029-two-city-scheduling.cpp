class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int>> arr;
        int n=costs.size();

        for(int i=0;i<n;i++)
            arr.push_back({costs[i][1]-costs[i][0],i});

        sort(arr.begin(),arr.end());

        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(i < n/2 ? costs[arr[i].second][1] : costs[arr[i].second][0]);
        }

        return ans;
    }
};