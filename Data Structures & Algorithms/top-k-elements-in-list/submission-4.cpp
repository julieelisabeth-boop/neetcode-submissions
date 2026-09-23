class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> map;
        for (auto &n : nums)
        {
            map[n]++;
        }

    vector<vector<int>> buckets(nums.size()+1);
    vector<int> res;
        for (auto &m : map)
        {
            buckets[m.second].push_back(m.first);
        }

    for (int i=buckets.size()-1; i>=0 && res.size() < k; i--)
    {
        for (int num : buckets[i])
        {
            res.push_back(num);
            if (res.size() == k) break;
        }
    }

    return res;
    }
};
