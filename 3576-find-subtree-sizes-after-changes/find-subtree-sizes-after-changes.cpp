class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        vector<vector<int>> newAdj(n);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);
        vector<int> newParent(n, -1);

        function<void(int)> dfs1 = [&](int node) {
            int ch = s[node] - 'a';

            int old = last[ch];

            if (old != -1) {
                newParent[node] = old;
            } else {
                newParent[node] = parent[node];
            }

            last[ch] = node;

            for (int child : adj[node]) {
                dfs1(child);
            }

            last[ch] = old;
        };

        dfs1(0);

        for (int i = 1; i < n; i++) {
            newAdj[newParent[i]].push_back(i);
        }

        vector<int> ans(n, 0);

        function<int(int)> dfs2 = [&](int node) {
            int size = 1;

            for (int child : newAdj[node]) {
                size += dfs2(child);
            }

            ans[node] = size;
            return size;
        };

        dfs2(0);

        return ans;
    }
};
