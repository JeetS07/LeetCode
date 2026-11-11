class Solution {
public:
    void solve(int curr, int &n, vector<int> &ans){
        if(curr>n) return;

        ans.push_back(curr);
        for(int i=0;i<=9;i++){
            int newCurr=(curr*10)+i;
            if(newCurr>n) return;

            solve(newCurr,n,ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            solve(i,n,ans);
        }

        return ans;
    }
};

// Recursion
// O(n) O(no. of digits in n)
// starting with 1, appending a digit and checking if it is less than n