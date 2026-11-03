class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int mn=INT_MAX;

        for(int i=0;i<nums.size();i+=2){
            int d=to_string(nums[i+1]).size();
            int curr=(nums[i]*pow(10,d)) + nums[i+1];

            if(curr<mn) mn=curr;
        }

        return mn;
    }

};