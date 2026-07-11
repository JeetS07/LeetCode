class Solution {
public:
    void dfs(int node, unordered_map<int,vector<int>> &adj, vector<int> &elements,  vector<bool> &visited){
        visited[node]=true;
        elements.push_back(node);

        for(int i:adj[node]){
            if(visited[i]==false) dfs(i,adj,elements,visited);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<bool> visited(n,false);
        int ans=0;

        unordered_map<int,vector<int>> adj;
        for(auto &i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        for(int i=0;i<n;i++){
            if(visited[i]==false){
                vector<int> elements;
                dfs(i,adj,elements,visited);

                int out=elements.size()-1;
                bool flag=true;
                for(int i:elements){
                    if(adj[i].size()<out) flag=false;
                }

                if(flag) ans++;
            }
        }

        return ans;
    }
};