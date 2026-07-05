class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int i=0,j=0,m=s.size();
        for(char c:t){
            if(s[i]==c) i++;
            i=max(i,j+1);
            if(s[j]==c) j++;
            if(i==m or j==m) return true;
        }
        return false;
    }
};
