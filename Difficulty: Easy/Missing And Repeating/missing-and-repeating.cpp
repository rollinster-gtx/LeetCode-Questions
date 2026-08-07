class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n=arr.size();
        
        //decrease value by 1
        for(int i=0;i<n;i++)
        arr[i]--;
        
        
        //occurance
        for(int i=0;i<n;i++)
        {
            arr[arr[i]%n]+=n;
        }
        
        vector<int>ans(2);
        for(int i=0;i<n;i++)
        {
            if(arr[i]/n==2) //repeating element
            ans[0]=i+1;
            else if(arr[i]/n==0) //missing element
            ans[1]=i+1;
        }
        return ans;
    }
};