class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = -1;
        int i=0, j=heights.size()-1;
        while (i<j) {
            int width = j-i;
            int height = min(heights[i], heights[j]);
            max_area = max(max_area, width*height);
            if (heights[i]<heights[j]) i++;
            else j--;
        }
        return max_area;
    }
};
