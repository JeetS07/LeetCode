class Solution {
public:
    void solve(vector<string> &ans, int n, int open, int close, string current){
        if(current.size()==(n*2)){ 
            ans.push_back(current);
            return;
        }

        if(open<n) solve(ans,n,open+1,close,current+"(");
        if(close<open) solve(ans,n,open,close+1,current+")");
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans,n,0,0,"");
        return ans;
    }
};