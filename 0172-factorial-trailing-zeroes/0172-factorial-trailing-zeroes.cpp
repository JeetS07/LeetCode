class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
        for(int i=5;i<=n;i*=5){
            ans+=n/i;
        }
        return ans;
    }
};

// O(log_5(n)) O(1)
// all 5 and 2 contribute to a zero in result, since 5 is less available than 2 we count
// no. of 5 in n (i.e. ans+=n/i;). But we also need to count the no. of 25(contributing 2 5s), 125(3 5s i.e. 5x5x5),... so on
// so we do i*=5, so i=5,25,125,... and count 5s contributed by these respectively