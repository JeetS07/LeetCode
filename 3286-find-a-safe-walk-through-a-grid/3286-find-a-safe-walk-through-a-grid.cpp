class Solution {
public:
    vector<vector<int>> direction={{0,1},{0,-1},{1,0},{-1,0}};

    bool isValid(int &x, int &y, int &m, int &n){
        return (x>=0 && x<m && y>=0 && y<n);
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> result(m,vector<int> (n,INT_MAX));
        deque<pair<int,int>> dq;

        result[0][0]=grid[0][0];
        dq.push_front({0,0});

        while(!dq.empty()){
            int x=dq.front().first;
            int y=dq.front().second;

            dq.pop_front();

            for(auto &dir:direction){
                int nx=dir[0]+x;
                int ny=dir[1]+y;

                if(!isValid(nx,ny,m,n)) continue; 

                if(result[x][y]+grid[nx][ny]<result[nx][ny]){
                    result[nx][ny] = result[x][y]+grid[nx][ny];

                    if(grid[nx][ny]==0) dq.push_front({nx,ny});
                    else dq.push_back({nx,ny});
                }
            }
        }

        int x=result[m-1][n-1];
        return (health-x)>=1;
    }
};