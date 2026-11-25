
class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        long long mod1 = 1000000007;
        long long mod2 = 1000000009;
        long long base = 911382323;

        vector<long long> h1(n + 1, 0), h2(n + 1, 0);
        vector<long long> p1(n + 1, 1), p2(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * base + nums[i]) % mod1;
            h2[i + 1] = (h2[i] * base + nums[i]) % mod2;

            p1[i + 1] = (p1[i] * base) % mod1;
            p2[i + 1] = (p2[i] * base) % mod2;
        }

        int low = 1, high = n;
        int ans = n;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            unordered_map<unsigned long long, int> mp;

            for (int i = 0; i + mid <= n; i++) {
                long long x = (h1[i + mid] - h1[i] * p1[mid] % mod1 + mod1) % mod1;
                long long y = (h2[i + mid] - h2[i] * p2[mid] % mod2 + mod2) % mod2;

                unsigned long long key = ((unsigned long long)x << 32) | y;

                mp[key]++;
            }

            bool found = false;

            for (auto it : mp) {
                if (it.second == 1) {
                    found = true;
                    break;
                }
            }

            if (found) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
