class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // [-4, -1, -1, 0, 1, 2]
        vector<vector<int>> output;
        for (int i=0; i<nums.size(); i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int pt1 = i+1;
            int pt2 = nums.size()-1;
            while (pt1 < pt2) {
                if (nums[pt1]+nums[pt2] == target) {
                    output.push_back({nums[pt1], nums[pt2], -target});
                    pt1++; pt2--;
                    while (pt1<pt2 && nums[pt1]==nums[pt1-1]) pt1++;
                    while (pt1<pt2 && nums[pt2]==nums[pt2+1]) pt2--;
                } else if (nums[pt1]+nums[pt2] > target) pt2--;
                else pt1++;
            }
        }
        return output;
    }
};
