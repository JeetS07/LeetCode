class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<int> temp;
        for(auto i:grid){
            for(int j:i){
                temp.push_back(j);
            }
        }

        vector<vector<int>> ans(grid.size(),vector<int> (grid[0].size()));
        k%=temp.size();
        int k1=temp.size()-k;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(k1==temp.size()) k1=0;

                ans[i][j]=temp[k1];
                k1++;
            }
        }

        return ans;

    }
};