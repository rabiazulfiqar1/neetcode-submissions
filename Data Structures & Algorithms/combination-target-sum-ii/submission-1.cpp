class Solution {
public:
    void dfs(vector<int>& candidates, int sum, int target, vector<int>& curr, vector<vector<int>>& ans, int i) {
        if (sum == target) {
            ans.push_back(curr);
            return;
        } else if (sum > target || i>=candidates.size()) return;
        curr.push_back(candidates[i]);
        dfs(candidates, sum+candidates[i], target, curr, ans, i+1);
        curr.pop_back();
        while ((i+1 < candidates.size()) && (candidates[i] == candidates[i+1])) i+=1;
        dfs(candidates, sum, target, curr, ans, i+1);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(candidates, 0, target, curr, ans, 0);
        return ans;
    }
};
