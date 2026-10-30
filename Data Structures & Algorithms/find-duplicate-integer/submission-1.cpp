class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        int hurtig = 0;
        int langsom = 0;

        // 1. Find et mødested inde i ringen
        do
        {
            langsom = nums[langsom];        // 1 skridt
            hurtig = nums[nums[hurtig]];    // 2 skridt
        } while (langsom != hurtig);

        // 2. Find indgangen til ringen
        int start2 = 0;
        while (start2 != langsom)
        {
            langsom = nums[langsom];
            start2 = nums[start2];
        }

        // 3. Indgangen er dubletten
        return langsom;
    }
};
