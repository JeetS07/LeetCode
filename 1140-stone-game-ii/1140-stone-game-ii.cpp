class Solution {
public:
    int n;
    int dp[2][101][101];
    int solveForAlice(vector<int>& piles, int player, int i, int M){
        if(i>=n) return 0;
        if(dp[player][i][M]!=-1) return dp[player][i][M];
        int result = (player==1) ? -1 : INT_MAX;
        int stones=0;

        for(int x=1;x<=min((n-i),(2*M));x++){
            stones+=piles[i+x-1];
            if(player==1) //Alice
                result = max(result,stones+solveForAlice(piles,0,i+x,max(M,x)));
            else // Bob
                result = min(result,solveForAlice(piles,1,i+x,max(M,x)));
        } 

        return dp[player][i][M]=result;

    }

    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        n=piles.size();
        return solveForAlice(piles,1,0,1);
    }
};