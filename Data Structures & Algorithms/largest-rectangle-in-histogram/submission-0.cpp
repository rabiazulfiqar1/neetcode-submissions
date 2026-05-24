class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st; // height, index
        int maxh = 0;
        for (int i=0; i<heights.size(); i++) {
            int index = i;
            while (!st.empty() && st.top().first>heights[i]) {
                index = st.top().second;
                maxh = max(maxh, st.top().first * (i-index));
                st.pop();
            }
            st.push({heights[i], index});
        }

        int n = heights.size();

        while (!st.empty()) {
            maxh = max(maxh, st.top().first * (n - st.top().second));
            st.pop();
        }

        return maxh;
    }
};
