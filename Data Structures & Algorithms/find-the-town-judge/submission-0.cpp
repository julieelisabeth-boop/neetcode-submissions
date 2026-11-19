class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
     
    std::vector<pair<bool,int>> liste(n+1,{false,0});
     //liste med trusted og hvor mange der stoler på den person

    int ai=0; //den som stoler (udelukker automatisk at man er judge)
    int bi=1; //den der stoles på (skal have n-1 antal for at de er judge)
    int facit=-1;

    for (int i=0; i<trust.size();i++)
    {
        int x=trust[i][ai]; //den som stolers tal
        liste[x].first=true; //dens indeks sættes til true
        int y=trust[i][bi]; //den de stoler pås tal
        liste[y].second++; //tæl person de stoler på op
    }

        for (int j=1; j<liste.size(); j++)
        {
            if (liste[j].first) { continue; } // stoler på nogen (true)
            else if(liste[j].second==n-1) //alle andre stoler på ham
            {
                facit=j;
            }

        }

        return facit;
    }
};