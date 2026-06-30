class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> m;
        int ans=0, i=0, j=0;
        while(j<s.size()){
            m[s[j]]++;
            while(m.size()==3){
                ans += s.size() - j;
                m[s[i]]--;
                if(m[s[i]]==0) m.erase(s[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};