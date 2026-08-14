class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int> m;
        int n=s.size(), i=0, j=0, ans=2;

        while(j<n){
            m[s[j]]++;
            if(m[s[j]]<=2) ans=max(ans,j-i+1);
            else{
                while(m[s[j]]>2){
                    m[s[i]]--;
                    i++;
                }
            }

            j++;
        }

        return ans;
    }
};

// Sliding Window