class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> map;
        for (auto &s :strs)
        {
            std::string sorted=s;
            sort(sorted.begin(), sorted.end());
            map[sorted].push_back(s);
        }

    vector<vector<string>> resultat;
    for (auto &m : map)
    {
        resultat.push_back(m.second);
    }
    return resultat;
    }
};
