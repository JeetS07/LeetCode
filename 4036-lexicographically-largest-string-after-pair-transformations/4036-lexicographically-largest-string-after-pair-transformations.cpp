class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans;

        for(int i:nums){
            string temp="";
            char c='a'; 
            
            while(i>0 && c<'z'){
                if(i%2!=0) temp=c+temp;
                
                i/=2;
                c++;
            }

            while(i>0){
                temp='z'+temp;
                i--;
            }
            
            ans.push_back(temp);
        }

        return ans;
    }
};