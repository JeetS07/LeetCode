class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mx=INT_MIN, mn=INT_MAX;
        for(int i:nums){
            mx=max(mx,i);
            mn=min(mn,i);
        }
        return __gcd(mx,mn);
    }
};