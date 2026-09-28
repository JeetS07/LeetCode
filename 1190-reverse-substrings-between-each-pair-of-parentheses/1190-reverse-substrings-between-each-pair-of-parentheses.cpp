class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int> openBracket;
        vector<int> door(n);

        // Pairing parentheses
        for(int i=0;i<n;i++) {
            if(s[i] == '(') openBracket.push(i);
            else if(s[i] == ')'){
                int j = openBracket.top();
                openBracket.pop();
                door[i] = j;
                door[j] = i;
            }
        }

        // Build the result string
        string result;
        int direction = 1; // Left to Right
        for(int i=0;i<n;i+=direction){
            if(s[i] == '(' || s[i] == ')'){
                i = door[i];
                direction = -direction; // reversing direction
            } 
            else result += s[i];
        }
        return result;
    }
};

// Wormhole Teleportation
// O(n) 