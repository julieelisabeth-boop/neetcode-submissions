class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Vi bruger en max-heap. Standard priority_queue i C++ er en max-heap.
        // Vi gemmer et pair: {distance_kvadrat, punkt_koordinater}
        priority_queue<pair<int, vector<int>>> maxHeap;
        
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            
            // Beregn x^2 + y^2 (vi skipper sqrt, da det ikke ændrer rækkefølgen)
            int dist_squared = x * x + y * y;
            
            // Push parret til vores max-heap
            maxHeap.push({dist_squared, points[i]});
            
            // Hvis heapen bliver større end k, popper vi det punkt, der er LÆNGST væk
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        // Hent de k tætteste punkter ud af heapen og overfør til resultatet
        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second); // .second er selve vector<int> (punktet)
            maxHeap.pop();
        }
        
        return result;
    }
};