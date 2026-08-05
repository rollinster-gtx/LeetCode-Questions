class Solution {
public:

    bool possible(vector<int> &stalls, int k, int dist) {

        int count = 1;
        int last = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {

            if (stalls[i] - last >= dist) {
                count++;
                last = stalls[i];
            }
        }

        return count >= k;
    }

    int aggressiveCows(vector<int> &stalls, int k) {

        sort(stalls.begin(), stalls.end());

        int start = 1;
        int end = stalls.back() - stalls[0];
        int ans = 0;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (possible(stalls, k, mid)) {
                ans = mid;
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;
    }
};