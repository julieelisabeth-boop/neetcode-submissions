class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> set;
        int Max=0;
        for (auto n : nums)
        {
            set.insert(n);
        }

        for (int i=0; i<nums.size(); i++)
        {
            if (set.count(nums[i]-1)) //hvis den værdi som er x-1 findes
            {
                continue; // gå videre
            }
            else
            {
                int count=1;
                while (true)
                {
                    if (set.count(nums[i]+count))
                    {
                        count++;
                    }
                    else {break;}
                }
                    if (count>Max)
                    {
                        Max=count;
                    }
                }
            }
         
    return Max;
    }
};
