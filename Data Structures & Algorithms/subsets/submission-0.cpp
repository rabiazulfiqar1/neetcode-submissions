class Solution {
public:
    void recursiveSol(vector<int> nums, int i, vector<vector<int>>& res, vector<int>& subset,int n) {
        if (i >= n){
            res.push_back(subset);
            return;
        } 
        subset.push_back(nums[i]);
        recursiveSol(nums, i+1, res, subset, n);
        subset.pop_back();
        recursiveSol(nums, i+1, res, subset, n);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        recursiveSol(nums, 0, ans, subset, nums.size());
        return ans;
    }
};
