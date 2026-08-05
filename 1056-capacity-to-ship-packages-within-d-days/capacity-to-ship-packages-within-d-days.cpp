class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
         long long start=0,end=0,mid,ans;
        for(int i=0;i<weights.size();i++)
        {
            start=max(start,(long long)weights[i]);
            end+=weights[i];
        }
        
        while(start<=end)
        {
            mid=start+(end-start)/2;
            
            int sum=0,count=1;
            for(int i=0;i<weights.size();i++)
            {
                sum+=weights[i];
                if(sum>mid)
                {
                    count++;
                    sum=weights[i];
                }
            }
            
            if(count<=days)
            {
                ans=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        return ans;
    }
};