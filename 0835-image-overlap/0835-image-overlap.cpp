class Solution {
public:
    int overlap(vector<vector<int>>& a, vector<vector<int>>& b, int r, int c){
        int n=a.size(), count=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int b_i=i+r;
                int b_j=j+c;

                if(b_i<0 || b_i>=n || b_j<0 || b_j>=n) continue;
                if(a[i][j]==1 && b[b_i][b_j]==1) count++;
            }
        }
        return count;
    }

    int largestOverlap(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n=a.size(), ans=0;
        for(int r=-n+1;r<n;r++){
            for(int c=-n+1;c<n;c++){
                int count=overlap(a,b,r,c);
                ans=max(ans,count);
            }
        }
        return ans;
    }
};