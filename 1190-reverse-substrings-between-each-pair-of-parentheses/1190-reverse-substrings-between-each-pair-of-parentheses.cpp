class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openBracket;
        string result;

        for (char curr:s) {
            if(curr == '(') openBracket.push(result.size());
            else if(curr == ')') {
                int start = openBracket.top();
                openBracket.pop();
                reverse(result.begin()+start,result.end());
            } 
            else result += curr;
        }
        return result;
    }
};
