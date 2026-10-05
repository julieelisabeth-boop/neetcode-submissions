class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

      vector<vector<int>> facit;
      sort(nums.begin(), nums.end());

      for (int i = 0; i < (int)nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) //hvis i er det smamew tal som før, spring over
            {
                continue;
            }
            int j = i + 1;
            int k = nums.size()-1;

            while (j<k)
            {
                if (nums[j]+nums[k]==-nums[i])
                {
                    facit.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while (j < k && nums[j] == nums[j - 1])   // spring dubletter af j over
                    {
                        j++;
                    }
                }
                else if (nums[j] + nums[k] < -nums[i])
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }

        }
            return facit;
    }
};
