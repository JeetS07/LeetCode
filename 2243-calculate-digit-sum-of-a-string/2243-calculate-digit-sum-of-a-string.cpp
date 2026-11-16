class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k){
            string s2="";
            int n=s.size();

            for(int i=0;i<n;i+=k){
                string curr=(i+k-1<n) ? s.substr(i,k) : s.substr(i);

                int sum=0;
                for(char j:curr) sum+=(j-'0');
                s2+=to_string(sum);
            }

            s=s2;
        }

        return s;
    }
};