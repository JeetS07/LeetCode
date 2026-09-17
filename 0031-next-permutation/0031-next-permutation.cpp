class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(), i;
        
        for(i=n-2;i>=0;i--) if(nums[i]<nums[i+1]) break;
        if(i==-1){ // if array is entirely descending, no next greater permutation
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

// O(n) O(1)

// 4 steps:
// find the index i1 from last whose value is less then its next index value (nums[i]<nums[i+1])
// now find the index i2 from last which is greater than nums[i1]
// swap nums[i1], nums[i2]
// reverse from i1+1 index to last