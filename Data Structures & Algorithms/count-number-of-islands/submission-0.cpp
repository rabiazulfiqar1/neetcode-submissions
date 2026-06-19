class Solution {
public:
    void bfs(int r, int c, int rows, int cols, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c] = '#';

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto d: directions) {
                int r = row+d.first;
                int c = col+d.second;
                if (r >=0 && r < rows  && c >=0 && c<cols && grid[r][c] == '1') {
                    grid[r][c] = '#';
                    q.push({r, c});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.size() == 0) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        for (int i=0; i<rows; i++) {
            for (int j=0; j<cols; j++) {
                if (grid[i][j] == '1' && grid[i][j] != '#') {
                    bfs(i, j, rows, cols, grid);
                    islands+=1;
                }
            }
        }
        return islands;
    }
};
