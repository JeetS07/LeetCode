class Solution {
public:
    typedef long long ll;
    typedef pair<ll,int> P;

    bool check(int mid, int n, ll k, unordered_map<int,vector<vector<int>>> &adj){ // Dijkastra's Algorithm
        priority_queue<P,vector<P>,greater<P>>pq; // using minheap to find min dist node
        vector<ll> result(n,LLONG_MAX); // tracking min dist till now

        result[0]=0;
        pq.push({0,0});

        while(pq.empty()==false){
            ll d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(d>k) return false; // current path already exceeds k
            if(node==n-1) return true; // reached target

            if(result[node]<d) continue; // already smaller path exists

            for(auto i:adj[node]){ // taking all adj nodes
                int adjNode=i[0];
                int edgeCost=i[1];

                if(edgeCost<mid) continue; // mid should be the smallest edge of chosen path

                if(d+edgeCost<result[adjNode]){ // smaller path exists
                    result[adjNode]=d+edgeCost;
                    pq.push({d+edgeCost,adjNode});
                }
            }

        }

        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n=online.size();
        unordered_map<int,vector<vector<int>>> adj;
        int l=INT_MAX, r=0;

        for(auto i:edges){
            int u=i[0], v=i[1], cost=i[2];
            if(online[u]==0|| online[v]==0) continue;
            adj[u].push_back({v,cost});

            l=min(l,cost); // minimum possible ans
            r=max(r,cost); // maximum possible ans
        }

        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(check(mid,n,k,adj)){ // if current path is valid moving towards larger answer
                ans=mid;
                l=mid+1;
            } 
            else r=mid-1;
        }
        return ans;
    }
};

// Binary Search + Dijkastra
// ans is one the edges, so we apply binary search on min edge to max edge and check
// if current mid is a edge and lies in a valid path, if so we move towards larger mid