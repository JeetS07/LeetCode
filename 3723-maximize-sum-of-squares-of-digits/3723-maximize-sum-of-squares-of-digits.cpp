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