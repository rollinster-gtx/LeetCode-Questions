class Solution {
  public:
    void lpsfind(vector<int>& lps, string s) {
        int pre = 0, suf = 1;

        while (suf < s.size()) {
            // Match
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                suf++, pre++;
            } 
            // Not Matched
            else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
    }

    // LeetCode 28 wala strStr (KMP Algorithm)
    int strStr(string haystack, string needle) {
        vector<int> lps(needle.size(), 0);
        lpsfind(lps, needle);

        int first = 0, second = 0;

        while (first < haystack.size() && second < needle.size()) {
            // Match
            if (haystack[first] == needle[second]) {
                first++, second++;
            } 
            // Not matched
            else {
                if (second == 0)
                    first++;
                else
                    second = lps[second - 1];
            }
        }

        // Answer exist
        if (second == needle.size())
            return first - second;

        return -1;
    }

    int repeatedStringMatch(string a, string b) {
        if (a == b)
            return 1;

        int repeat = 1;
        string temp = a;

        while (temp.size() < b.size()) {
            temp += a;
            repeat++;
        }

        // strStr (LC 28) se check kar rahe hain
        if (strStr(temp, b) != -1)
            return repeat;

        if (strStr(temp + a, b) != -1)
            return repeat + 1;

        return -1;
    }
};