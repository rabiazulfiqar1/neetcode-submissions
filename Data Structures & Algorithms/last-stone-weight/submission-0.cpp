class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (auto n: stones) {
            maxHeap.push(n);
        }
        while (maxHeap.size() > 1) {
            int x = maxHeap.top();
            maxHeap.pop();
            int y = maxHeap.top();
            maxHeap.pop();
            if (x < y) maxHeap.push(y-x);
            else if (x>y) maxHeap.push(x-y);
        }
        if (maxHeap.size() == 1) return maxHeap.top();
        return 0;
    }
};
