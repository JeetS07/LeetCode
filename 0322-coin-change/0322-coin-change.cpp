class Solution {
public:
    int rec(vector<int>& coins, int amount, vector<int> &dp){
        if(amount==0) return 0; // current denomination reached amount
        if(amount<0) return INT_MAX; // current denomination doesnt reach amount
        if(dp[amount]!=-1) return dp[amount];
        
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans=rec(coins,amount-coins[i],dp); // finding all other denomination recursively
            if(ans!=INT_MAX) mini=min(mini,ans+1); // storing the minimum
        }

        return dp[amount] = mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans=rec(coins,amount,dp);
        return (ans==INT_MAX) ? -1 : ans;
    }
};

// Recursion+DP Memoisation
// Greedy is not possible as always choosing the the max coins first may not be able to make amount==0
// at each coin we deduct the current coin value from amount and send recursive calls for all other coins
// parellely we track the no. of count through return value, and return the minimumm coins used
// if we cant reach amount perfectly(i.e amount<0) then we return INT_MAX in base case as INT_MAX wont 
// interfere with out minimum coin calculation, so we cannot return -1 here in place of INT_MAX 