class Solution {
public:

    void udforsk(vector<vector<char>>& grid, int i, int j)
    {
        // uden for gitteret, eller ikke land, det er base case stoop
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1')
        {
            return;
        }

        grid[i][j] = '0'; // marker som besøgt, så øen bliver "slettet"

        udforsk(grid, i + 1, j);       // ned
        udforsk(grid, i - 1, j);       // op
        udforsk(grid, i, j + 1);       // højre
        udforsk(grid, i, j - 1);       // venstre
    }

    int numIslands(vector<vector<char>>& grid) {
        int facit = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    facit++;                // en ny ø
                    udforsk(grid, i, j);    // slet hele øen
                }
            }
        }
        return facit;
    }
};