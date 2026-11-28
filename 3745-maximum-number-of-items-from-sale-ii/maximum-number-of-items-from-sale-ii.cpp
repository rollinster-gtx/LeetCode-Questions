
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> freq(n + 1, 0);

        int minPrice = INT_MAX;

        for(int i = 0; i < n; i++)
        {
            freq[items[i][0]]++;
            minPrice = min(minPrice, items[i][1]);
        }

        // Calculate gain only once for each factor
        vector<int> gain(n + 1, 0);

        for(int i = 1; i <= n; i++)
        {
            for(int j = i; j <= n; j += i)
            {
                gain[i] += freq[j];
            }

            gain[i]--;
        }

        vector<pair<int, int>> v;

        for(int i = 0; i < n; i++)
        {
            int f = items[i][0];
            int price = items[i][1];

            if(gain[f] > 0 && price <= 2LL * minPrice)
            {
                v.push_back({price, gain[f]});
            }
        }

        sort(v.begin(), v.end());

        long long ans = 0;

        for(int i = 0; i < v.size(); i++)
        {
            int price = v[i].first;
            int cnt = v[i].second;

            long long take = min(1LL * cnt, 1LL * budget / price);

            ans += take * 2;
            budget -= take * price;
        }

        ans += budget / minPrice;

        return (int)ans;
    }
};
