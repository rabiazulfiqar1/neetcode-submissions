class Solution {
public:
    vector<vector<int>> permute(vector<int> nums) {
        if (nums.empty()) return {{}};

        int first = nums[0];
        nums.erase(nums.begin());

        vector<vector<int>> perms = permute(nums);
        vector<vector<int>> result;

        for (auto &p : perms) {
            for (int i = 0; i <= p.size(); i++) {
                vector<int> temp = p;
                temp.insert(temp.begin() + i, first);
                result.push_back(temp);
            }
        }

        return result;
    }
};