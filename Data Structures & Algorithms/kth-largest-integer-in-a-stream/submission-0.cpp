#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : k(k) {
        // Tilføj alle elementer fra nums via add-funktionen
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        // Tilføj det nye tal til vores min-heap
        minHeap.push(val);
        
        // Hvis heapen bliver større end k, fjerner vi det mindste element,
        // så vi kun bevarer de k største elementer.
        if (minHeap.size() > k) {
            minHeap.pop(); //fjerner fra toppen (det mindste tal)
        }
        
        // Toppen af min-heapen er nu det k-te største element
        return minHeap.top(); // fx hvis KthLargest(int k, vector<int>& nums) med k=3 kan que se sådna her ud (3,4,5), så er k=3
    }

private:
    // En min-heap i C++ (gør at det mindste element altid er øverst)
    priority_queue<int, vector<int>, greater<int>> minHeap; //greater<int> betyder: Er det næste tal større end det forrige?" (a > b).
    int k;
};
