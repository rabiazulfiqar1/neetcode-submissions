class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        for (int i=0; i<points.size(); i++) {
            int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            if (pq.size() < k) pq.push({d, i});
            else if (d < pq.top().first) {
                pq.push({d, i});
                if (pq.size() > k) pq.pop();
            }
        }
        vector<vector<int>> result;
        while (!pq.empty()) {
            result.push_back(points[pq.top().second]);
            pq.pop();
        }
        return result;
    }
};
