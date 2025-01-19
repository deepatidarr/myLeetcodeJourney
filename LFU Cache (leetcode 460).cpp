class LFUCache {
private: 
    int cap, size, minFreq;

    struct Node {
        int key, val, count;
        Node* next; 
        Node* prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
            count = 1;
            next = prev = nullptr;
        }
    };

    struct List {
        int size;
        Node* head;
        Node* tail;

        List() {
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }

        void addFront(Node* node) {
            node->next = head->next;
            node->prev = head;
            head->next->prev = node;
            head->next = node;
            size++;
        }

        void deleteNode(Node* node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            size--;
        }
    };

    map<int, List*> freqList; // frequency -> List
    unordered_map<int, Node*> keyNode; // key -> Node

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
        size = 0;
    }

    void updateFreqList(Node* node) {
        int freq = node->count;
        freqList[freq]->deleteNode(node);
        if (freqList[freq]->size == 0 && minFreq == freq) {
            minFreq++;
        }
        node->count++;
        if (freqList.find(node->count) == freqList.end()) {
            freqList[node->count] = new List();
        }
        freqList[node->count]->addFront(node);
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }
        Node* node = keyNode[key];
        updateFreqList(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreqList(node);
            return;
        }

        if (size == cap) {
            List* l = freqList[minFreq];
            Node* nodeToDelete = l->tail->prev;
            l->deleteNode(nodeToDelete);
            keyNode.erase(nodeToDelete->key);
            delete nodeToDelete;
            size--;
        }

        Node* newNode = new Node(key, value);
        if (freqList.find(1) == freqList.end()) {
            freqList[1] = new List();
        }
        freqList[1]->addFront(newNode);
        keyNode[key] = newNode;
        minFreq = 1;
        size++;
    }
};
