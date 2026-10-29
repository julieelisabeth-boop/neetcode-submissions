/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:


Node* copyRandomList(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }

    unordered_map<Node*, Node*> tabel;
    Node* curr = head;

    // 1. Lav en kopi af hver knude og husk parret: original -> kopi
    while (curr != nullptr)
    {
        Node* p = new Node(curr->val);
        tabel[curr] = p;
        curr = curr->next;
    }

    // 2. Sæt next og random på hver kopi ved at slå op i tabellen
    for (auto& par : tabel)
    {
        Node* orginal = par.first;
        Node* ny = par.second;
        Node* nxt = orginal->next;
        Node* rnd = orginal->random;

        if (nxt != nullptr)
        {
            ny->next = tabel[nxt];
        }
        if (rnd != nullptr)
        {
            ny->random = tabel[rnd];
        }
    }

    // 3. Returner kopien af head
    return tabel[head];
}
};
