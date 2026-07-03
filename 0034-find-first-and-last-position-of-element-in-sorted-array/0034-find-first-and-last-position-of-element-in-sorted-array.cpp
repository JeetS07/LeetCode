class Solution {
public:
    int binarySearch(vector<int>& nums, int &target, int l, int r, int dir){
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(target>nums[mid]) l=mid+1;
            else if(target<nums[mid]) r=mid-1;
            else{
                ans=mid;
                if(dir==0) r=mid-1; // going more left for first occurance
                else l=mid+1; // going more right for last occurance
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        
        // dir represents direction
        // dir=0 means we search leftbiased for first occurance
        // dir=1 means we search rightbiased for last occurance 
        int first=binarySearch(nums,target,l,r,0);
        int last=binarySearch(nums,target,l,r,1);

        return {first,last};
    }
};

// O(logn) O(1)
// we perform bs 2 time, one time for first next for last
// for each, when we find the result we go more left or more right depending on dir(direction)