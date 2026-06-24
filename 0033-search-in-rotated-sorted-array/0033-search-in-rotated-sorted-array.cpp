class Solution {
public:
    int bs(vector<int>& nums, int target, int l, int r){
        if(l>r) return -1;
        int mid=l+(r-l)/2;
        if(nums[mid]==target) return mid;

        if(nums[l]<=nums[mid]){ // if left half is  sorted
            if(nums[l]<=target && target<=nums[mid]) return bs(nums,target,l,mid-1); // target exists in this half
            else return bs(nums,target,mid+1,r);
        }
        else{ // if right half is sorted
            if(nums[mid]<=target && target<=nums[r]) return bs(nums,target,mid+1,r); // target exist in this half
            else return bs(nums,target,l,mid-1);
        }
        
    }

    int search(vector<int>& nums, int target) {
        return bs(nums,target,0,nums.size()-1);
    }
};

// O(log n) O(1)
// if the array is sorted and rotated, there is one pivot. After we divide array with mid,
// either part has a pivot and the other is totally sorted. In the totally sorted, we can say if target exist by checking boundary elements.
// If not we go for other half