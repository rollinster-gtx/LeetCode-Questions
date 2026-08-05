class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int start = 1, end = 0, mid, ans;

        for (int i = 0; i < piles.size(); i++) {
            end = max(end, piles[i]);
        }

        ans = end;

        while (start <= end) {

            mid = start + (end - start) / 2;

            long long hours = 0;

            for (int i = 0; i < piles.size(); i++) {
                hours += (piles[i] + mid - 1) / mid;
            }

            if (hours <= h) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return ans;
    }
};