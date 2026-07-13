class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        queue<int> q;
        for(int i=1;i<=9;i++) q.push(i); // pushing 1-9 in queue

        while(q.empty()==false){
            int n=q.front();
            q.pop();

            if(n>high) continue;
            
            if(low<=n && n<=high) ans.push_back(n);

            int one=n%10;
            if(one<9) q.push(n*10 + (one+1)); // if n is 123, we are pushing 1234 to queue
        }

        return ans;
    }
};

// queue
// we first push 1,2,3,...9 in queue, now pop each number and add 12,23,34,...89 respectively
// again 123,234,345,... for each no. we append to ans if its in range. If no. exceeds high
// we stop adding to queue and pop the remaining n > high 