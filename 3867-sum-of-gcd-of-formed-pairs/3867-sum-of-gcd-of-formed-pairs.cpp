class Solution {
public:
    typedef long long ll;
    long long gcdSum(vector<int>& nums) {
        int mx=nums[0];
        vector<int> prefixGcd(nums.size());

        for(int i=0;i<nums.size();i++){
            mx=max(mx,nums[i]);
            prefixGcd[i]=__gcd(nums[i],mx);
        }

        sort(prefixGcd.begin(),prefixGcd.end());

        ll ans=0;
        int i=0, j=prefixGcd.size()-1;

        while(i<j){
            ans+=__gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }

        return ans;
    }
};

// Simulation