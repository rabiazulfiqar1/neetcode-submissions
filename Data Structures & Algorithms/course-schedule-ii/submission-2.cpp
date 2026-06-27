class Solution {
public:
    bool dfs(int node, unordered_map<int, vector<int>>& mp, unordered_set<int>& vis, unordered_set<int>& cycle, vector<int>& ans) {
        if (cycle.find(node) != cycle.end()) return false; //cycle
        if (vis.find(node) != vis.end()) return true; //visited
        cycle.insert(node);
        for (auto pre: mp[node]) {
            if (!dfs(pre, mp, vis, cycle, ans)) return false;
        }
        cycle.erase(node);
        vis.insert(node);
        ans.push_back(node);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        for (auto preq: prerequisites) {
            mp[preq[0]].push_back(preq[1]);
        }
        unordered_set<int> visited;
        unordered_set<int> cycle;
        vector<int> ans;
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, mp, visited, cycle, ans)) return {};
        }
        return ans;
    }
};
