class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int i=0;
        stack<int> st;
        while (i<tokens.size()) {
            if (tokens[i] == "*" || tokens[i] == "/" || tokens[i] == "+" || tokens[i] == "-") {
                int op1 = st.top();
                st.pop();
                int op2 = st.top();
                st.pop();
                if (tokens[i] == "*") {
                    st.push(op1 * op2);
                } else if (tokens[i] == "/") {
                    st.push(op2/op1);
                } else if (tokens[i] == "+") {
                    st.push(op2 + op1);
                } else {
                    st.push(op2 - op1);
                }
            }
            else {
                st.push(stoi(tokens[i]));
            }
            i++;
        }
        return st.top();
    }
};
