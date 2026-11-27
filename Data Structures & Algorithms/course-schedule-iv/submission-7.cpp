class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {

        vector<vector<int>> adj(numCourses);
        vector<vector<bool>> omvej(numCourses, vector<bool>(numCourses, false));

        for (int i=0; i<prerequisites.size(); i++)
        {
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];

            adj[a].push_back(b);
        } 

        for (int start = 0; start < numCourses; start++) //start er alle noderne numCourses-1
        {
            queue<int> koe;      // ny, tom kø hver gang
            koe.push(start);     // kun den ene node

            while (!koe.empty())
            {
                int node = koe.front();
                koe.pop();
                for (int k=0; k<adj[node].size(); k++)
                {
                    int nabo = adj[node][k];
                    if (omvej[start][nabo]!=true)
                    {
                        omvej[start][nabo]=true;
                        koe.push(nabo); //lig nabo i køen så vi bagefter undersøger hvor du kan nå fra k
                    }
                }
            }
        }

    vector<bool> facit;
        for (int k=0; k<queries.size(); k++)
        {
            int x=queries[k][0];
            int y=queries[k][1];
            if (omvej[x][y]!=true)
            {
            facit.push_back(false);
            }
            else if (omvej[x][y]==true)
            {
            facit.push_back(true);
            }
        }
        

    return facit;
    }
        
    };
