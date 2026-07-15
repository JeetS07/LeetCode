class Solution {
public:
    int sumOfN(int a, int n){ // Sum of n numbers = n/2(2a+(n-1)d)
        return n*((2*a) + ((n-1)*2))/2;
    }

    int gcd(int a, int b){ // Euclidean Algorithm
        while(b!=0){
            int temp=b;
            b=a%b;
            a=temp;
        }

        return a;
    }

    int gcdOfOddEvenSums(int n) {
        int sumEven=sumOfN(2,n);
        int sumOdd=sumOfN(1,n);

        return gcd(sumEven,sumOdd);
    }
};

// O(log(min(sumEven,sumOdd))) O(1)
// Using AP series formula to calculate sum and using 
// Euclidean Algorithm for gcd