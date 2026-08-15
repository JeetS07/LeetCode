class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x=0;
        bool all_zero=true;

        for(int i:nums){
            x=x^i;
            if(i!=0) all_zero=false;
        } 

        if(all_zero) return 0;
        if(x!=0) return nums.size();
        else return nums.size()-1;
    }
};

// O(n) O(1) Bit Manipulation
// if all elements are 0, then we dont have any subsequence with non 0 xor
// if entire array xor is non zero array length is ans
// else we can use this property of xor: if all elements xor to 0,
// removing any non zero element results in the remaining xor equal to the removed element