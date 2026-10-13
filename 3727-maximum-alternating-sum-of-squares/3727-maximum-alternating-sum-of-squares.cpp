class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;

        for(int &i:nums) i=abs(i);
        sort(nums.begin(),nums.end(),greater<int>());

        int mid=(n/2)+(n%2!=0);
        for(int i=0;i<mid;i++){
            ans+=(1LL*nums[i]*nums[i]);
        }

        for(int i=mid;i<n;i++){
            ans-=(1LL*nums[i]*nums[i]);
        }

        return ans;
    }
};
