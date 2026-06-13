class Solution {
public:
    set<pair<int, int>> path;

    bool recursiveSol(vector<vector<char>>& board, string word, int i, int j, int c) {
        if (c == word.length()) return true;
        if (i >= board.size() || j >= board[0].size() || i<0 || j<0 || board[i][j] != word[c] || path.count({i, j})) return false;

        path.insert({i, j});
        bool res = recursiveSol(board, word, i+1, j, c+1) || 
                   recursiveSol(board, word, i-1, j, c+1) || 
                   recursiveSol(board, word, i, j-1, c+1) || 
                   recursiveSol(board, word, i, j+1, c+1);
        path.erase({i, j});
        return res;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (recursiveSol(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
};
