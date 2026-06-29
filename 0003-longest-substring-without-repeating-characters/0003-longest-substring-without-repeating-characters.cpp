class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int ans=0, i=0, j=0;
        while(j<s.size()){
            if(set.count(s[j])==0){
                set.insert(s[j]);
                j++;
            }
            else{
                ans=max(ans,j-i);
                while(set.count(s[j])!=0){
                    set.erase(s[i]);
                    i++;
                }
            }
        }
        ans=max(ans,j-i);
        return ans;
    }
};