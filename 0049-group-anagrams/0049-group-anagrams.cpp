class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>> ans;

        for(string i:strs){
            vector<int> freq(26,0);
            for(char j:i) freq[j-'a']++;

            string key="";
            for(int j:freq) key+=to_string(j)+'#';

            m[key].push_back(i);
        }

        for(auto i:m) ans.push_back(i.second);
        return ans;
    }
};