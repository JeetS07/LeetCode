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
                for(int i:elements){ // checking if connected component is complete
                    if(adj[i].size()<out) flag=false;
                }

                if(flag) ans++;
            }
        }

        return ans;
    }
};

// O(V+E) O(V+E)
// Applying normal dfs to mark connected components true and for all node
// in a connected component, we are storing the nodes in elements, then if
// all node have a outgoing edge (total nodes in the component - 1) then all are connected to 
// each other, hence it is a complete connected component and increasing ans.