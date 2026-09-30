class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {


     for (int i=0; i<board.size(); i++)
     {
        unordered_set<char> vandret(board.size());
        for (int j=0; j<board[i].size(); j++)
        {
        if (board[i][j] == '.') continue;   // tjekker for tom char
        if (vandret.count(board[i][j])) //hvis det allerede findes
        {
           return false;
        }
        else 
        {
            vandret.insert(board[i][j]);
        } // ellers insert
        
        }
     }
     for (int j=0; j<board.size(); j++)
     {
        unordered_set<char> lodret(board.size());
        for (int i=0; i<board[j].size(); i++)
        {
        if (board[i][j] == '.') continue;   // tjekker for tom char
        if (lodret.count(board[i][j])) //hvis det allerede findes
        {
           return false;
        }
        else 
        {
            lodret.insert(board[i][j]);
        } // ellers insert
        
        }
     }
   
    for (int boxRow=0; boxRow < 9; boxRow+=3) //start rækker 0,3,6
    {
        for(int boxCol=0; boxCol < 9; boxCol+=3) // start kolloner
        {
            unordered_set<char> box;
            for (int i=boxRow; i<boxRow+3; i++)
            {
                for(int j=boxCol; j<boxCol+3;j++)
                {
                    if (board[i][j] == '.') continue;
                    if (box.count(board[i][j])) //hvis det allerede findes
                    {
                    return false;
                    }
                    else 
                    {
                    box.insert(board[i][j]);
                    } // ellers insert
                }
            }
        }
    }
   
 return true;
    }
};
