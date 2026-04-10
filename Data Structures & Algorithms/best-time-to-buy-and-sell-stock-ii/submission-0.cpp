class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, j = 1;
        int total_profit = 0;

        while (j < prices.size()) {
            int diff = prices[j] - prices[i];
            if (diff > 0) total_profit += diff;
            i++;
            j++;
        }

        return max(total_profit, 0);
    }
};