class Solution {
public:
    void solve(vector<vector<char>>& board) {
  
    vector<vector<bool>> safe(board.size(), vector<bool>(board[0].size(),false));
    queue<pair<int,int>> kor;


    for (int i = 0; i < board.size(); i++)
{
    for (int j = 0; j < board[0].size(); j++)
    {
        if (i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1)
        {
            if (board[i][j] == 'O')
            {
                kor.push({i, j});
                safe[i][j]=true;
            }
        }
    }
}

    while(kor.size()!=0)
    {
        pair<int,int> front;
        front=kor.front();
        kor.pop();
        int i=front.first;
        int j=front.second;

        if (i-1>=0 && board[i-1][j]=='O' && !safe[i-1][j]) //op
        {
            safe[i-1][j]=true;
            kor.push({i-1,j});
        }
        if (j-1>=0 && board[i][j-1]=='O' && !safe[i][j-1]) //venstre
        {
            safe[i][j-1]=true;
            kor.push({i,j-1});
        }
         if (i+1<board.size() && board[i+1][j]=='O' && !safe[i+1][j]) //ned
        {
            safe[i+1][j]=true;
            kor.push({i+1,j});
        }
         if (j+1<board[0].size() && board[i][j+1]=='O' && !safe[i][j+1]) //højre
        {
            safe[i][j+1]=true;
            kor.push({i,j+1});
        }

    }

    for (int i=0; i<board.size(); i++)
    {
        for (int j=0; j<board[0].size();j++)
        {
            if (safe[i][j]==false)
            {
                board[i][j]='X';
            }
        }
    }
    }

};
