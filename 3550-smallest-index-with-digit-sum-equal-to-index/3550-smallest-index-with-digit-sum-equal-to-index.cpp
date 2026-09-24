class Solution {
public:
    int dSum(int n){
        int s=0;
        while(n>0){
            int r=n%10;
            s+=r;
            n/=10;
        }
        return s;
    }

    int smallestIndex(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
            if(dSum(nums[i])==i) return i;

        return -1;
    }
};