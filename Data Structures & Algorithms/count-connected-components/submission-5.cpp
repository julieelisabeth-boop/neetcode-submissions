
class Solution {
public:
int countComponents(int n, vector<vector<int>>& edges) {

    vector<vector<int>> adj(n);
    vector<bool> besoegt(n, false);
    int counter=0;
    
    for (int i = 0; i < edges.size(); i++)
    {
        int a = edges[i][0];
        int b = edges[i][1];
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int start = 0; start < n; start++)
    {
        if (besoegt[start])
        {
            continue;
        }
        counter++;
        queue<int> koe;
        koe.push(start);
        besoegt[start] = true; 

        while (!koe.empty())
        {
            int x=koe.front();
            koe.pop();

            for (int nabo=0; nabo<adj[x].size(); nabo++)
            {
                int naboen=adj[x][nabo];
                if (besoegt[naboen])
                {
                    continue;
                }
                besoegt[naboen]=true;
                koe.push(naboen);
            }
        }
    }
    // returner tælleren
      return counter;
    }

};