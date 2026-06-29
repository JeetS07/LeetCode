class Solution {
public:
    int totalFruit(vector<int>& f) {
        int n=f.size();
        if(n<3) return n; 
        unordered_map<int,int> mp;
        int ans=0, i=0, j=0;
        while(j<n){
            mp[f[j]]++; // inserting element in bucket
            while(mp.size()>2){ // if 3 distinct found removing element from back until only 2 distinct
                mp[f[i]]--;
                if(mp[f[i]]==0) mp.erase(f[i]);
                i++;
            }
            ans=max(ans,j-i+1); // storing max of current valid subarray with 2 distinct
            j++;
        }
        return ans;
    }
};

// Largest subarray length with 2 distinct elements