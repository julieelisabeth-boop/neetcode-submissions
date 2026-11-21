class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        queue<pair<int,int>> koordinator;
        int friske = 0;
        int minutes = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 2)
                {
                    koordinator.push({i, j}); // smid alle de rådne i køen
                }
                else if (grid[i][j] == 1) friske++; // hold styr på om der stadig er friske
            }
        }

        while (!koordinator.empty() && friske > 0)
        {
            int n = koordinator.size(); // antal rådne ved starten af dette minut

            for (int k = 0; k < n; k++)
            {
                pair<int,int> par = koordinator.front();
                koordinator.pop();
                int first = par.first;
                int second = par.second;

                if (first-1 >= 0 && grid[first-1][second] == 1) // op
                {
                    grid[first-1][second] = 2;
                    koordinator.push({first-1, second});
                    friske--;
                }
                if (first+1 < grid.size() && grid[first+1][second] == 1) // ned
                {
                    grid[first+1][second] = 2;
                    koordinator.push({first+1, second});
                    friske--;
                }
                if (second+1 < grid[0].size() && grid[first][second+1] == 1) // højre
                {
                    grid[first][second+1] = 2;
                    koordinator.push({first, second+1});
                    friske--;
                }
                if (second-1 >= 0 && grid[first][second-1] == 1) // venstre
                {
                    grid[first][second-1] = 2;
                    koordinator.push({first, second-1});
                    friske--;
                }
            }
            minutes++; // et helt lag er færdigt = ét minut
        }

        if (friske > 0) return -1;
        return minutes;
    }
};