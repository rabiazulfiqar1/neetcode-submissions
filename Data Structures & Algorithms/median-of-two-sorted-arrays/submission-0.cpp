class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size()) {
            swap(nums1, nums2);
        }

        int total = nums1.size() + nums2.size();
        int half = total / 2;

        int s = 0;
        int e = (int)nums1.size();

        while (s <= e) {

            int i = s + (e - s) / 2;
            int j = half - i;

            int Aleft  = (i - 1 >= 0) ? nums1[i - 1] : INT_MIN;
            int Aright = (i < (int)nums1.size()) ? nums1[i] : INT_MAX;

            int Bleft  = (j - 1 >= 0) ? nums2[j - 1] : INT_MIN;
            int Bright = (j < (int)nums2.size()) ? nums2[j] : INT_MAX;

            if (Aleft <= Bright && Bleft <= Aright) {

                if (total % 2 == 0) {

                    return (max(Aleft, Bleft) + 
                            min(Aright, Bright)) / 2.0;
                }

                return min(Aright, Bright);
            }

            else if (Aleft > Bright) {
                e = i - 1;
            }

            else {
                s = i + 1;
            }
        }
        return -1;
    }
};