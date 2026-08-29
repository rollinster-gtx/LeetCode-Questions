class Solution {
  public:
    int celebrity(vector<vector<int>>& M) {
        // code here
        int n=M.size();
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        st.push(i);
        int first,second;
        while(st.size()>1)
        {
            first=st.top();
            st.pop();
            second=st.top();
            st.pop();
        
            if(M[first][second]==1)
            st.push(second);
            else
            st.push(first);
        }
        if(st.empty())
        return -1;
        
    
        int num=st.top();
        st.pop();
    
        int row=0,col=0;
        for(int i=0;i<n;i++)
        {
        if(i!=num)
        {
        row+=M[num][i];
        col+=M[i][num];
        }
        }    
        return row==0&&col==n-1?num:-1;
    }
};