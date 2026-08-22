class Solution {
public:
    bool checkDivisibility(int n) {
        int x=n, s=0, p=1;

        while(x>0){
            int r=x%10;
            s+=r;
            p*=r;
            x/=10;
        }

        return n%(s+p)==0;
    }
};