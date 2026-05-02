/* LRU Cache Approach -
  Use a Hash Map and a Doubly Linked List.
  Map stores Key -> Node pointer.
  DLL keeps track of most recently used (head) and least recently used (tail).
  When accessing/updating, move node to head. When capacity is full, remove tail.
*/
#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache {
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };
    
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void insertHead(Node* node) {
        node->next = head->next;
        node->next->prev = node;
        head->next = node;
        node->prev = head;
    }
    
public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node* resNode = cache[key];
            removeNode(resNode);
            insertHead(resNode);
            return resNode->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            Node* existNode = cache[key];
            cache.erase(key);
            removeNode(existNode);
        }
        if(cache.size() == capacity) {
            cache.erase(tail->prev->key);
            removeNode(tail->prev);
        }
        insertHead(new Node(key, value));
        cache[key] = head->next;
    }
};

// time complexity - O(1) for get and put
int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << "Get 1: " << lru.get(1) << endl;
    lru.put(3, 3);
    cout << "Get 2: " << lru.get(2) << endl;
    return 0;
}
