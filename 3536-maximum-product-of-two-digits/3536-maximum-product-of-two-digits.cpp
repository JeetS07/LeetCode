class Solution {
public:
    int maxProduct(int n) {
        priority_queue<int> h;

        while(n>0){
            int r=n%10;
            h.push(r);
            n/=10;
        }

        int x=h.top();
        h.pop();

        int y=h.top();
        h.pop();

        return x*y;
    }
};