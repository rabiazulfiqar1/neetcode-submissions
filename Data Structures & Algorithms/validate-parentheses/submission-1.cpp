class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        while (i < s.length()) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
            else if (s[i] == ']' || s[i] == '}' || s[i] == ')') {
                if (st.empty()) return false;
                if ((st.top()=='{' && s[i]=='}') || (st.top()=='(' && s[i]==')') || (st.top()=='[' && s[i]==']')) {
                    st.pop();
                } 
                else return false;
            }
            i++;
        }
        if (st.empty()) return true;
        return false;
    }
};
