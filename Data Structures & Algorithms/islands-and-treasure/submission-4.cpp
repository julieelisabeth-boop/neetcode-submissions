class Solution {
public:
   
    void islandsAndTreasure(vector<vector<int>>& grid) {
    const int INF = 2147483647;
    queue<pair<int,int>> koordinator;

    for (int i=0; i<grid.size();i++)
    {
        for (int j=0; j<grid[0].size();j++)
        {
            if (grid[i][j]==0)
            {
                koordinator.push({i,j}); //lig alle 0'er ind
            }
        }
    }

    while (!koordinator.empty())
    {
        pair<int,int> par;
        par=koordinator.front();
        koordinator.pop();
        int i=par.first;
        int j=par.second;
        
        if (i + 1 < grid.size() && grid[i+1][j] == INF)
        {
            grid[i+1][j] = grid[i][j] + 1;  // naboen skal have din aftsand +1
            koordinator.push({i + 1, j});       // læg den i køen
        }


        if (i - 1 >= 0 && grid[i-1][j] == INF)
        {
        grid[i-1][j]=grid[i][j]+1; //tæl op på pladsen af de koordinator
        koordinator.push({i-1,j}); //sæt det nye tal bag køen fx 1 efter første loop
        }

        if (j + 1 < grid[0].size() && grid[i][j+1] == INF)
        {
            grid[i][j+1] = grid[i][j] + 1;      // afstanden en mere end mig
            koordinator.push({i, j+1});       // læg den i køen
        }

        if (j - 1 >= 0 && grid[i][j-1] == INF)
        {
            grid[i][j-1] = grid[i][j] + 1;      // afstanden en mere end mig
            koordinator.push({i, j-1});       // læg den i køen
        }
    }
    }  
};
