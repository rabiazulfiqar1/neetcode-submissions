class Solution {
public:
    int findMin(vector<int> &nums) {
        int minn = nums[0];
        int s = 0, e = nums.size()-1;
        while (s<=e) {
            if (nums[s] < nums[e]) {
                minn = min(minn, nums[s]);
                break; 
            }
            int mid = s+(e-s)/2;
            minn = min(nums[mid], minn);
            if (nums[mid] >= nums[s]) s = mid+1;
            else e = mid-1;
        }
        return minn;
    }
};
