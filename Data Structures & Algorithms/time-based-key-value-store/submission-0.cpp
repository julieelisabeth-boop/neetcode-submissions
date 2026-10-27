class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
       map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        auto& v = map[key];   // listen for denne key (en reference, så den ikke kopieres)
        int left = 0;
        int right = (int)v.size() - 1;       // sidste plads. Er listen tom, bliver right -1
        string kandidat = "";

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (v[mid].first <= timestamp) // v[mid] er et par: .first = tidspunkt, .second = værdi
            {
                kandidat=v[mid].second;
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }

        return kandidat;
        
        // 1. find vektoren for key (findes den ikke: return "")
        // 2. halvér på .first (tidspunktet):
        //    - .first <= timestamp: gem .second som kandidat, kig til højre
        //    - .first >  timestamp: kig til venstre
        // 3. return kandidaten (ingen kandidat = "")
    }

    private:
    unordered_map<string, vector<pair<int,string>>> map;
};
