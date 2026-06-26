class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int curr=0;
        mp[curr]=1;

        long long validLeft=0, ans=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                validLeft+=mp[curr];
                curr++;
            }
            else{
                curr--;
                validLeft-=mp[curr];
            }
            mp[curr]+=1;
            ans+=validLeft;
        }
        
        return ans;
    }
};