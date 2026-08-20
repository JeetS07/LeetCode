class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> a1, a2;
        a1.push_back(nums[0]);
        a2.push_back(nums[1]);

        int x=0, y=0;
        for(int i=2;i<nums.size();i++){
            if(a1[x]>a2[y]){
                a1.push_back(nums[i]);
                x++;
            }
            else{
                a2.push_back(nums[i]);
                y++;
            }
        }

        for(int i:a2){
            a1.push_back(i);
        }

        return a1;
    }
};