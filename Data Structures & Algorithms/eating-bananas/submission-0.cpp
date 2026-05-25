class Solution {
    bool istrue(vector<int>& piles, int h, int k) {
        long long sum = 0;
        for (int n: piles) {
            sum += ceil(1.0 * n/k);
        }
        if (sum <= h) return true;
        return false;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int e = 0;
        for (int n: piles) e=max(n, e);
        int s = 1;
        int min_k = e;
        while (s<=e) {
            int k = s+(e-s)/2;
            if (!istrue(piles, h, k)) s = k+1;
            else {
                min_k = min(min_k, k);
                e = k-1;
            }
        }
        return min_k;
    }
};
