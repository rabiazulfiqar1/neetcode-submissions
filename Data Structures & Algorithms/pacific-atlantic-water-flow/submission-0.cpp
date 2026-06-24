class Solution {
public:
    void dfs(int r, int c, vector<vector<bool>>& vis, int prevHeight, vector<vector<int>>& heights) {
        if (r<0 || r==heights.size() || c<0 || c==heights[0].size() || vis[r][c] || heights[r][c]<prevHeight) return;
        vis[r][c] = true;
        dfs(r+1, c, vis, heights[r][c], heights);
        dfs(r-1, c, vis, heights[r][c], heights);
        dfs(r, c+1, vis, heights[r][c], heights);
        dfs(r, c-1, vis, heights[r][c], heights);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size(), COLS = heights[0].size();
        vector<vector<bool>> pac(ROWS, vector<bool>(COLS, false));
        vector<vector<bool>> atl(ROWS, vector<bool>(COLS, false));

        for (int c=0; c<COLS; c++) {
            dfs(0, c, pac, heights[0][c], heights);
            dfs(ROWS-1, c, atl, heights[ROWS-1][c], heights);
        }

        for (int r=0; r<ROWS; r++) {
            dfs(r, 0, pac, heights[r][0], heights);
            dfs(r, COLS-1, atl, heights[r][COLS-1], heights);
        }

        vector<vector<int>> ans;
        for (int i=0; i<ROWS; i++) {
            for (int j=0; j<COLS; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
