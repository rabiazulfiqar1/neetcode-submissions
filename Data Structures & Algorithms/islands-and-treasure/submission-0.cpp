class Solution {
public:
    void addRoom(vector<vector<int>>& grid, queue<pair<int, int>>& q, int i, int j, int ROWS, int COLS) {
        if (i<0 || i==ROWS || j<0 || j==COLS || grid[i][j] != 2147483647) return;
        grid[i][j] = -2;
        q.push({i, j});
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.size() == 0) return;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int, int>> q;
        for (int i=0; i<ROWS; i++) {
            for (int j=0; j<COLS; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int dist = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i=0; i<size; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                grid[r][c] = dist;
                addRoom(grid, q, r+1, c, ROWS, COLS);
                addRoom(grid, q, r-1, c, ROWS, COLS);
                addRoom(grid, q, r, c+1, ROWS, COLS);
                addRoom(grid, q, r, c-1, ROWS, COLS);
            }
            dist += 1;
        }
    }
};
