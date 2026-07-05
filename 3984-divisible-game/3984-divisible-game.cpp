class Solution {
public:
    int MOD=1000000007;
    
    long long kadane(vector<int>&a){
        long long sum=0, maxi=a[0];
        for(long long i:a){
            sum+=i;
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        return maxi;
    }

    vector<int> divisors(int x){
        vector<int> d;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                d.push_back(i);
                if(i*i!=x) d.push_back(x/i);
            }
        }
        return d;
    }

    int divisibleGame(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> s;
        for(int i:nums){
            auto d=divisors(i);
            for(int j:d) if(j>1) s.insert(j);
        }

        long long bestScore=LLONG_MIN;
        int bestK=2;
        bool found=false;
        vector<int> arr(n);

        for(int k:s){
            found=true;

            for(int i=0;i<n;i++){
                if(nums[i]%k==0) arr[i]=nums[i];
                else arr[i]=-nums[i];
            }
            
            long long score=kadane(arr);
            if(score>bestScore || (score==bestScore && k<bestK)){
                bestK=k;
                bestScore=score;
            }
        }

        if(found==false){
            bestScore=-1;
            bestK=2;
        }

        long long ans=((bestScore%MOD)*bestK);
        return (ans+MOD)%MOD;
    }
};