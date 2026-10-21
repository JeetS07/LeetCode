class Solution {
public:
    int minOperations(string s) {
        int n=s.size();

        string s2=s;
        sort(s2.begin(),s2.end());

        if(s2==s) return 0;
        if(n==2) return -1;

        char min_c=s2[0];
        char max_c=s2[n-1];
        if(s[0]==min_c || s[n-1]==max_c) return 1;

        char min_mid=s2[1];
        char max_mid=s2[n-2];
        if(s[0]>max_mid && s[n-1]<min_mid) return 3;
        else return 2;
    }
};
