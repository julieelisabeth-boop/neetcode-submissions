class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> map_s;

    if (s.length() != t.length())
    {
        return false;
    }
        for (char c : s)
        {
            map_s[c] += 1;
        }

        for (char c : t)
        {
            if (map_s.find(c)!=map_s.end())
                {
                    map_s[c] -=1;
                }
        }

    for (auto& [key,value] : map_s)
    {
        if (value!=0)
        {
            return false;
        }
    }
    return true;
        
    }
};
