class LRUCache {
private:
    struct Node {
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> map;  // key → pointer til knuden
    Node* head;                     // hjælpenode: lige efter den ligger den nyeste
    Node* tail;                     // hjælpenode: lige før den ligger den ældste

    // hægt en knude ud af listen
    void fjern(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // sæt en knude ind forrest (lige efter head)
    void saetForrest(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (map.find(key) == map.end())  // key findes ikke
            return -1;

        Node* node = map[key];           // find adressen til knuden
        fjern(node);                     // den er lige brugt, så den flyttes forrest
        saetForrest(node);
        return node->val;
    }

    void put(int key, int value) {
        if (map.find(key) != map.end()) {  // key findes allerede: opdater og flyt forrest
            Node* node = map[key];
            node->val = value;
            fjern(node);
            saetForrest(node);
            return;
        }

        if ((int)map.size() == capacity) { // fuld: smid den ældste ud
            Node* aeldst = tail->prev;
            fjern(aeldst);
            map.erase(aeldst->key);        // derfor skal knuden kende sin key
            delete aeldst;
        }

        Node* ny = new Node(key, value);   // ny knude forrest
        saetForrest(ny);
        map[key] = ny;
    }
};