class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        vector<bool> besoegt(n, false);
        vector<vector<int>> adj(n);

        for (int i=0; i<edges.size(); i++)
            {
                int x=edges[i][0];
                int y=edges[i][1];

                adj[x].push_back(y);
                adj[y].push_back(x);
            }

queue<pair<int,int>> nodeAndPrev;   
nodeAndPrev.push({0,-1});           //  prev skal være -1
besoegt[0] = true;                  // marker start som besøgt

while (!nodeAndPrev.empty())
{
    int node = nodeAndPrev.front().first;
    int prev = nodeAndPrev.front().second;
    nodeAndPrev.pop();

    for (int j=0; j<adj[node].size() ; j++)
    {
        int x=adj[node][j];
        if (x == prev)
        continue;      // den kom jeg fra, tag næste nabo
        if (besoegt[x])
        {
            return false;
        }
        besoegt[x]=true;
        nodeAndPrev.push({x,node});
    }
}

int facit=0;

for (int f=0; f<besoegt.size(); f++)
{
    if (besoegt[f]==true)
    {
        facit++;
    }
}

return facit==n;

    }
  
};
