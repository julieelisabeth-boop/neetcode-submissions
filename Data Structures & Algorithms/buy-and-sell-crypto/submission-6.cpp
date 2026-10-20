class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = prices[0];
        int best = 0;
        for (int price : prices)
        {
            lowest = min(lowest, price);
            best = max(best, price - lowest);
        }
        return best;
    }
};