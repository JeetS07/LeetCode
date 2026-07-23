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