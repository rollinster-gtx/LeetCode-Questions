class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int ans=-1;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>ans)
            ans=arr[i];
        }
        
        int second=-1;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]!=ans)
            second=max(second,arr[i]);
        }
        return second;
    }
};