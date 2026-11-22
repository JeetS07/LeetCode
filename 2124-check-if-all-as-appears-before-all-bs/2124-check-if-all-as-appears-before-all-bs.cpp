class Solution {
public:
    bool checkString(string s) {
        int n=s.size(), a=n, b=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                b=i;
                break;
            } 
        }

        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                a=i;
                break;
            } 
        }

        return ((a==n-1 && b==-1) || (b==0 && a==n) || (a<b));
    }
};