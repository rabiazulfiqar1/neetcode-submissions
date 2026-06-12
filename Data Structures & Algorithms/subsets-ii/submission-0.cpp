class Solution {
public:
    void recursiveSol(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int>& curr) {
        if (i>=nums.size()) {
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        recursiveSol(nums, i+1, ans, curr);
        curr.pop_back();
        while ((i+1 < nums.size()) && (nums[i] == nums[i+1])) i+=1;
        recursiveSol(nums, i+1, ans, curr);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        recursiveSol(nums, 0, ans, curr);
        return ans;
    }
};
