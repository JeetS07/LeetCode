class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size(), ans=0, c=1;
        while(n>8){
            ans+=(8*c++);
            n-=8;
        }
        ans+=(n*c);
        return ans;
    }
};