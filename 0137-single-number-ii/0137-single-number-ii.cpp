class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int sum=0;
            for(int j=0;j<nums.size();j++){
                sum+=(nums[j]>>i)&1; // adding bits of all elements at i-th position
            }
            sum%=3; // bit at i-th position
            ans=ans | (sum<<i); // forming the extra element 
        }
        return ans;
    }
};

// O(n) O(1) Bit Manipulation
// only 1 number is extra, so in binary, all elements will repeat same bits except 1 mismatch
// eg. 1 1 1 2 3 3 3
//  001
//  001
//  001
//  010
//  011
//  011
// +011
// ----
// 046 -> adding mods of each digit with 3 
// (0%3)+(4%3)+(6%3) = 010 which is 2; the extra number