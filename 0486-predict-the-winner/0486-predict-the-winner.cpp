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

// finding max score of player 1 with player 2 making maximum score
// finding player 2 score by total - player 1
// finding all possibilities, at each step player 1 either chooses i or j
// if he chose i, next steps are i(i+2,j) or j(i+1,j-1) again
// if he chose j, next steps are i(i+1,j-1) or j(i,j-2) again
// taking min as we expect player 2 to play optimally and have best choice
// at last we take the max score we can obtain through all these choices