class Solution {
  public:

    vector<int> bracketNumbers(string &s) {
        // code here
        int count = 0;
        stack<int>st;
        vector<int>ans;
        
        for(int i=0;i<s.size();i++)
        {
            //opening bracket
            if(s[i]=='(')
            {
                count++;
                st.push(count);
                ans.push_back(count);
            }
            //closing bracket
            else if(s[i]==')')
            {
                ans.push_back(st.top());
                st.pop();
                
            }
        }
        return ans;
    }
};