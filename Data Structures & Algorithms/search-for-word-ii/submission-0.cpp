class TrieNode {
    public:
        bool isTerminal;
        TrieNode* children[26];
        char data;

        TrieNode(char d) {
            isTerminal = false;
            data = d;
            for (int i=0; i<26; i++) {
                children[i] = NULL;
            }
        }

        void addWord(string word) {
            TrieNode* curr = this;
            for (char c: word) {
                int idx = c-'a';
                if (curr->children[idx] == NULL) {
                    curr->children[idx] = new TrieNode(c);
                } 
                curr = curr->children[idx];
            }
            curr->isTerminal = true;
        }
};

class Solution {
public:
    set<pair<int, int>> visited;
    unordered_set<string> res;
    TrieNode* root = new TrieNode('\0');
    void dfs(int r, int c, TrieNode* node, string word, int ROWS, int COLS, vector<vector<char>>& board) {
        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || visited.count({r,c}))
        {
            return;
        }

        char ch = board[r][c];

        if(node->children[ch - 'a'] == NULL) return;
        
        visited.insert({r, c});
        word += board[r][c];
        node = node->children[board[r][c] - 'a'];
        if (node->isTerminal) {
            res.insert(word);
        }

        dfs(r+1, c, node, word, ROWS, COLS, board);
        dfs(r-1, c, node, word, ROWS, COLS, board);
        dfs(r, c+1, node, word, ROWS, COLS, board);
        dfs(r, c-1, node, word, ROWS, COLS, board);
        visited.erase({r, c});
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (string w: words) {
            root->addWord(w);
        }

        int ROWS = board.size();
        int COLS = board[0].size();
        for (int i=0; i<ROWS; i++) {
            for (int j=0; j<COLS; j++) {
                dfs(i, j, root, "", ROWS, COLS, board);
            }
        }

        return vector<string>(res.begin(), res.end());
    }
};
