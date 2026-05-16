class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;
        int n = height.size();
        int l = 0, r = n-1;
        int maxl = 0, maxr = height[r];
        while (l<=r) {
            if (maxl < maxr) {
                area += max(0, min(maxl, maxr)-height[l]);
                maxl = max(maxl, height[l]);
                l++;
            } else {
                area += max(0, min(maxl, maxr)-height[r]);
                maxr = max(maxr, height[r]);
                r--;
            }
        }
        return area;
    }
};
