class Solution {
  public:
    int findSubString(string str) {
        int n = str.size();
        
        // 1. Total unique characters count karo
        vector<int> total(256, 0);
        int totalUnique = 0;
        for (char c : str) {
            if (total[c] == 0) {
                totalUnique++;
                total[c] = 1;
            }
        }

        // 2. Sliding window technique
        vector<int> window(256, 0);
        int first = 0, count = 0, minLen = n;

        for (int second = 0; second < n; second++) {
            window[str[second]]++;
            if (window[str[second]] == 1) {
                count++;
            }

            // Jab saare unique characters window mein aa jayein
            while (count == totalUnique) {
                minLen = min(minLen, second - first + 1);
                
                window[str[first]]--;
                if (window[str[first]] == 0) {
                    count--;
                }
                first++;
            }
        }

        return minLen;
    }
};