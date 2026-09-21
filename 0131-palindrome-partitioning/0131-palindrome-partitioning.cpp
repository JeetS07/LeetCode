class Solution {
public:
    vector<vector<string>> ans;

    bool isP(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    void solve(int i, string &s, vector<string> &temp){
        if(i>=s.size()){
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<s.size();j++){
            if(isP(s,i,j)){
                temp.push_back(s.substr(i,j-i+1));
                solve(j+1,s,temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;

        solve(0,s,temp);
        return ans;
    }
};