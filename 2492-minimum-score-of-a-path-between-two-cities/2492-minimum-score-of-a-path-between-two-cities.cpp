class Solution {
public:
    void dfs(int i, unordered_map<int,vector<int>> &adj, vector<bool> &connected){
        connected[i]=true;
        for(int node:adj[i]){
            if(connected[node]==false) dfs(node,adj,connected);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<int>> adj;
        for(auto i:roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<bool> connected(n+1,0);
        dfs(1,adj,connected);

        int ans=INT_MAX;
        for(auto i:roads){
            if(connected[i[0]]) ans=min(ans,i[2]);
        }

        return ans;
    }
};