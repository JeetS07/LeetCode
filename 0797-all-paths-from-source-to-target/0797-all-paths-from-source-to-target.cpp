class Solution {
public:
    void solve(int i, vector<int> &path, vector<vector<int>> &ans, vector<vector<int>> &graph){
        path.push_back(i);
        if(i==graph.size()-1) ans.push_back(path);
        else
            for(int j:graph[i]) solve(j,path,ans,graph);
            
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> path;
        solve(0,path,ans,graph);
        return ans;
    }
};