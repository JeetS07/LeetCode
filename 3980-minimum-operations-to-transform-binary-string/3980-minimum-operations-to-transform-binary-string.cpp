class Solution {
public:
    int minOperations(string s1, string s2) {
        int ans=0;
        if(s1.size()==1 and s1[0]!=s2[0] and s1[0]=='1') return -1;
        for(int i=0;i<s1.size();i++){
            if(s1[i]==s2[i]) continue;
            else{
                if(s1[i]=='0'){
                    ans++;
                    s1[i]='1';
                }
                else{
                    if(i+1<s1.size() && s1[i+1]=='1'){
                        ans++;
                        s1[i]=s1[i+1]='0';
                    }
                    else if(i+1<s1.size() && s1[i+1]=='0'){
                        ans+=2;
                        s1[i]=s1[i+1]='0';
                    }
                    else ans+=2;
                }
            }
        }
        return ans;
    }
};