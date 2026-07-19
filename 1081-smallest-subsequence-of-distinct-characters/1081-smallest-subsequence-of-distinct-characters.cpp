class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26,0);
        vector<bool> seen(26,0);
        stack<char> st; // maintaining answer
        string ans="";

        for(int i=0;i<s.size();i++) last[s[i]-'a']=i; // storing last appearance of each char
        
        for(int i=0;i<s.size();i++){
            int curr=s[i]-'a';
            if(seen[curr]) continue; // ignoring if char already seen

            while(st.size()>0 && st.top()>s[i] && i<last[st.top()-'a']){ // popping if last seen element is greater than current and it appears later in s 
                seen[st.top()-'a']=0; // reseting seen for last seen element
                st.pop(); 
            }

            st.push(s[i]); // including curr char in ans
            seen[curr]=1; // maintaining seen
        }
        
        while(st.size()>0){ // forming ans string from char in stack
            ans=st.top()+ans;
            st.pop();
        }

        return ans;
    }
};

// O(n), O(1)
// Stack
// first we are finding the last occurance of each char,
// Now for each char, 1.ignore if already seen,
//                    2.pop from stack if curr<(last char) and (last char) appears laters in s, we can remove it now
//                      from ans and take last occurance later to achieve lowest Lexicographical order
//                    3.push to stack, mark seen
