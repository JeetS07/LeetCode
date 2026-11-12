class Solution {
public:
    long long countValidSubstrings(string s) {
        int i=0;
        long long ans=0;
        for(int j=0;j<s.size();j++){
            if(j>=2 && (s[j-2]=='a' && s[j-1]=='b' && s[j]=='c')) i=j-1;
            ans+=(j-i+1);
        }
        return ans;
    }
};