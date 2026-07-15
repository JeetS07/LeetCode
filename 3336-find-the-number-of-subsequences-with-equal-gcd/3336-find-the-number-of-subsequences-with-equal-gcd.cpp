class Solution {
public:
    int dp[201][201][201];
    int MOD = 1e9 + 7;
    int recursion(vector<int>& nums, int i, int first, int second){ // i=current element, first = gcd of 1st seq, second = gcd of 2nd seq
        if(i==nums.size()){
            bool noSeqEmpty = (first!=0 && second!=0); // no sequence is empty (gcd of empty seq is zero)
            bool isEqualGcd = (first==second); // both gcd are equal

            return (noSeqEmpty && isEqualGcd) ? 1 : 0; // if both condition is try, we have a solution
        }
        if(dp[i][first][second]!=-1) return dp[i][first][second];

        int skip = recursion(nums,i+1,first,second); // not taking current element
        int take1 = recursion(nums,i+1,__gcd(first,nums[i]),second); // taking current element in seq1
        int take2 = recursion(nums,i+1,first,__gcd(second,nums[i])); // // taking current element in seq2

        return dp[i][first][second] = (0LL + skip + take1 + take2) % MOD; // return sum of ans from all path
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return recursion(nums,0,0,0);
    }
};

// Recursion + Memoisation
// we go through all elements, for each we have 3 choices:
// dont take current, take current in 1st seq, take current in 2nd seq
// and simultaneously we calculate gcd on the fly using __gcd stl
// finally we return sum of all path