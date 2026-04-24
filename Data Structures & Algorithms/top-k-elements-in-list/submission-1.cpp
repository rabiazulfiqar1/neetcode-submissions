class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n:nums) {
            freq[n]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (const auto& [key, freqs]: freq) {
            pq.push({freqs, key});
            if (pq.size()>k) pq.pop();
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};
