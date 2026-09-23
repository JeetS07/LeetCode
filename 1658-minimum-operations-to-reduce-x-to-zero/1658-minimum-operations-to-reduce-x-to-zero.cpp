class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0, n=nums.size();
        for(int &i:nums) sum+=i;
        sum-=x;

        if(sum==0) return n;

        int i=0, j=0, mx=0, temp=0;
        while(j<n){
            temp+=nums[j];

            while(i<j && temp>sum){
                temp-=nums[i];
                i++;
            }

            if(temp==sum) mx=max(mx,j-i+1);

            j++;
        }

        return (mx==0) ? -1 : n-mx;
    }
};

// O(n) O(1)
// Sliding Window
// We are finding the largest possible subarray with sum (total_sum-x)
// then returning the remaining length outside this subarray (n-subarray_length)
// if (total_sum-x) is zero that means all elements should be removed to make x=0
// if subarray_length is zero that means x cant be made 0, return -1