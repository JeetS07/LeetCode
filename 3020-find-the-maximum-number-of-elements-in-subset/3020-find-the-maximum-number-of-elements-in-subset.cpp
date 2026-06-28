class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> freq;
        int ans=0;
        for(int i:nums) freq[i]++;
        
        if(freq[1]%2==0) ans=freq[1]-1;
        else ans=freq[1];

        for(auto i:freq){
            if(i.first==1) continue;

            long long curr= i.first;
            int len=0;

            while(freq.count(curr) and freq[curr]>1){
                len+=2;
                curr=curr*curr;
            }

            if(freq.count(curr)==1) len+=1;
            else len-=1;

            ans=max(ans,len);
            
        }

        return ans;
    }
};