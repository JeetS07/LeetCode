class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m; // using map to group anagrams
        vector<vector<string>> ans;

        for(string i:strs){
            vector<int> freq(26,0); 
            for(char j:i) freq[j-'a']++; // calculating freq of each string

            string key="";
            for(int j:freq) key+=to_string(j)+'#'; // forming string key

            m[key].push_back(i); // anagrams grouped against same freq key
        }

        for(auto i:m) ans.push_back(i.second);
        return ans;
    }
};

// O(m*n) O(m*n)
// for every string, making a frequency array and using it as a key in map to group anagrams
// as all anagrams will have same req array. Since we cannot use vector<int> as key in map,
// so converting it to a string eg. for freq=[1,0,0,3,...] key becomes "1#0#0#3#..." 