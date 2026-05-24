class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        vector<int> result(temperatures.size(), 0);
        for (int i=0; i<temperatures.size(); i++) {
            while (!st.empty() && st.top().first < temperatures[i]) {
                result[st.top().second] = i-st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }
        while (!st.empty()) {
            result[st.top().second] = 0;
            st.pop();
        }
        return result;
    }
};
