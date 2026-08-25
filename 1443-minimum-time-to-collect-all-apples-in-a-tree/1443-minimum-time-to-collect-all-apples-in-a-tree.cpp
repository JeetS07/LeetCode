class Solution {
public:
    int dfs(int node, int price, vector<bool> &hasApple, unordered_map<int,vector<int>> &adj, vector<bool> &visited){
        if(visited[node]==true) return 0;
        visited[node]=true;

        int childCost=0;
        for(int i:adj[node]){
            childCost+=dfs(i,2,hasApple,adj,visited);
        }

        if(childCost==0 && hasApple[node]==false) return 0;

        return price + childCost;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        unordered_map<int,vector<int>> adj;
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<bool> visited(n,false);

        return dfs(0,0,hasApple,adj,visited);
    }
};