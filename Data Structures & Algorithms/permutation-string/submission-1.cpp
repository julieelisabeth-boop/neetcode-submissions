class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
    vector<int> c1(26, 0);
    vector<int> c2(26, 0);
    int n = s1.size();

    for (char c : s1)
    {
        c1[c - 'a']++;
    }
    
    int left=0;
    for (int right = 0; right < s2.size(); right++)
    {
       c2[s2[right]-'a']++;

       if (right-left+1==n)
       {
            if (c1==c2)
            {
                return true;
            }
        c2[s2[left]-'a']--;
        left++;
       }
    }
    return false;
    }
};
