class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;

        for (char t : tasks) {
            mp[t]++;
        }

        priority_queue<int> maxHeap;

        for (auto& p : mp) {
            maxHeap.push(p.second);
        }

        int time = 0;

        queue<pair<int, int>> q; // {remaining_count, available_time}

        while (!maxHeap.empty() || !q.empty()) {
            time++;

            if (!maxHeap.empty()) {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();

                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }

            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};