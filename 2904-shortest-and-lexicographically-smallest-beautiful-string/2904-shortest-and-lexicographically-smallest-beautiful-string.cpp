class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int ones=0;
        vector<string> ans;

        int i=0, j=0;

        while (j<s.size()) {
            if (s[j]=='1')
                ones++;

            if (ones==k) {
                while(s[i]=='0') i++;

                ans.push_back(s.substr(i,j-i+1));

                ones--;
                i++;
            }

            j++;
        }

        if (ans.empty())
            return "";

        sort(ans.begin(),ans.end(),[](string &a, string &b){
            if(a.size()!=b.size()) return a.size()<b.size();
            return a<b;
        });

        return ans[0];
    }
};