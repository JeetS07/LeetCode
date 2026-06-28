class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        arr[0]=1;
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]>1) arr[i]=arr[i-1]+1;
        }
        return arr[arr.size()-1];
    }
};

// O(n) O(1) Greedy
// sorting(operation 2) and setting 1st element to 1(operation 1)
// starting from 2nd, lowering each element to arr[i-1]+1 if greater than that(operation 1)