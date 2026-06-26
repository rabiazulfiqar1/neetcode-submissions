class Solution {
public:
    bool dfs(int node, unordered_map<int, vector<int>>& mp, unordered_set<int>& vis) {
        if (mp[node].size() == 0) return true; //no prereq
        if (vis.find(node) != vis.end()) return false; //cycle
        vis.insert(node);
        for (auto pre: mp[node]) {
            if (!dfs(pre, mp, vis)) return false;
        }
        vis.erase(node);
        mp[node] = {};
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> mp;
        for (auto preq: prerequisites) {
            mp[preq[0]].push_back(preq[1]);
        }
        unordered_set<int> visited;
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, mp, visited)) return false;
        }
        return true;
    }
};
