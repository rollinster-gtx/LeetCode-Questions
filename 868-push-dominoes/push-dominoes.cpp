class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int left = -1;

        for (int i = 0; i <= n; i++) {
            char right = (i == n) ? 'R' : dominoes[i];

            if (right == '.') {
                continue;
            }

            if (right == 'L') {
                if (left == -1) {
                    for (int j = 0; j < i; j++) {
                        dominoes[j] = 'L';
                    }
                }
                else if (dominoes[left] == 'L') {
                    for (int j = left + 1; j < i; j++) {
                        dominoes[j] = 'L';
                    }
                }
                else {
                    int l = left + 1;
                    int r = i - 1;

                    while (l < r) {
                        dominoes[l] = 'R';
                        dominoes[r] = 'L';
                        l++;
                        r--;
                    }
                }
            }
            else if (right == 'R' && left != -1 &&
                     dominoes[left] == 'R') {
                for (int j = left + 1; j < i; j++) {
                    dominoes[j] = 'R';
                }
            }

            left = i;
        }

        return dominoes;
    }
};