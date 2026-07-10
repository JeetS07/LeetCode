class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(b.size()<a.size()) swap(a,b); // making a as smaller size array

        int total=a.size()+b.size();
        int half=total/2;

        int l=0, r=a.size()-1;
        while(true){
            // if(l+r)<0 we want i to be INT_MIN, but cpp uses integer division i.e. for -1/2, cpp rounds it off to 0 and not -1
            int i = (l+r < 0) ? -1 : ((l + r) / 2); // partition in a ;
            int j = half-i-2; // partition in b

            int leftA = (i >= 0) ? a[i] : INT_MIN; // rightmost element in left partition of a
            int rightA = (i+1 < a.size()) ? a[i+1] : INT_MAX; // leftmost element in right partition of a

            int leftB = (j >= 0) ? b[j] : INT_MIN; // rightmost element in left partition of b
            int rightB = (j+1 < b.size()) ? b[j+1] : INT_MAX; // leftmost element in right partition of b

            if(leftA<=rightB and leftB<=rightA){ // partition is perfect
                if(total%2 != 0) return min(rightA,rightB); // odd
                else return (double)(max(leftA,leftB)+min(rightA,rightB))/2.0; // even
            }
            else if(leftA>rightB) r=i-1; // decrease elements from a
            else l=i+1; // increase elements from a
        }

        return 0;
    }
};

// O(log(min(a_size,b_size))) O(1)
// first we consider a as minimum length array, then mark its mid as parition, and half-mid as partition of larger array
// as half elements we wil have in our left partition. Now 
// if:
// leftA<=rightB and leftB<=rightA, then we already did a correct partition, then find its median
// else:
// we reduce or increase elements from a based on requirement
