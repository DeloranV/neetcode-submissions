class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0;
        int total_profit = 0;

        for (int j = 1; j < prices.size(); ++j) {
            int diff = prices[j] - prices[i];
            if (diff > 0) total_profit += diff;
            i++;
        }

        return max(total_profit, 0);
    }
};