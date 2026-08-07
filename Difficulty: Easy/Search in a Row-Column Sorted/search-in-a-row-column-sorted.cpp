class Solution {
  public:
    bool matSearch(vector<vector<int>> &arr, int x) {
        // code here
        
        int n=arr.size(),m=arr[0].size(),row=0,col=m-1;
        
        while(row<n&&col>=0)
        {
            if(arr[row][col]==x)
            return 1;
            else if(arr[row][col]<x)
            row++;
            else
            col--;
        }
        return 0;
    }
};