class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n=nums.size(), p=0;
        bool flag=1;
        unordered_map<int,int> m1,m2;
        for(int i=0;i<n;i++){
            m1[nums[i]]++;
            m2[target[i]]++;

            if(nums[i]!=target[i]) flag=0;
            if(flag && nums[i]==target[i]) p++;
        }
        if(m1!=m2) return 0;

        int q=n-1;
        for(int i=n-1;i>0;i--){
            if(target[i]<=target[i-1]) q=i-1;
            else break;
        }

        return max(0,min(p,n-1)-q+1);
    }
};
