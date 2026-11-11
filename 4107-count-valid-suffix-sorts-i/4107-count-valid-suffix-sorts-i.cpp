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
            if(flag && nums[i]==target[i]) p++; // finding p; length of prefix where nums[i]==target[i]
        }
        if(m1!=m2) return 0; // if freq of target and num are not equal, no possible ans

        int q=n-1;
        for(int i=n-1;i>0;i--){
            if(target[i]<=target[i-1]) q=i-1; // finding q; start of suffix where target is decreasing
            else break;
        }

        return max(0,min(p,n-1)-q+1);
    }
};

// O(n) O(n)
// For an index i to work:
//  Everything before i must already match target. Therefore, i <= p.
//  The suffix starting at i must already be non-increasing in target. Therefore, i >= q.
// So ans is the count of i in range q to p.