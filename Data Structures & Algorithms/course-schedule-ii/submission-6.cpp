class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> peger(numCourses);   // hvem peger jeg på
        vector<int> ind(numCourses, 0);          // hvor mange peger på mig
        queue<int> done; //de kursuser der frit kan tages
        vector<int> facit;

        for (int i=0; i<prerequisites.size(); i++)
        {
            int a=prerequisites[i][0];
            int b=prerequisites[i][1];
            peger[b].push_back(a); // (a,b) a venter på b, så b->a
            ind[a]++; // der er en som peger på mig
        }

        for (int j=0; j<ind.size(); j ++)
        {
            if (ind[j]==0)
            {
                done.push(j); //det her kursus kan klares med det samme
            }
        }

        while (!done.empty())
        {
            int j=done.front(); //det kursus vi kan færdiggøre
            facit.push_back(j); //facit starter med dem her
            done.pop();

            for (int k=0; k<peger[j].size(); k++) //alle dem det kursus "unlocker"
            {
                int a=peger[j][k]; //det kursus jeg pegr
                ind[a]--; //træk en fra det kursus
                if (ind[a]==0) //hvis det kursus nu kan tilgås
                {
                done.push(a);  //lig det i queue
                }
            }
        }
        if (facit.size()>=numCourses)
        {
        return facit;
        }
        else
        return {};
    }
};
