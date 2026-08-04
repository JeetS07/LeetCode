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