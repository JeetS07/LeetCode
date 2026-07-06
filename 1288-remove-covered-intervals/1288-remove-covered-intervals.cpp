class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> ans;

        sort(intervals.begin(),intervals.end(),[](vector<int> &a,vector<int> &b){
            if(a[0]==b[0]) return a[1]>b[1];
            else return a[0]<b[0];
        });
        
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][1]>ans.back()[1]) ans.push_back(intervals[i]);
        }
        return ans.size();
    }
};

// O(nlogn) O(n)
// sorting in increasing base on intervals[i][0], if it is equal then sort in decreasing for intervals[i][1];
// after sorting we will get our first valid interval at ans[0],then start comparing towards right
// intervals[i][0] is already in order, we just need to check for intervals[i][1]<=ans.back()[1] then its
// covered otherwise push it to ans as a valid interval