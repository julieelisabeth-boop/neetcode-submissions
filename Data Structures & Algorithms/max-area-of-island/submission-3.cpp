class Solution {
public:

    int udforsk(vector<vector<int>>& grid, int i, int j)
    {
        // uden for gitteret eller ikke land arealet er 0, base case
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1)
        {
            return 0;
        }

        grid[i][j] = 0;     // marker som besøgt så den ikke bliver talt igen

        // denne celle (1) plus arealet fra de fire naboer
        return 1 + udforsk(grid, i + 1, j)     // ned
                 + udforsk(grid, i - 1, j)     // op
                 + udforsk(grid, i, j + 1)     // højre
                 + udforsk(grid, i, j - 1);    // venstre
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int facit = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                facit = max(facit, udforsk(grid, i, j));    // behold den største
            }
        }

        return facit;
    }
};
