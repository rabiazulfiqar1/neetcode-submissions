class Solution {
public:
    bool isPalindrome(string word) {
        string rev = word;
        reverse(rev.begin(), rev.end());
        return word == rev;
    }
    void recursiveSol(string s, vector<string>& partitions, vector<vector<string>>& ans) {
        
        if (s.size() == 0) {
            ans.push_back(partitions);
            return;
        }
        
        for (int i=0; i<s.length(); i++) {
            string part = s.substr(0, i+1);

            if (isPalindrome(part)) {
                partitions.push_back(part);
                recursiveSol(s.substr(i+1), partitions, ans);
                partitions.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partitions;
        
        recursiveSol(s, partitions, ans);

        return ans;
    }
};
