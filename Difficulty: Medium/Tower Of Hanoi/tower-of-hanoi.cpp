class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        if (n == 0) return 0;
        
        // Total moves = (moves for n-1) + 1 (current disk) + (moves for n-1)
        return 2 * towerOfHanoi(n - 1, from, aux, to) + 1;
    }
};