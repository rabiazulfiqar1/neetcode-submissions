class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int i=0, j=0;
        int max_cnt = 0;
        while (j<s.length() && i<=j) {
            while (j < s.length() && !seen.count(s[j])) {
                seen.insert(s[j]);
                j++;
            } 
            seen.erase(s[i]);
            max_cnt = max(max_cnt, j-i);
            i++;
        }
        return max_cnt;
    }
};
