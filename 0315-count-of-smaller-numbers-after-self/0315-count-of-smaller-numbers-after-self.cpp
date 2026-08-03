class Solution {
public:
    int n;
    vector<int> bit;

    void update(int val, int id){
        while(id<=n){
            bit[id]+=val;
            id+=(id & -id);
        }
    }

    int query(int id){
        int ans=0;
        while(id>0){
            ans+=bit[id];
            id-=(id & -id);
        }
        return ans;
    }

    vector<int> countSmaller(vector<int>& nums) {
        n=nums.size();
        bit = vector<int>(n+1,0);

        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({nums[i],i});

        sort(v.begin(),v.end());

        vector<int> ans(n);
        for(auto [element,i]:v){
            update(1,i+1);
            ans[i]=query(n)-query(i+1);
        }   

        return ans;   
    }
};

// Fenwick Tree
// O(nlogn) O(n)
// we are first sorting the array by preserving the indexes
// now we keep bit array with 0, and starting from smallest element,
// we keep placing 1 on that index and find the ranged sum from that
// index to right, that gives the count of smaller element to the right
// of that index