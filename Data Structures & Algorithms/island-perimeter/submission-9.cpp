class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
//kig på alle enklete ø'er, hver nabo den har give -1 i perimeter, har den 4 naboer har den 0 perimeter
   
        int rowMax = grid.size();        // antal rækker
        int colMax = grid[0].size();     // antal kolonner (længden af en række)
        int Peri=0;

        for (int i=0; i<rowMax;i++)
        {
            for (int j=0; j<colMax;j++)
            {
                if (grid[i][j]==0) {continue;}

                if (i+1>=rowMax || grid[i+1][j]!=1) //tjek ø til højre
                {
                    Peri++;
                }
                if (i==0 || grid[i-1][j]!=1) //tjek ø til venstre
                {
                    Peri++;
                }
                if (j==0 || grid[i][j-1]!=1) //tjek ø under
                {
                    Peri++;
                }
                if (j+1>=colMax || grid[i][j+1]!=1) //tjek ø over
                {
                    Peri++;
                }

            }
        }

        return Peri;
    }
};