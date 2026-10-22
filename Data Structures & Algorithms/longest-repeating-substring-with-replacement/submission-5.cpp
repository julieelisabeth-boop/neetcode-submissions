class Solution {
public:
    int characterReplacement(string s, int k) {
        int antal[26] = {0};
        int left = 0;
        int flest = 0; //flest antal i et vindue
        int bedst = 0;

        for (int right = 0; right < s.size(); right++)
        {
            char c = s[right];
            antal[c - 'A'] += 1;
            flest = max(flest, antal[c - 'A']);

            int lenge = right - left + 1;
            if (lenge - flest > k) // for mange erstatninger
            {
                antal[s[left] - 'A'] -= 1; // smid bogstavet til venstre ud
                left += 1;
            }

            lenge = right - left + 1;
            if (lenge > bedst)
            {
                bedst = lenge;
            }
        }

        return bedst;
    }
};
