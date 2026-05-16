class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int maxp = 0;
        for (int i=prices.size()-1; i>=0; i--) {
            maxp = max(maxp, prices[i]);
            profit = max(profit, maxp - prices[i]);
        }
        return profit;
    }
};
