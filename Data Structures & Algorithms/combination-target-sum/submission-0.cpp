class Solution {
public:
    void recursiveSol(vector<int>& nums, int target, int sum, int i, vector<vector<int>>& ans, vector<int>& curr) {
        if (sum == target) {
            ans.push_back(curr);
            return;
        } else if (i >= nums.size() || sum > target) return;

        curr.push_back(nums[i]);
        recursiveSol(nums, target, sum+nums[i], i, ans, curr);
        curr.pop_back();
        recursiveSol(nums, target, sum, i+1, ans, curr);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        recursiveSol(nums, target, 0, 0, ans, curr);
        return ans;
    }
};
