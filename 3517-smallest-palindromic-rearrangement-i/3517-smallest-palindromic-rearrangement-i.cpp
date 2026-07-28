class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26,0);
        for(char i:s) freq[i-'a']++; // finding freq in vector

        string first="", mid="", last="";
        for(int i=0;i<26;i++){
            char curr='a'+i;
            
            if(freq[i]%2 != 0) mid+=curr; // separating 1 element from odd freq char

            first+=(string(freq[i]/2,curr)); // appending first half
        }

        last = first;
        reverse(last.begin(),last.end()); // forming last half

        return first+mid+last; // merging to ans
    }
};

// O(n) O(1)
// first we find freq in vector, then traverse vector to acccess freq alphabetically
// either all char freq is even or only 1 char have freq odd rest even
// if any odd freq found we will take 1 of that char and place in middle
// for the rest we add freq/2 for first part, as rest go in last part
// at last we return first part + mid part(single odd) + last(reverse of first)