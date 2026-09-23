class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int counter1=0;
        vector<int> facit;
        unordered_map<int,int> map;
        
        for (auto n: nums)
        {
        int complement = target - n;
            if (map.find(complement)!=map.end())
            {
                facit.push_back(map[complement]);
                facit.push_back(counter1);
                return facit;
            }
            map.insert({n,counter1});
            counter1++;
        }
    }
};
