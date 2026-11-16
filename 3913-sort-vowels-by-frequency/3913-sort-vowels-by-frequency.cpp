class Solution {
public:
    bool isV(char &c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }

    string sortVowels(string s) {
        unordered_map<char,int> m1,m2;
        string v="";
        for(int i=0;i<s.size();i++){
            if(isV(s[i])){
                v+=s[i];
                m1[s[i]]++;
                if(m2.count(s[i])==0) m2[s[i]]=i;
            }
        }

        sort(v.begin(),v.end(),[&](char a, char b){
            return (m1[a]==m1[b]) ? m2[a]<m2[b] : m1[a]>m1[b];
        });

        int j=0;
        for(char &i:s){
            if(isV(i)){
                i=v[j];
                j++;
            }
        }

        return s;
    }
};