class Solution {
  public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    string dir = "UDLR";

    bool valid(int i, int j, int n) {
        return i >= 0 && j >= 0 && i < n && j < n;
    }

    void Total(vector<vector<int>>& matrix, int i, int j, int n, string& path, vector<string>& ans, vector<vector<bool>>& visited) {
        // Base case: destination reached
        if (i == n - 1 && j == n - 1) {
            ans.push_back(path);
            return;
        }

        visited[i][j] = 1;

        for (int k = 0; k < 4; k++) {
            int new_i = i + row[k];
            int new_j = j + col[k];
            
            if (valid(new_i, new_j, n) && matrix[new_i][new_j] == 1 && !visited[new_i][new_j]) {
                path.push_back(dir[k]);
                Total(matrix, new_i, new_j, n, path, ans, visited);
                path.pop_back();
            }
        }

        visited[i][j] = 0;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<vector<bool>> visited(n, vector<bool>(n, 0));
        vector<string> ans;
        string path = "";

        // Corner case: source ya destination blocked ho
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;

        Total(maze, 0, 0, n, path, ans, visited);
        
        // GFG standard: lexicographical order maintain karna
        sort(ans.begin(), ans.end());
        return ans;
    }
};