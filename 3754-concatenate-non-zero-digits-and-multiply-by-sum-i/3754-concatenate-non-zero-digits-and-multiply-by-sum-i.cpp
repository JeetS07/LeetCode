class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0, x=0, c=0;
        while(n>0){
            int r=n%10;
            if(r!=0) x=(r*pow(10,c++))+x;
            sum+=r;
            n/=10;
        }
        return x*sum;
    }
};