class Solution {
  public:
    int minChar(string str){
        //Write your code here
        // String reverse
        string rev = str;
        reverse(rev.begin(), rev.end());
        int size = str.size();
        str+='$';  // Separator
        str+=rev;  // Reverse

        // Longest prefix nikalna hai
        int n = str.size();
        vector<int>lps(n,0);

        int pre =0 , suf =1;

        while(suf<str.size())
        {
            // Matched
            if(str[pre]==str[suf])
            {
                lps[suf]=pre+1;
                pre++, suf++;
            }
            // Not Matched
            else
            {
                if(pre==0)
                    suf++;
                else
                {
                    pre = lps[pre-1];
                }
            }
        }

        // Answer dena hai
        return size - lps[n-1];
    }
};