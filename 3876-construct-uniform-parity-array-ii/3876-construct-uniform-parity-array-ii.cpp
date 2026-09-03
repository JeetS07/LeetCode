class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int OddMin=INT_MAX;
        for(int i:nums1) if(i%2!=0) OddMin=min(OddMin,i);

        bool even=1, odd=1;
        // even parity
        for(int i:nums1){
            if(i%2==0) continue;
            if(i<=OddMin){
                even=0;
                break;
            }
        }

        // odd parity
        for(int i:nums1){
            if(i%2!=0) continue;
            if(i<=OddMin){
                odd=0;
                break;
            }
        }

        return (even || odd);
    }
};