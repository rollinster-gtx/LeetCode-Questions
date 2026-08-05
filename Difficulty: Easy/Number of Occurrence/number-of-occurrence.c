int countFreq(int arr[], int n, int target) {
    // code here
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==target)
        count++;
    }
    return count;
}