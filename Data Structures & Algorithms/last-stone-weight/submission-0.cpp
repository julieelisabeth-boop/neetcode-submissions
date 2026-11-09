#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // Opret en max-heap og put alle stenene i den på en gang
        // (Standard priority_queue i C++ er automatisk en max-heap)
        priority_queue<int> maxHeap(stones.begin(), stones.end());

        // Bliv ved så længe der er mindst 2 sten tilbage
        while (maxHeap.size() > 1) {
            // Hent den allerstørste sten
            int stone1 = maxHeap.top();
            maxHeap.pop();
            
            // Hent den næststørste sten
            int stone2 = maxHeap.top();
            maxHeap.pop();

            // Hvis de ikke er ens, lægges differencen tilbage i køen
            if (stone1 != stone2) {
                maxHeap.push(stone1 - stone2);
            }
        }

        // Hvis køen er tom, er svaret 0. Ellers returner den sidste sten.
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
