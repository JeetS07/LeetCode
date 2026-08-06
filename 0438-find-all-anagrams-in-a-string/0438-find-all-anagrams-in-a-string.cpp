class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1=s.size(), n2=p.size();
        vector<int> ans;
        if(n2>n1) return ans;

        vector<int> freq1(26,0); //s freq
        vector<int> freq2(26,0); //p freq

        for(char i:p) freq2[i-'a']++;

        int i=0, j=0, size=0;

        while(j<n1){
            if(size==n2){
                if(freq1==freq2) ans.push_back(i);
                freq1[s[i]-'a']--;
                i++;
                size--;
            }
            freq1[s[j]-'a']++;
            j++;
            size++;
        }

        if(size==n2 && freq1==freq2) ans.push_back(i);

        return ans;
    }
};