 vector<int> leftRight(vector<int> nums)
        {
            vector<int> kladde(nums.size());
            int sum=1;
            for (int i=0; i < nums.size();i++)
            {
                kladde[i]=sum;
                sum=sum*nums[i];
            }
            return kladde;
        }
    vector<int> rightLeft(vector<int> nums)
        {
            vector<int> kladde(nums.size());
            int sum=1;
            for (int i=nums.size()-1; i>=0; i--)
            {
                kladde[i]=sum;
                sum=sum*nums[i];
            }
            return kladde;
        }

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> left = leftRight(nums);
        vector<int> right = rightLeft(nums);
        vector<int> sum(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            sum[i] = left[i] * right[i];
        }
        return sum;
    }
};

