class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> curr(n,INT_MAX);
        unordered_map<int,vector<pair<int,int>>> adj;
        vector<bool> maxedOut(n,0);
        curr[k-1]=0;

        for(auto i:times) adj[i[0]].push_back({i[1],i[2]});

        for(int i=0;i<n;i++){
            int f=-1;
            for(int j=0;j<n;j++){
                if((f==-1 or curr[j]<curr[f]) && !maxedOut[j]) f=j;
            }

            if(f==-1 or curr[f]==INT_MAX) break;
            maxedOut[f]=true;

            for(auto j:adj[f+1]){
                int node=j.first;
                if(!maxedOut[node-1]){
                    curr[node-1]=min(curr[node-1],curr[f]+j.second);
                }
            }
        }

        int ans=0;
        for(int i:curr){
            if(i==INT_MAX) return -1;
            ans=max(ans,i);
        }

        return ans;
    }
};