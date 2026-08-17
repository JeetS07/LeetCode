class Solution {
public:
    int dp[501][501];
    int solve(int l, int r, vector<int> &prefix){
        if(l>=r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];

        int score=0;
        for(int mid=l;mid<=r-1;mid++){
            int leftsum= prefix[mid] - (l-1>=0 ? prefix[l-1] : 0);
            int rightsum= prefix[r] - prefix[mid];

            if(leftsum<rightsum) score=max(score,leftsum+solve(l,mid,prefix));
            else if(rightsum<leftsum) score=max(score,rightsum+solve(mid+1,r,prefix));
            else score=max({score,leftsum+solve(l,mid,prefix),rightsum+solve(mid+1,r,prefix)});
        }

        return dp[l][r] = score;
    }

    int stoneGameV(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        int n=stoneValue.size();
        vector<int> prefix(n,0);
        prefix[0]=stoneValue[0];

        for(int i=1;i<n;i++) prefix[i]=prefix[i-1]+stoneValue[i];

        return solve(0,n-1,prefix);
    }
};

// O(n^3) Recursion,DP
// we are using prefix sum to find sum of left or right part in O(1) time
// now exploring all choices of placing mid to all positions, for each position
// finding left and right sum, then finding the score depending on condition
// finally returning score