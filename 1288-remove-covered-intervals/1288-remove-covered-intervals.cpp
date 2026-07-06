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