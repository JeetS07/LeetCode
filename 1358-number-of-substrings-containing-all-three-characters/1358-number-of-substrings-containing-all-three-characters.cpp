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

// O(n) O(1)
// suppose for s=abcaa, now i=0,j=2 forms a valid substring but we dont ans++ as the
// current valid substring doesnt contribute to 1 ans...if we know abc in abcaa is valid
// then abc abca and abcaa is also valid...so it contributes to 3 ans(n-j), as the question have stated 
// valid substring as having ATLEAST 1 a,b and c