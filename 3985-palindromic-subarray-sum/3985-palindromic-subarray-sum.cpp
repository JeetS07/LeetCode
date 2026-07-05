class Solution {
public:
    vector<int> manacher(vector<int> s) { // return center of all palindromes with their radius
        int n = s.size();
        vector<int> radii(n, 0);
        int center = 0;
        int radius = 0;
        while (center < n) {
            while (center + radius + 1 < n &&
                   center - radius - 1 >= 0 &&
                   s[center + radius + 1] == s[center - radius - 1]) {
                radius++;
            }
            radii[center] = radius;
            int oldCenter = center;
            int oldRadius = radius;
            center++;
            radius = 0;
            while (center <= oldCenter + oldRadius) {
                int mirror = oldCenter - (center - oldCenter);
                int limit = oldCenter + oldRadius - center;
                if (radii[mirror] < limit) {
                    radii[center] = radii[mirror];
                    center++;
                }
                else if (radii[mirror] > limit) {
                    radii[center] = limit;
                    center++;
                }
                else {
                    radius = limit;
                    break;
                }
            }
        }
        return radii;
    }

    long long getSum(vector<int>& nums) {

        int n = nums.size();

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++) // Prefix sum
            pref[i + 1] = pref[i] + nums[i];

        vector<int> t; // Insert -1 as separator
        t.push_back(-1);
        for (int x : nums) {
            t.push_back(x);
            t.push_back(-1);
        }

        vector<int> rad = manacher(t);

        long long ans = 0;

        for (int c = 0; c < t.size(); c++) {
            int L = c - rad[c]; // left boundary of palindrome
            int R = c + rad[c]; // left boundary of palindrome

            // Convert transformed indices to original indices
            int l = L / 2;
            int r = R / 2 - 1;

            if (l <= r)
                ans = max(ans, pref[r + 1] - pref[l]); // finding highest sum of all palindromes
        }

        return ans;
    }
};

// Manacher's Algorithm(find palindromic subarray in O(n))
// we will get all palindrome centers and their radius using manacher,
// now we need to find all sum of these subarray and return max ans.
// to calculate sum in O(1) time we use prefix sum
// Manachar algorithm detecs only odd palindrome, so we insert -1 as
// separator to transform all even palindrome to odd palindrome