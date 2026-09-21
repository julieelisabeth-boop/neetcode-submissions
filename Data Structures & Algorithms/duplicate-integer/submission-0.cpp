class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> hashmap;
    for (auto n: nums)
    {
    if (hashmap.find(n) !=hashmap.end())
    return true;
        hashmap[n]=1;
    }
    return false;
    }
};