class Solution {
public:
    int minLights(vector<int>& lights) {
        int n=lights.size(), ans=0;
        vector<int> track(n,0);

        for(int i=0;i<n;i++){
            if(lights[i]>0){
                int l=max(0,i-lights[i]);
                int r=min(n-1,i+lights[i]);

                track[l]++;
                if(r+1<n) track[r+1]--;
            }
        }

        for(int i=1;i<n;i++) track[i]+=track[i-1];

        for(int i=0;i<n;i++){
            if(track[i]==0){
                ans++;

                track[i]=1;
                if(i+1<n) track[i+1]=1;
                if(i+2<n) track[i+2]=1;
            }
        }

        return ans;
    }
};