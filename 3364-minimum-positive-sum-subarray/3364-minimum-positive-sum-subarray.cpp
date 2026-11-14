class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();

        vector<int> prefix(n);
        prefix[0]=nums[0];
        for(int i=1;i<n;i++) prefix[i]=nums[i]+prefix[i-1];

        int ans=INT_MAX;
        for(int k=l;k<=r;k++){
            int i=0, j=k-1;
            while(j<n){
                int sum=(i>0)?prefix[j]-prefix[i-1]:prefix[j];
                if(sum>0) ans=min(ans,sum);
                i++;
                j++;
            }
        }

        return (ans!=INT_MAX)?ans:-1;
    }
};
