class Solution {
public:
    int bfs(int r, int c, int rows, int cols, vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = 0;
        int sum = 1;

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto d: directions) {
                int r = row+d.first;
                int c = col+d.second;
                if (r >=0 && r < rows  && c >=0 && c<cols && grid[r][c] == 1) {
                    sum++;
                    grid[r][c] = 0;
                    q.push({r, c});
                }
            }
        }
        return sum;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.size() == 0) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int maxislands = 0;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j] == 1) {
                    maxislands = max(maxislands, bfs(i, j, rows, cols, grid));
                }
            }
        }
        return maxislands;
    }
};
