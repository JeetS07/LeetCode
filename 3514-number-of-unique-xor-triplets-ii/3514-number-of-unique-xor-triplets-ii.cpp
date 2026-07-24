class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> s1,s2;

        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                s1.insert(nums[i]^nums[j]);
            }
        }

        for(int i:s1){
            for(int j:nums){
                s2.insert(i^j);
            }
        }

        return s2.size();
    }
};