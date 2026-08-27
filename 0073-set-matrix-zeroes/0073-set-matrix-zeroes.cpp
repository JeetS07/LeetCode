class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[0].size();
        bool row1=0, col1=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    if(i==0) row1=1;
                    if(j==0) col1=1;

                    matrix[0][j]=0;
                    matrix[i][0]=0;
                } 
            }
        }

        for(int i=1;i<m;i++){
            if(matrix[i][0]==0){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
        }

        for(int j=1;j<n;j++){
            if(matrix[0][j]==0){
                for(int i=0;i<m;i++){
                    matrix[i][j]=0;
                }
            }
        }

        if(row1==1) for(int j=0;j<n;j++) matrix[0][j]=0;
        if(col1==1) for(int i=0;i<m;i++) matrix[i][0]=0;
    }
};