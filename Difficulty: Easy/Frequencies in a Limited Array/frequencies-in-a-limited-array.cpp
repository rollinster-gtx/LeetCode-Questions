class Solution {
  public:
    vector<int> frequencyCount(vector<int>& arr) {
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
        
        for(int i=0;i<n;i++)
        {
            arr[i]/=n;
        }
        
        return arr;
        
        
    }
};
