class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx=INT_MIN;
        for(int i:nums) if(i>mx) mx=i;

        int ans=0;
        for(int i:nums) ans+=(mx-i);

        return ans;
    }
};