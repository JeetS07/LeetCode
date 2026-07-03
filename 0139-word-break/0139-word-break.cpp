class Solution {
public:
    bool recursion(int i,string &s,unordered_set<string> &set,vector<int> &dp){
        if(i==s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        string temp;
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(set.count(temp)!=0){
                if(recursion(j+1,s,set,dp)==1) return dp[i]=1;
            }
        }
        return dp[i]=0;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(),-1);
        unordered_set<string> set;
        for(string i:wordDict) set.insert(i);
        return recursion(0,s,set,dp);
    }
};