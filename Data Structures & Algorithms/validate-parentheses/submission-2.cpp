class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;

        unordered_map<char, char> mp = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        while (i < s.length()) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else if (s[i] == ']' || s[i] == '}' || s[i] == ')') {
                if (st.empty() || st.top() != mp[s[i]]) return false;
                st.pop();
            }
            i++;
        }
        if (st.empty()) return true;
        return false;
    }
};
