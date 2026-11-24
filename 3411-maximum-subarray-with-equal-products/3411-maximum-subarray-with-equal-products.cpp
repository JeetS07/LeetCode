class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++) {
            long long p=nums[i], g=nums[i], l=nums[i];

            for(int j=i+1;j<nums.size();j++) {
                p*=nums[j];
                g=gcd(g,nums[j]);
                l=lcm(l,nums[j]);

                if (p==g*l) ans=max(ans,j-i+1);
                else break;
            }
        }

        return ans;
    }
};