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
                if(dir==0) r=mid-1;
                else l=mid+1;
            }
        }
        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int first=binarySearch(nums,target,l,r,0);
        int last=binarySearch(nums,target,l,r,1);

        return {first,last};
    }
};