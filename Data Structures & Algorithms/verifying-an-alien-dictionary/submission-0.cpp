class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        for (int i=0; i<words.size()-1; i++) //for hvert ord
        {
            string a=words[i]; //et ord
            string b=words[i+1]; //ordet efter vi sammenligner med
            bool fundet=false;

            for (int j=0; j<a.size() && j<b.size(); j++) //for hvert bogstav (char)
            {
                if (a[j]==b[j]) {continue;}

                int findA = order.find(a[j]);
                int findB = order.find(b[j]);

                if (findA>findB) {return false;}
                fundet = true; //Der er fundet en forskel men rækkefølge er ok
                break; //videre til næste bogstav
            }

            //ekstra tjek til hvis alle ord var det samme men a bare var kortere
            if (fundet==false && a.size()>b.size())
            {
                return false;
            }
        }
        return true;
    }
};