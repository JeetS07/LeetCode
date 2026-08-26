class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int ones=0;
        string ans="";

        int i=0, j=0;

        while (j<s.size()) {
            if (s[j]=='1')
                ones++;

            if (ones==k) {
                while(s[i]=='0') i++;

                string current = s.substr(i,j-i+1);
                if (ans.empty() || current.size()<ans.size() || (current.size()==ans.size() && current<ans)) 
                    ans = current;

                ones--;
                i++;
            }

            j++;
        }

        return ans;
    }
};