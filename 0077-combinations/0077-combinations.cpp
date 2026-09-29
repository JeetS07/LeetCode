class Solution {
public:
    vector<vector<int>> ans;

    void solve(int &n, int &k, vector<int> &temp, int start){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }

        for(int i=start;i<=n;i++){
            temp.push_back(i);
            solve(n,k,temp,i+1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(n,k,temp,1);
        return ans;
    }
};