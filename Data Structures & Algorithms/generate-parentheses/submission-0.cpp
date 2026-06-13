class Solution {
public:
    void recursiveSol(int n, int open, int close, vector<string>& ans, string op) {
        if (open == 0 && close == 0) {
            ans.push_back(op);
            return;
        }

        if (open > close) return; 

        if (open > 0) recursiveSol(n, open-1, close, ans, op + '(');

        if (close > open) recursiveSol(n, open, close-1, ans, op + ')');
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recursiveSol(n, n, n, ans, "");
        return ans;
    }
};
