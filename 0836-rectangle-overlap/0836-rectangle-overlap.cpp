class Solution {
public:
    bool isRectangleOverlap(vector<int>& r1, vector<int>& r2) {
        // no overlap, if straight line
        if(r1[0]==r1[2] or r1[1]==r1[3] or r2[0]==r2[2] or r2[1]==r2[3]) return false;

        // no overlap, if r1 is totally left, bottom, right or top of r2
        if(r1[2]<=r2[0] or r1[3]<=r2[1] or r1[0]>=r2[2] or r1[1]>=r2[3])
            return false;
        else 
            return true;
    }
};
