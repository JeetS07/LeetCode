class Solution {
public:
    int smallestNumber(int n, int t) {
        while(true){
            int p=1, n1=n;
            while(n1>0){
                int r=n1%10;
                p*=r;
                n1/=10;
            }
            if(p%t==0) return n;
            n++;
        }
    }
};