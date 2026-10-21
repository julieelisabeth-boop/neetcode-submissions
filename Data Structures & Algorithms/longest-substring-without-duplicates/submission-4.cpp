class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
    map<char, int> sub;
    int max=0;
    int left=0;

    for (int right = 0; right < s.size(); right++)
    { 
        auto resultat = sub.insert({s[right], right});
        if (!resultat.second) // tegnet fandtes allerede
        {
            int gammel = resultat.first->second; // det gamle indeks
            if (gammel >= left) //If’en svarer kun på et spørgsmål: er det en rigtig dublet, eller er det bare mappet, der husker noget gammelt?
            {
                left=gammel+1; //den nye left er nu doubletens indeks +1
            } 
            resultat.first->second = right;
            // overskriver det gammle doubvlet indeks med det nye
        }
        int lengde = right - left + 1;
        if (lengde > max)
        {
            max = lengde;
        }
    }
      return max;
    }
};
