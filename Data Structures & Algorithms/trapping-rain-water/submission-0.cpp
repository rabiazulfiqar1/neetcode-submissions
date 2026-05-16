class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;
        int n = height.size();
        for (int i=0; i<n-1; i++) {
            int leftmax = 0, rightmax = 0;
            for (int l=i-1; l>=0; l--) {
                leftmax = max(leftmax, height[l]);
            }
            for (int r=i+1; r<n; r++) {
                rightmax = max(rightmax, height[r]);
            }
            area += max(0, min(leftmax, rightmax)-height[i]);
        }
        return area;
    }
};
