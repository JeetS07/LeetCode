class Solution {
public:
    using ll=long long;
    ll countCommas(long long n) {
        ll n1=n, c=0;
        while(n1>0){
            c++;
            n1/=10;
        }

        vector<pair<int,int>> v={{1,3},{4,6},{7,9},{10,12},{13,15},{16,18}};
        ll ans=0;
        for(int i=0;i<v.size();i++){
            if(c<v[i].first) break;
            if(c>v[i].second){
                string start='1'+string(v[i].first-1,'0');
                string end=string(v[i].second,'9');
                ans+=(1LL*i*(stoll(end)-stoll(start)+1));
            }
            if(v[i].first<=c && c<=v[i].second){
                string start='1'+string(v[i].first-1,'0');
                ans+=(1LL*i*(n-stoll(start)+1));
            }
        }

        return ans;
    }
};