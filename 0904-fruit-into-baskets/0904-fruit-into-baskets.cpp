class Solution {
public:
    int totalFruit(vector<int>& f) {
        int n=f.size();
        if(n<3) return n; 
        unordered_map<int,int> mp;
        int ans=0, i=0, j=0;
        while(j<n){
            mp[f[j]]++;
            while(mp.size()>2){
                mp[f[i]]--;
                if(mp[f[i]]==0) mp.erase(f[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};