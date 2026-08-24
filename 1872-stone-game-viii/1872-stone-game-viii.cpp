class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> prefix(n);

        prefix[0]=stones[0];
        for(int i=1;i<n;i++) prefix[i]=stones[i]+prefix[i-1];

        vector<int> t(n,0);
        t[n-1]=prefix[n-1];

        for(int i=n-2;i>=1;i--){
            int take = prefix[i] - t[i+1];
            int skip = t[i+1];

            t[i] = max(take,skip);
        }

        return t[1];
    }
};