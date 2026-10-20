class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> s;
        int fleet = 0;
        vector<pair<int,int>> fartpos;
        for (int i = 0; i < position.size(); i++)
        {
            fartpos.push_back({position[i], speed[i]});
        }
        sort(fartpos.begin(), fartpos.end());
        for (int j = fartpos.size() - 1; j >= 0; j--)
        {
            double tid = (double)(target - fartpos[j].first) / fartpos[j].second;
            if (s.empty() || tid > s.top())
            {
                fleet++;
                s.push(tid);
            }
        }
        return fleet;
    }
};