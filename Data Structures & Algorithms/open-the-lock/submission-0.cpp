class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        
        unordered_set<string> forbudt(deadends.begin(), deadends.end());
        queue<pair<string,int>> koe;

        if (forbudt.count("0000")) {return -1;}  // start er selv forbudt

        koe.push({"0000",0}); //sæt i kø
        forbudt.insert("0000");                 // marker som besøgt

        while (!koe.empty())
        {
        pair<string,int> front=koe.front();
        std::string first=front.first;
        int second=front.second;
        koe.pop();
            if (first==target)
            {
                return second;
            }

        for (int i=0; i<first.size(); i++) //vi arbjeder påp de indivudelle hjule:
            {
                string op = first; //op er en kopi af den kode fra vores queue
                if (first[i]=='9')
                {op[i]='0';} //så drejer vi om til nul
                else
                op[i]=first[i]+1; //lig 1 til det hjul vi drejer på lige nu

            if (!forbudt.count(op)) //findes op i vores forbundet set liste?
            {
                forbudt.insert(op); //hvis ik så tilføjer vi den til listen og queue
                koe.push({op,second+1});
            }

                string ned = first; // kan vi dreje hjulet ned?
                if (first[i]=='0')
                {ned[i]='9';} 
                else
                ned[i]=first[i]-1; 

            if (!forbudt.count(ned)) //findes op i vores forbundet set liste?
            {
                forbudt.insert(ned); //hvis ik så tilføjer vi den til listen og queue
                koe.push({ned,second+1});
            }
            }
        }
        return -1;
    }
};