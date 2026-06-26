class Solution {
public:
    double dfs(double x, long long n){
        if(x==0) return 0;
        if(n==0) return 1;

        double res=dfs(x,n/2);
        res*=res;
        return (n%2==0) ? res : x*res;

    }
    double myPow(double x, long long n) {
        double ans=dfs(x,abs(n));
        return (n<0) ? 1/ans : ans;
    }
};