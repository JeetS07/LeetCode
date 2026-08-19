class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> m;
        for(auto i:reservedSeats) m[i[0]].push_back(i[1]);

        int ans = (n-m.size())*2;
        for(auto i:m){
            bool left=1, mid=1, right=1;

            for(int j:i.second){
                if(2<=j && j<=5) left=0;
                if(4<=j && j<=7) mid=0;
                if(6<=j && j<=9) right=0;
            }
            
            if(left && right) ans+=2;
            else if(left || right || mid) ans+=1;
        }

        return ans;
    }
};