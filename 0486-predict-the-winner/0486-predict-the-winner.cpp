class Solution {
public:
    int solve(vector<int>& nums, int i, int j){
        if(i>j) return 0;
        if(i==j) return nums[i];

        int take_i=nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));
        int take_j=nums[j]+min(solve(nums,i+1,j-1),solve(nums,i,j-2));

        return max(take_i,take_j);
    }

    bool predictTheWinner(vector<int>& nums) { 
        int total=0, n=nums.size();
        for(int i:nums) total+=i;

        int player1=solve(nums,0,n-1);
        int player2=total-player1;

        return player1>=player2;
    }
};