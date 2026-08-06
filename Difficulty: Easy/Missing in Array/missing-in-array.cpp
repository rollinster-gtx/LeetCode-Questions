class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int sum=0;
        long long n=arr.size()+1;
        for(int i=0;i<n-1;i++)
        sum+=arr[i];
        
        long long ans =n*(n+1)/2;
        
        return ans-sum;
    }
};