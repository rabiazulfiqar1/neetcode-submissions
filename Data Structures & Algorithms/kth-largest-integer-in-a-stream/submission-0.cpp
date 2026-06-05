class KthLargest {
    int k;
    vector<int> nums;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums = nums;
        for (auto n: nums) {
            minHeap.push(n);
            if (minHeap.size() > k) minHeap.pop();
        }
    }
    
    int add(int val) {
        nums.push_back(val);
        minHeap.push(val);
        if (minHeap.size() > k) minHeap.pop();
        return minHeap.top();
    }
};
