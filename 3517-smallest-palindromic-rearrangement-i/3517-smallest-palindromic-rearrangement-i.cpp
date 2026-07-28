class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        for(char i:s) freq[i-'a']++;

        string first="", mid="", last="";
        for(int i=0;i<26;i++){
            char curr='a'+i;
            
            if(freq[i]%2 != 0) mid+=curr;

            first+=(string(freq[i]/2,curr));
        }

        last = first;
        reverse(last.begin(),last.end());

        return first+mid+last;
    }
};