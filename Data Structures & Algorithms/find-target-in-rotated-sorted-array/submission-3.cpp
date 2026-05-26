class Solution {
public:
    int search( vector<int>& nums, int target ) {
        int s = 0, e = nums.size() - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target) return mid;

            // left sorted
            if (nums[mid] >= nums[s]) {
                if (nums[mid] < target || nums[s] > target) s = mid+1;
                else e = mid-1;
            } else {
                if (nums[mid] > target || target > nums[e]) e = mid-1;
                else s = mid+1;
            }
        }
        return -1;
    }
};
