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
        dfs(1,adj,connected); // marking only connected nodes as true

        int ans=INT_MAX;
        for(auto i:roads){
            if(connected[i[0]] || connected[i[1]]) ans=min(ans,i[2]); // finding min among the true marked nodes
        }

        return ans;
    }
};

// O(n) O(n)
// we need to find the min roads[i[2]] among the connected nodes
// using dfs to mark all disconnected nodes as false in connected
// now among the left true marked nodes in finding the min path