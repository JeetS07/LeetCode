class Solution {
public:
    int getLength(vector<int>& nums) {
        int n=nums.size(), ans=1;
        for(int i=0;i<n;i++){
            unordered_map<int,int> m;
            vector<int> bucket(n+1,0);
            int maxF=0, countMaxF=0;

            for(int j=i;j<n;j++){
                if(m[nums[j]]) bucket[m[nums[j]]]--;

                m[nums[j]]++;
                bucket[m[nums[j]]]++;
                int distinct=m.size();

                if(m[nums[j]]>maxF){
                    maxF=m[nums[j]];
                    countMaxF=1;
                }
                else if(m[nums[j]]==maxF) countMaxF++;

                if(distinct==1) ans=max(ans,j-i+1);
                else if(maxF%2==0 && distinct-countMaxF==bucket[maxF/2]) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};