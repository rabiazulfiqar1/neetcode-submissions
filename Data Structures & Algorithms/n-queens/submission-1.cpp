class Solution {
public:
    void recursiveSol(int n, int i, unordered_set<int>& cols, unordered_set<int>& posDiag, unordered_set<int>& negDiag, vector<string>& board, vector<vector<string>>& ans) {
        if (i == n) {
            ans.push_back(board);
            return;
        }

        for (int j=0; j<n; j++) {
            if (cols.find(j) != cols.end() || posDiag.find(i-j) != posDiag.end() || negDiag.find(i+j) != negDiag.end()) continue;
            board[i][j] = 'Q';
            cols.insert(j);
            posDiag.insert(i-j);
            negDiag.insert(i+j);
            recursiveSol(n, i+1, cols, posDiag, negDiag, board, ans);

            board[i][j] = '.';
            cols.erase(j);
            posDiag.erase(i-j);
            negDiag.erase(i+j);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int> cols;
        unordered_set<int> posDiag;
        unordered_set<int> negDiag;
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        recursiveSol(n, 0, cols, posDiag, negDiag, board, ans);
        return ans;
    }
};