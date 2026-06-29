class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int ans=0, i=0, j=0;
        while(j<s.size()){
            if(set.count(s[j])==0){ // not present 
                set.insert(s[j]);
                j++;
            }
            else{ // present
                ans=max(ans,j-i); // since j is already out of valid substring so we store j-i, not j-i+1
                while(set.count(s[j])!=0){ // erasing from back until subarray is valid
                    set.erase(s[i]);
                    i++;
                }
            }
        }
        ans=max(ans,j-i);
        return ans;
    }
};

// O(n) O(n)