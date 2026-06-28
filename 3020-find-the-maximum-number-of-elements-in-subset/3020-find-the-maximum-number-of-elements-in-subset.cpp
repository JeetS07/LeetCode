class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> freq;
        int ans=0;
        for(int i:nums) freq[i]++; // finding frequency
        
        if(freq[1]%2==0) ans=freq[1]-1; // handling edge case of 1
        else ans=freq[1];

        for(auto i:freq){ // checking for all elements
            if(i.first==1) continue; // ignoring 1s since already handled

            long long curr= i.first;
            int len=0;

            while(freq.count(curr) and freq[curr]>1){ // finding if curr's pair exist if so trying to find same for curr*curr and incrementing length
                len+=2;
                curr=curr*curr;
            }

            if(freq.count(curr)==1) len+=1; // if last curr occured only 1s making it a peak, increasing 1 length
            else len-=1; // else removing the element, reducing 1 length

            ans=max(ans,len); // finding max of all length
            
        }

        return ans;
    }
};

// O(n) O(n)
// we can form valid subarray with odd no. of 1s. Then checking all other elements,
// if that exists at least 2 adding length and finding its square greedily for greater valid lengths
// while loop breaks when curr is less than 1 or doesnt exist in map, then checking if curr is present
// atleast 1 using it as peak, or else 1 of the last curr to get peak.