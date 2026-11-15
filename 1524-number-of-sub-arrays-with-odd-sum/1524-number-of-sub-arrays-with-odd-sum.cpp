class Solution {
public:
    int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size(), ans=0, sum=0, odd=0, even=1;

        for(int i=0;i<n;i++){
            sum+=arr[i];

            if(sum%2==0){
                ans=(ans+odd)%MOD;
                even++;
            }
            else{
                ans=(ans+even)%MOD;
                odd++;
            }
        }

        return ans;
    }
};