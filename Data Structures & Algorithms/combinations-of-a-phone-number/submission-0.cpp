class Solution {
    unordered_map<char, vector<char>> mp = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };
public:
    void recursiveSol(int i, string& curr, vector<string>& ans, string& digits) {
        if (i >= digits.length()) {
            ans.push_back(curr);
            return;
        }
        for (char ch: mp[digits[i]]) {
            curr += ch;
            recursiveSol(i+1, curr, ans, digits);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string curr = "";
        if (digits.empty()) return ans;
        recursiveSol(0, curr, ans, digits);
        return ans;
    }
};
