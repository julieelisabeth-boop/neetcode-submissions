class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int best = 0;                                  // bedste hidtil, starter på 0

        while (left < right) {
            int bredde = right - left;
            int hojde = min(heights[left], heights[right]);   // den korteste søjle
            best = max(best, bredde * hojde);                 // gem, hvis bedre

            if (heights[left] < heights[right])
                left++;                                // flyt den korte
            else
                right--;
        }
        return best;
    }
};
