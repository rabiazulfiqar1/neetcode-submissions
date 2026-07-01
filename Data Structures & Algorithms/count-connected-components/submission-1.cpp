class Solution {
public:
    int find(int n, vector<int>& par) { //find parent
        int res = n;
        while (res != par[res]) { // when node will be parent of itself: ultimate parent
            par[res] = par[par[res]]; //PATH COMPRESSION
            res = par[res];
        }
        return res;
    }

    int find_union(int n1, int n2, vector<int>& par, vector<int>& rank) {
        int p1 = find(n1, par);
        int p2 = find(n2, par);
        if (p1 == p2) return 0; //both nodes have same parent (i.e already connected)
        // we need to connect smaller rank to larger rank
        if (rank[p2] > rank[p1]) {
            par[p1] = p2;
            rank[p2] += rank[p1];
        } else {
            par[p2] = p1;
            rank[p1] += rank[p2];
        }
        return 1; //union happened
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> par(n);
        for (int i=0; i<n; i++) {
            par[i] = i;
        }
        vector<int> rank(n, 1);
        int n_comp = n;
        for (auto edge: edges) {
            n_comp -= find_union(edge[0], edge[1], par, rank);
        }
        return n_comp;
    }
};
