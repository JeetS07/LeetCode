class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int d=0;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                d++;
                ans.push_back((d%2==0) ? 0 : 1);
            }
            else{
                ans.push_back((d%2==0) ? 0 : 1);
                d--;
            }
        }

        return ans;
    }
};