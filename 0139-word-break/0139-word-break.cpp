class Solution {
public:
    bool recursion(int i,string &s,unordered_set<string> &set,vector<int> &dp){
        if(i==s.size()) return 1; // if last char addition ends up in a match then recursive call goes for j+1=s.size() which means we have reached desired target
        if(dp[i]!=-1) return dp[i];
        string temp;
        for(int j=i;j<s.size();j++){
            temp+=s[j]; // forming new string for current stack
            if(set.count(temp)!=0){ 
                if(recursion(j+1,s,set,dp)==1) return dp[i]=1; // if match found checking for further matches
            }
        }
        return dp[i]=0; // if no desired solution found return 0
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        unordered_set<string> set;
        for(string i:wordDict) set.insert(i);
        return recursion(0,s,set,dp);
    }
};

// Dp Memoisation, Recursion
// forming temp string by adding each char, when a match is found, searching progressively for new string match