class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;

        int buy = 0;
        int sell = buy + 1;
        while (sell < prices.size()) {
            max_profit = max(max_profit, prices[sell] - prices[buy]);
            if (prices[buy] <= prices[sell]) sell++;
            else buy = sell++;
        }
        return max_profit;
    }
};
