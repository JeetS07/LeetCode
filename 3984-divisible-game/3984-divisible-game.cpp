class Solution {
public:
    int MOD=1000000007;
    
    long long kadane(vector<int>&a){ // return the maximum subarray sum 
        long long sum=0, maxi=a[0];
        for(long long i:a){
            sum+=i;
            maxi=max(maxi,sum);
            if(sum<0) sum=0;
        }
        return maxi;
    }

    vector<int> divisors(int x){ // find all divisors for each element in nums
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
        for(int i:nums){ // store unique divisors(potential k)
            auto d=divisors(i);
            for(int j:d) if(j>1) s.insert(j);
        }

        long long bestScore=LLONG_MIN; // store highest score
        int bestK=2; // store min k with highest score
        bool found=false;
        vector<int> arr(n);

        for(int k:s){ // checking scores for all k
            found=true;

            for(int i=0;i<n;i++){ // creating arr array
                if(nums[i]%k==0) arr[i]=nums[i];
                else arr[i]=-nums[i];
            }
            
            long long score=kadane(arr); // finding Alice-Bob score for best [l,r]
            if(score>bestScore || (score==bestScore && k<bestK)){
                bestK=k;
                bestScore=score;
            }
        }

        if(found==false){ // if no k found > 1 ..i.e. all element 1
            bestScore=-1;
            bestK=2;
        }

        long long ans=((bestScore%MOD + MOD)*bestK); // using +MOD to map both negative and positive no. to range:[0,MOD], as in example 3
        return ans%MOD;
    }
};

// we generate all possible k for all elements, then for each k
// we create arr that stores +ve nums[i] if nums[i] divisible by k else -ve nums[i]
// eg. {2,3,6}, for k=2, arr={2,-3,6}, to maximize score diff Alice would 
// have chosen {l,r}={2,2} i.e. 6 which is the max sum subarray of arr
// now on this arr, we find the max sum subarray using kadanes algo that gives
// us the score of the best choice of l and r, so we dont need to explicitly choose l and r