class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        queue<int> q;
        for(int i=1;i<9;i++) q.push(i);

        while(q.empty()==false){
            int n=q.front();
            q.pop();

            if(n>high) continue;
            
            if(low<=n && n<=high) ans.push_back(n);

            int one=n%10;
            if(one<9) q.push(n*10 + (one+1));
        }

        return ans;
    }
};