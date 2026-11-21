
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;

                int best = 1e9;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0) continue;

                    int changes = 0;

                    for (int x = 0; x < d; x++) {
                        for (int y = 0; y < len / d; y++) {
                            int l = i + x + y * d;
                            int r = i + x + (len / d - 1 - y) * d;

                            if (l < r && s[l] != s[r]) {
                                changes++;
                            }
                        }
                    }

                    best = min(best, changes);
                }

                cost[i][j] = best;
            }
        }

        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 1e9));

        dp[0][0] = 0;

        for (int parts = 1; parts <= k; parts++) {
            for (int i = parts * 2; i <= n; i++) {
                for (int j = (parts - 1) * 2; j < i - 1; j++) {
                    dp[parts][i] = min(dp[parts][i],
                        dp[parts - 1][j] + cost[j][i - 1]);
                }
            }
        }

        return dp[k][n];
    }
};

