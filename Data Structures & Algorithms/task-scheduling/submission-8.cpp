class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        for (char c : tasks) freq[c - 'A']++;            // tæl hvert bogstav

        int maxFreq  = *max_element(freq, freq + 26);    // flest af ét bogstav
        int countMax = count(freq, freq + 26, maxFreq);  // hvor mange bogstaver har det antal

        int skelet = (maxFreq - 1) * (n + 1) + countMax;
        return max((int)tasks.size(), skelet);
    }
};

