class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return n;

        int mx=0, mn=0;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[mx]) mx=i;
            if(nums[i]<nums[mn]) mn=i;
        }

        int a=min(mx,mn);
        int b=max(mx,mn);
        
        return min({a+1+n-b, b+1, n-a});
    }
};