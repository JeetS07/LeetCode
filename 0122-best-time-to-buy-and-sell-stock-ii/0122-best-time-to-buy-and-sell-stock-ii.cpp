class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]) ans+=prices[i]-prices[i-1];
        }
        return ans;
    }
};

// O(n) O(1)
// Greedy
// we try to add up all profits on daily basis if possible