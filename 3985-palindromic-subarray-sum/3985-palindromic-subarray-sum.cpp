class Solution {
public:
    vector<int> manacher(vector<int> s) {
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

        // Prefix sum
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        // Transform: -1 is separator
        vector<int> t;
        t.push_back(-1);

        for (int x : nums) {
            t.push_back(x);
            t.push_back(-1);
        }

        vector<int> rad = manacher(t);

        long long ans = 0;

        for (int c = 0; c < t.size(); c++) {

            int L = c - rad[c];
            int R = c + rad[c];

            // Convert transformed indices -> original indices
            int l = L / 2;
            int r = R / 2 - 1;

            if (l <= r)
                ans = max(ans, pref[r + 1] - pref[l]);
        }

        return ans;
    }
};