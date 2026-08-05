class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Code Here
        for(int i=arr.size()-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
            {
                if(arr[j]>arr[j+1])
                swap(arr[j],arr[j+1]);
            }
        }
        for(int i=0;i<=arr.size()-2;i++)
        {
            int ans = target-arr[i];
            int start=i+1,end=arr.size()-1;
            while(start<end)
            {
                if(arr[start]+arr[end]==ans)
                return 1;
                else if(arr[start]+arr[end]>ans)
                end--;
                else
                start++;
                
            }
            
        }
        return 0;
        
    }
};