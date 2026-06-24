class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last_index;
        vector<int> ans;
        int size=0, end=0;
        for(int i=0;i<s.size();i++) last_index[s[i]]=i; // finding last index of characters

        for(int i=0;i<s.size();i++){
            size++; // size of current partition
            if(last_index[s[i]]>end) end=last_index[s[i]]; // update end if a char has higher last index
            if(i==end){ // all elements belong only to this partition since end the max of rightmost appearing char of this partition
                ans.push_back(size);
                size=0; // reseting size for new partition
            }
        }

        return ans;
    }
};

// O(n) O(1)(since map size at max is 26 -> constant)
// we are pre calculating rightmost index of each letter
// then we start traversing and size and end of current partition, which is max of rightmose index of chars till now
// when i meets end, we found 1 partition