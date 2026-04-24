class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n:nums) {
            freq[n]++;
        }
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        // for (const auto& [key, freqs]: freq) {
        //     pq.push({freqs, key});
        //     if (pq.size()>k) pq.pop();
        // }

        vector<vector<int>> buckets(nums.size()+1);

        for (const auto& [key, freqs]: freq) {
            buckets[freqs].push_back(key);
        }

        vector<int> result;
        // while (!pq.empty()) {
        //     result.push_back(pq.top().second);
        //     pq.pop();
        // }
        int cnt = 0;
        for (int i=nums.size(); i>=0; i--) {
            if (!buckets[i].empty()) {
                for (int n: buckets[i]) {
                    if (cnt < k) {
                        result.push_back(n);
                        cnt++;
                    }
                }
            }
        }
        return result;
    }
};
