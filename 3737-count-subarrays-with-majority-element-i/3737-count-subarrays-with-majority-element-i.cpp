class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int count=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==target) count+=1;
                else count-=1;
                if(count>0) ans++;
            }
        }    
        return ans;
    }
};

// using brute force
// incrementing count by 1 when a target is found and decrementing by one when not
// thus whenever there is a subarray with target majority elements, count will be > 0
// O(n^2) O(1)