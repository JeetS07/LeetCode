class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i:nums) m[i]++;

        if(k==1 || k==n){

            int allMax=-1, uniqueMax=-1;
            for(int i:nums){
                allMax=max(allMax,i);
                if(m[i]==1) uniqueMax=max(uniqueMax,i);
            }

            if(k==n) return allMax;
            else if(k==1 && uniqueMax!=-1) return uniqueMax;
            else return -1;
        }
        else{
            int first=nums[0];
            int last=nums[n-1];

            if(m[first]>1 && m[last]>1) return -1;
            else if(m[first]>1) return last;
            else if(m[last]>1) return first;
            else return max(first,last);
        }
    }
};

// there are 3 diff cases:
// k=1, return max unique element
// k=n, return max of nums
// 1<k<n, only first and last element of nums are eligible 
// if both are unique return max of them else return the unique one