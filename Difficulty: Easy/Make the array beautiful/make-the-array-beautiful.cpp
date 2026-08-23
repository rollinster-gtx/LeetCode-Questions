class Solution {
public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        stack<int> s;

        for(int i = 0; i < arr.size(); i++)
        {
            // stack can be empty
            if(s.empty())
                s.push(arr[i]);
            // Non negative number
            else if(arr[i] >= 0)
            {
                // Non negative
                if(s.top() >= 0)
                    s.push(arr[i]);
                // Negative
                else
                    s.pop();
            }
            // Negative number
            else
            {
                // Negative
                if(s.top() < 0)
                    s.push(arr[i]);
                // Non Negative
                else
                    s.pop();
            }
        }

        vector<int> ans(s.size());
        int i = s.size() - 1;
        while(!s.empty())
        {
            ans[i] = s.top();
            i--;
            s.pop();
        }
        return ans;
    }
};