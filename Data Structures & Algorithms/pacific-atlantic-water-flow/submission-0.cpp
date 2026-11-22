class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        vector<vector<int>> facit;
        int rows = heights.size();
        int cols = heights[0].size();

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                vector<vector<bool>> visitedP(rows, vector<bool>(cols, false));
                vector<vector<bool>> visitedA(rows, vector<bool>(cols, false));

                if (Pacific(heights, i, j, visitedP) && Atlantic(heights, i, j, visitedA))
                {
                    facit.push_back({i, j});
                }
            }
        }
        return facit;
    }

    bool Pacific(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited)
    {
        if (i == 0 || j == 0) return true;   // rører Pacific (øverst eller venstre)

        visited[i][j] = true;
        int rows = heights.size();
        int cols = heights[0].size();

        // op
        if (i-1 >= 0 && !visited[i-1][j] && heights[i-1][j] <= heights[i][j] && Pacific(heights, i-1, j, visited))
            return true;
        // ned
        if (i+1 < rows && !visited[i+1][j] && heights[i+1][j] <= heights[i][j] && Pacific(heights, i+1, j, visited))
            return true;
        // venstre
        if (j-1 >= 0 && !visited[i][j-1] && heights[i][j-1] <= heights[i][j] && Pacific(heights, i, j-1, visited))
            return true;
        // højre
        if (j+1 < cols && !visited[i][j+1] && heights[i][j+1] <= heights[i][j] && Pacific(heights, i, j+1, visited))
            return true;

        return false;  
    }

    bool Atlantic(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& visited)
    {
        int rows = heights.size();
        int cols = heights[0].size();

        if (i == rows-1 || j == cols-1) return true;   // rører Atlantic (nederst eller højre)

        visited[i][j] = true;

        // op
        if (i-1 >= 0 && !visited[i-1][j] && heights[i-1][j] <= heights[i][j] && Atlantic(heights, i-1, j, visited))
            return true;
        // ned
        if (i+1 < rows && !visited[i+1][j] && heights[i+1][j] <= heights[i][j] && Atlantic(heights, i+1, j, visited))
            return true;
        // venstre
        if (j-1 >= 0 && !visited[i][j-1] && heights[i][j-1] <= heights[i][j] && Atlantic(heights, i, j-1, visited))
            return true;
        // højre
        if (j+1 < cols && !visited[i][j+1] && heights[i][j+1] <= heights[i][j] && Atlantic(heights, i, j+1, visited))
            return true;

        return false;   // ingen vej fandt Atlantic
    }
};
