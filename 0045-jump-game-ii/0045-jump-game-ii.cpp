class Solution {
public:
    int jump(vector<int>& nums) {
        int coverage=0, last=0, total=0, n=nums.size();
        if(n==1) return 0;

        for(int i=0;i<n;i++){
            coverage=max(coverage,i+nums[i]);

            if(i==last){
                last=coverage;
                total++;
                if(coverage>=n-1) return total;
            }
        }

        return total;
    }
};