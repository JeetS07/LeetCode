class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size(), i=0, j=0, currSum=0, bestMinL=INT_MAX, ans=INT_MAX;
        vector<int> bestMinLTillIdx(n,INT_MAX);

        while(j<n){
            currSum+=arr[j];

            while(i<j && currSum>target){
                currSum-=arr[i];
                i++;
            }

            if(currSum==target){
                int l=j-i+1;
                if(i>0 && bestMinLTillIdx[i-1]!=INT_MAX) ans=min(ans,l+bestMinLTillIdx[i-1]);

                bestMinL=min(bestMinL,l);
            }

            bestMinLTillIdx[j]=bestMinL;
            
            j++;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};