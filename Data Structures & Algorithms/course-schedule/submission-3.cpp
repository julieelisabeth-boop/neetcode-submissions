class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // alle jeg peger på
        vector<int> ind(numCourses,0); // alle der peger på mig
        queue<int> koe;
        int taget=0;

        for (int i = 0; i < prerequisites.size(); i++)
        {
            int a = prerequisites[i][0];   // a: den der venter på dne inden er taget: [a,b] a venter på b bliver taget
            int b = prerequisites[i][1];   // b: den der skal tages først: (b->a) 

            adj[b].push_back(a);           // b peger på a : adj[0].push_back(a), adj er hvem jeg peger på
            ind[a]++;                      // a har fået en vej ind mere, holder styr på hvor mange der skal igennem min vej
        }

        for (int j=0; j<ind.size(); j++)
        {
            if (ind[j]==0)
            {
                koe.push(j); //kø bliver fyldt med de tal som ikke bliver peget på (de venter ik på nogen fag)
            }
        }

        while (!koe.empty())
            {
                int tal=koe.front(); //tag det tal ingen pegede på
                koe.pop();
                taget++;
                vector<int> facit=adj[tal]; //kig på hvad det tal pegede på, det kan vrære mange tal derfor vector

               for (int k = 0; k < facit.size(); k++)
                {
                    int nabo = facit[k]; //kig på en af de tal den pegede på, det en nabo
                    ind[nabo]--; //den nabo har nu en færre vej til sig vi behøver undersøge
                    if (ind[nabo] == 0) //hvis de nu er 0 veje vi mangler at undersøge
                        koe.push(nabo); //sæt det her tal i køen
                }
        }
        
        return taget == numCourses;

    }
};
