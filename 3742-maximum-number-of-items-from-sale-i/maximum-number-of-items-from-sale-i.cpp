class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freeCnt(n, 0);

        int cheapest = INT_MAX;

        // Count free items for each item
        for (int i = 0; i < n; i++) {
            cheapest = min(cheapest, items[i][1]);

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freeCnt[i]++;
                }
            }
        }

        // 0/1 Knapsack
        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int price = items[i][1];

            for (int j = budget; j >= price; j--) {
                dp[j] = max(dp[j],
                            dp[j - price] + freeCnt[i] + 1);
            }
        }

        int ans = 0;

        // Spend remaining budget on cheapest item
        for (int j = 0; j <= budget; j++) {
            ans = max(ans, dp[j] + (budget - j) / cheapest);
        }

        return ans;
    }
};
