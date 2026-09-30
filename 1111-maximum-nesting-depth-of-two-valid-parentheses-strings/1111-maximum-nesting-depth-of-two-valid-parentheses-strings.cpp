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

// O(n)
// we try to divide the total depth in 2 groups to get the minimal depth in either grps
// when we hit a opening bracket it increases depth, if current depth is even we send it to 
// group 0 else group 1, thereby divide equally among 2 groups, while each grp with minimal
// possible depth. we also need to keep groups balanced, so applying the same logic on closing
// bracket. if the decreased depth after hitting closing bracket, is even we send it to 0 else 1