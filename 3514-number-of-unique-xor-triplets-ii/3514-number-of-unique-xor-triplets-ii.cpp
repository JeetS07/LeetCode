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

// O(n*n)+O(maxElement*n) O(maxElement)
// If we check all triplets in 3 nested loops, it will be O(n^3),
// so we first form xor of all duplets of nums, then with those duplets,
// we check all elements in nums, finally return s2 size