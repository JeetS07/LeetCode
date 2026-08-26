class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int ones=0;
        string ans="";

        int i=0, j=0;

        while (j<s.size()) {
            if (s[j]=='1') // maintaining 1 count in substring
                ones++;

            if (ones==k) {
                while(s[i]=='0') i++; // removing leading 0

                string current = s.substr(i,j-i+1); // current beautiful substring
                if (ans.empty() || current.size()<ans.size() || (current.size()==ans.size() && current<ans)) 
                    ans = current; // maintaining smallest beautiful substring

                ones--; // removing leftmost 1
                i++;
            }

            j++;
        }

        return ans;
    }
};

// Sliding Window
// O(n) O(n)