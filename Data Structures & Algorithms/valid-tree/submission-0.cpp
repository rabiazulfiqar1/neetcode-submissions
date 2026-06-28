class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int prev, unordered_set<int>& vis, int node) {
        if (vis.find(node) != vis.end()) return false;

        vis.insert(node);
        for (int j: adj[node]) {
            if (j==prev) continue;
            if (!dfs(adj, node, vis, j)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if (!n) return true;
        vector<vector<int>> adj(n);
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> vis;
        return dfs(adj, -1, vis, 0) && vis.size()==n;
    }
};
