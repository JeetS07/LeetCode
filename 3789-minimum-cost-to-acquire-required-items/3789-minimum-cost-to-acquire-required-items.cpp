class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        int mn=min(need1,need2);

        ans=1LL*min(cost1+cost2,costBoth)*mn;
        if(mn==need1) ans+=1LL*min(costBoth,cost2)*(need2-need1);
        if(mn==need2) ans+=1LL*min(costBoth,cost1)*(need1-need2);

        return ans;
    }
};