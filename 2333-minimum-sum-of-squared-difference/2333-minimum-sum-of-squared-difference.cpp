class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n=nums1.size();

        vector<int> diff(n);
        for(int i=0;i<n;i++) diff[i]=abs(nums1[i]-nums2[i]);

        int maxDiff=*max_element(diff.begin(),diff.end());

        vector<int> countDiff(maxDiff+1,0);
        for(int i:diff) countDiff[i]++;

        int k=k1+k2;
        for(int i=maxDiff;i>0 && k>0;i--){
            int ops=min(countDiff[i],k);

            countDiff[i]-=ops;
            countDiff[i-1]+=ops;
            k-=ops;
        }

        long long ans=0;
        for(long long i=1;i<=maxDiff;i++) ans+=(countDiff[i]*i*i);

        return ans;
    }
};