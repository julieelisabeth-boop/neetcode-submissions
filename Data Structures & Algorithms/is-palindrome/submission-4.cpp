class Solution {
public:
    bool isPalindrome(string s) {
    int left=0;
    int right=s.size()-1; //sidtse indeks

        while (left < right)
        {
            if (!isalnum(s[left]))   // ikke et bogstav eller tal?
            {
                left++;              // spring det over
                continue;            // tjek løkkens betingelse igen og prøv forfra
            }

            if (!isalnum(s[right]))   // ikke et bogstav eller tal?
            {
                right--;              // spring det over
                continue;            // tjek løkkens betingelse igen og prøv forfra
            }


            if (tolower(s[left])!=tolower(s[right]))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
