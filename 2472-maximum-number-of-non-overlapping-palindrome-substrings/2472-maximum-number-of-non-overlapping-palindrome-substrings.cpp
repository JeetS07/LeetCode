class Solution {
public:
    int n;
    int dp[2001][2001];

    bool isP(string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;

            i++;
            j--;
        }

        return true;
    }

    int solve(string &s, int &k, int i, int j){
        if(j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(isP(s,i,j)){
            int take=1+solve(s,k,j+1,j+k);
            int grow=solve(s,k,i,j+1);
            int slide=solve(s,k,i+1,j+1);

            return dp[i][j] = max({take,grow,slide});
        }

        int grow=solve(s,k,i,j+1);
        int slide=solve(s,k,i+1,j+1);

        return dp[i][j] = max(grow,slide);
    }

    int maxPalindromes(string s, int k) {
        n=s.size();
        memset(dp,-1,sizeof(dp));

        if(k==1) return n;
        return solve(s,k,0,k-1);
    }
};

// Recursion, DP
// O(n^3) O(n^2)

// we are staring with first substring of size k, from there we have 2 outcomes
// curr is Palindrome, we have 3 choices:
//        take the curr substring for ans and check next substring of size k
//        dont take the curr substring for ans and increase substring size
//        dont take the curr substring for ans and slide the k size window
// curr is not Palindrome, we have 2 choices:
//        dont take the curr substring for ans and increase substring size
//        dont take the curr substring for ans and slide the k size window