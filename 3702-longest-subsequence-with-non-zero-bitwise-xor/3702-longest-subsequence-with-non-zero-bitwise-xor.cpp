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