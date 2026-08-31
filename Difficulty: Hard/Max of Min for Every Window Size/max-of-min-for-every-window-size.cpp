class Solution {
  public:
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            // value kb tk pop hogi.
            // NSR NSL
            while (!st.empty() && arr[st.top()] > arr[i]) {
                int index = st.top();
                st.pop();

                // i = next smallest right
                // stack ke andr jo index, NSL
                if (st.empty()) {
                    int range = i; // Max window size
                    ans[range - 1] = max(ans[range - 1], arr[index]);
                } else {
                    int range = i - st.top() - 1; // Max window
                    ans[range - 1] = max(ans[range - 1], arr[index]);
                }
            }
            st.push(i);
        }

        // stack khali kro
        while (!st.empty()) {
            int index = st.top();
            st.pop();
            // i = NSR
            // stack ke andr jo index, NSL
            if (st.empty()) {
                int range = n;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            } else {
                int range = n - st.top() - 1;
                ans[range - 1] = max(ans[range - 1], arr[index]);
            }
        }

        // ans array ki value ko update kro
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = max(ans[i], ans[i + 1]);
        }

        return ans;
    }
};