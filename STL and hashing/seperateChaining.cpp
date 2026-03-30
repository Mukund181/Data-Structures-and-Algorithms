#include <iostream>
#include <list>
#include <vector>
using namespace std;

// Application: Separate chaining is used in hash tables to handle collisions by chaining elements in lists, solving problems like fast lookups in dictionaries or caches.

class HashTable {
    vector<list<int>> table;
    int size;
public:
    HashTable(int s) {
        size = s;
        table.resize(size);
    }

    int hash(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hash(key);
        // Check if already exists
        for(auto it = table[index].begin(); it != table[index].end(); it++) {
            if(*it == key) return; // No duplicates
        }
        table[index].push_back(key);
    }

    bool search(int key) {
        int index = hash(key);
        for(auto it = table[index].begin(); it != table[index].end(); it++) {
            if(*it == key) return true;
        }
        return false;
    }

    void remove(int key) {
        int index = hash(key);
        table[index].remove(key); // STL list remove
    }

    void display() {
        for(int i = 0; i < size; i++) {
            cout << i << ": ";
            for(auto it = table[i].begin(); it != table[i].end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable ht(5);
    ht.insert(10);
    ht.insert(15);
    ht.insert(20);
    ht.insert(25);
    ht.insert(10); // Duplicate, ignored

    cout << "Hash Table after inserts:" << endl;
    ht.display();

    cout << "Search 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Search 30: " << (ht.search(30) ? "Found" : "Not Found") << endl;

    ht.remove(15);
    cout << "After remove 15:" << endl;
    ht.display();

    return 0;
}