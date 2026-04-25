class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_cnt = 0;
        unordered_set<int> st;
        for (int n: nums) st.insert(n);
        for (int i=0; i<nums.size(); i++) {
            int n = nums[i];
            if (st.count(n-1)) continue;
            int cnt = 1;
            while (st.count(n+1)) {
                cnt++;
                n++;
            }
            max_cnt = max(max_cnt, cnt);
        }
        return max_cnt;
    }
};
