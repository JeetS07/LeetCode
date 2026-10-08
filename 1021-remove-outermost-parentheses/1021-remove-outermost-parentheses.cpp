class Solution {
public:
    string removeOuterParentheses(string s) {
        int c=0;
        string ans;
        string temp="";

        for(int i:s){
            temp+=i;

            if(i=='(') c++;
            else c--;

            if(c==0){
                ans+= temp.substr(1,temp.size()-2);
                temp="";
            }
        }

        return ans;
    }
};