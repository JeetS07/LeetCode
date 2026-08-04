class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> t_map;
        for(char i:t) t_map[i]++;

        int i=0,j,c=t.size(),start=0,length=INT_MAX;
        for(j=0;j<s.size();j++){
            if(t_map[s[j]]>0) c--;
            t_map[s[j]]--;

            while(c==0){
                if(j-i+1<length){
                    length=j-i+1;
                    start=i;
                }
                t_map[s[i]]++;
                if(t_map[s[i]]>0) c++;
                i++;
            }
        }

        return (length==INT_MAX) ? "" : s.substr(start,length);
    }
};

// sliding window
// first we store count of elements in c, now we keep decrementing freq count of jth element and j moves ahead,
// also we decrease c if jth element is from t, now when we hit c==0 means all t elements are in s, at this point
// we try to minimize the answer by removing ith element from window while c==0, parellely we store the min length 
// and start of min window so we can reconstruct the ans with substr