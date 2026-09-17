class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), i;
        
        for(i=n-2;i>=0;i--) if(nums[i]<nums[i+1]) break;
        if(i==-1){
            reverse(nums.begin(),nums.end());
            return;
        } 

        for(int j=n-1;j>i;j--){
            if(nums[j]>nums[i]){
                swap(nums[j],nums[i]);
                break;
            }
        }

        reverse(nums.begin()+i+1,nums.end());
    }
};

// 