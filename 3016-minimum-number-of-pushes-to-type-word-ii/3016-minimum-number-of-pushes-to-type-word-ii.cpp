class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char,int> mp;
        for(char i:word) mp[i]++;

        vector<int> v;
        for(auto i:mp) v.push_back(i.second);

        sort(v.begin(),v.end(),greater<>());

        int ans=0, c=0;
        for(int i:v){
            c++;
            if(c<=8) ans+=(1*i);
            else if(c<=16) ans+=(2*i);
            else if(c<=24) ans+=(3*i);
            else ans+=(4*i);
        }

        return ans;
    }
};