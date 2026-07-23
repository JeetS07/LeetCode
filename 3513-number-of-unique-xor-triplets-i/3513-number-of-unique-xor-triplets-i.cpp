class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size(), c=0;
        if(n==1 || n==2) return n;
        while(true){
            int x=pow(2,c++);
            if(x>n) return x;
        }
    }
};

// for 1-n numbers, max xor we can obtain is all bits set to 1
// and we can bring all numbers from 0-n by xorring 3 no.
// eg, nums={1,2,3,4,5}, n=5
// we can take any combination of 3 with repetation allowed
// eg. 1,1,1 -> 1
//     1,1,2 -> 2 ....
// max zor could be 111
// 0 comes when we zor 3 diff number eg. 1,2,3