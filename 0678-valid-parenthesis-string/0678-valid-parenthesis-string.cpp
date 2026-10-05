class Solution {
public:
    int dp[101][101];

    bool solve(int i, int open, string &s, int &n){
        if(i==n) return open==0;
        if(dp[i][open]!=-1) return dp[i][open];

        bool isValid=0;
        if(s[i]=='*'){
            isValid |= solve(i+1,open+1,s,n);
            isValid |= solve(i+1,open,s,n);
            if(open>0) isValid |= solve(i+1,open-1,s,n);
        }
        else if(s[i]=='(') isValid |= solve(i+1,open+1,s,n);
        else if(open>0) isValid |= solve(i+1,open-1,s,n);

        return dp[i][open] = isValid;
    }

    bool checkValidString(string s) {
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,n);
    }
};

// Dp Recursion
// we have 3 choices for *, take it as '(' or ')' or ""
// exploring all possible choices, for ')', we only process if open>1