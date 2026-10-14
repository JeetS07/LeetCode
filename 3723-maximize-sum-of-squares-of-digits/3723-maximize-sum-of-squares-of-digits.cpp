class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > num*9) return "";

        int nines=sum/9;
        int remain=sum%9;

        string ans(nines,'9');
        if(remain>0) ans+=(remain+'0');
        ans+=(string(num-ans.size(),'0'));

        return ans;
    }
};

// O(n) O(1)
// we are trying to put maximum no. of 9s, then put
//  the remaining digit, and fill rest space with 0
// that gives the largest answer