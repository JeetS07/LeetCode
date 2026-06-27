class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0, r=0, count;
        while(r<nums.size()){
            count=1;
            while(r+1<nums.size() && nums[r]==nums[r+1]){
                r++;
                count++;
            }
            for(int i=0;i<min(2,count);i++){
                nums[l]=nums[r];
                l++;
            }
            r++;
        }
        return l;
    }
};

// O(n) O(1)
// Two Pointers
// for a streak, keeping l,r at beginning then moving r to end of streak. Simultaneously calculating count
// now write nums[r] to nums[l] min(2,count)...i.e min(2 or 1) and shifting l after write
// then moving r to s=beginning to next streak