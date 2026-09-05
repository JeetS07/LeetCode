class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int currMx=nums[0], currMn=nums[n-1];
        vector<int> mx(n), mn(n);

        for(int i=0;i<n;i++){
            currMx=max(currMx,nums[i]);
            mx[i]=currMx;
        } 

        for(int i=n-1;i>=0;i--){
            currMn=min(currMn,nums[i]);
            mn[i]=currMn;
        } 

        int ans=-1;
        for(int i=n-1;i>=0;i--) if(mx[i]-mn[i]<=k) ans=i; 

        return ans;
    }
};