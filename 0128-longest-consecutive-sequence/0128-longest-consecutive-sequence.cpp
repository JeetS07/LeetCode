class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int ans=0;
        for(int i:nums) s.insert(i);
        for(int i:s){
            int count=0;
            if(s.find(i-1)==s.end()) while(s.find(i)!=s.end()){
                i++;
                count++;
            }
            ans=max(ans,count); 
        }
        return ans;
    }
};