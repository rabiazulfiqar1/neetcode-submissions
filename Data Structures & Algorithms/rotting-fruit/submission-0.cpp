class Solution {
public:
    void addfruit(int r, int c, int ROWS, int COLS, vector<vector<int>>& grid, queue<pair<int, int>>& q, int& fresh) {
        if (r < 0 || r==ROWS || c<0 || c==COLS || grid[r][c] != 1) return;
        grid[r][c] = -2;
        fresh--;
        q.push({r, c});
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int ROWS = grid.size();
        int COLS = grid[0].size();
        int fresh = 0;
        for (int i=0; i<ROWS; i++) {
            for (int j=0; j<COLS; j++) {
                if (grid[i][j] == 1) fresh++;
                else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int time = 0;
        while (!q.empty() && fresh > 0) {
            int s = q.size();
            for (int i=0; i<s; i++) {
                int r = q.front().first;
                int c=  q.front().second;
                q.pop();

                addfruit(r+1, c, ROWS, COLS, grid, q, fresh);
                addfruit(r-1, c, ROWS, COLS, grid, q, fresh);
                addfruit(r, c+1, ROWS, COLS, grid, q, fresh);
                addfruit(r, c-1, ROWS, COLS, grid, q, fresh);
            }
            time += 1;
        }

        return fresh == 0? time: -1;
    }
};
