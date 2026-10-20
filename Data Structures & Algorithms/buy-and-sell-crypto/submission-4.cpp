class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int right=1;
    int left=0;
    int max=0;
    
    
    while (right < prices.size())
    {
        if (prices[right]<prices[left])
        {
            left=right;
        }
        int profit=prices[right]-prices[left];

        if (profit>max)
            {
                max=profit;
            }
            right++;
    }

    return max;
    }
};
