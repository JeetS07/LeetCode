class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size(),i=0,j=m*n-1,mid,curr;
        while(i<=j){
            mid=i+(j-i)/2;
            curr=matrix[mid/n][mid%n];
            if(curr==target) return true;
            else if(target<curr) j=mid-1;
            else i=mid+1;
        }
        return false;
    }
};

// O(log mn) O(1) Binary Search
// treating matrix as a linear array of size m*n
// we map curr in linear array to matrix by matrix[mid/n][mid%n];