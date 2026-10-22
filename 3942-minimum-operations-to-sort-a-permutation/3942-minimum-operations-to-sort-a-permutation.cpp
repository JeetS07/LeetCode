class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();

        int asc_c=0, dsc_c=0;

        for(int i=1;i<n;i++){
            asc_c+=(nums[i]==(nums[i-1]+1)%n);
            dsc_c+=(nums[i-1]==(nums[i]+1)%n);
        }

        if(asc_c==n-1 && nums[0]==0) return 0;

        if(asc_c==n-1){
            int leftR=n-nums[0];
            int rightR=2+(nums.back()+1);

            return min(leftR,rightR);
        }

        if(dsc_c==n-1){
            int leftR=n-nums.back() + 1;
            int rightR=(nums[0]+1)%n + 1;

            return min(leftR,rightR);
        }

        else return -1;
    }
};