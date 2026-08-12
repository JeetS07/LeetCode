class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int i=0,j=0,ans=0;

        for(j=0;j<nums.size();j++){
            m[nums[j]]++;
            if(m[nums[j]]<=k) ans=max(ans,j-i+1);
            else{
                while(m[nums[j]]>k){
                    m[nums[i]]--;
                    i++;
                }
            }
        }

        return ans;
    }
};