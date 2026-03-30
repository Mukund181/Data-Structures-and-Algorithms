#include <iostream>
#include <vector>
using namespace std;

// Application: Quadratic probing uses quadratic steps to reduce clustering in hash tables, improving performance in open addressing for problems like database indexing.

class HashTable {
    vector<int> table;
    int size;
    int EMPTY = -1;
    int DELETED = -2;
public:
    HashTable(int s) {
        size = s;
        table.assign(size, EMPTY);
    }

    int hash(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hash(key);
        int i = 0;
        while(table[(index + i*i) % size] != EMPTY && table[(index + i*i) % size] != DELETED && table[(index + i*i) % size] != key) {
            i++;
            if(i == size) return; // Table full
        }
        table[(index + i*i) % size] = key;
    }

    bool search(int key) {
        int index = hash(key);
        int i = 0;
        while(table[(index + i*i) % size] != EMPTY) {
            if(table[(index + i*i) % size] == key) return true;
            i++;
            if(i == size) break;
        }
        return false;
    }

    void remove(int key) {
        int index = hash(key);
        int i = 0;
        while(table[(index + i*i) % size] != EMPTY) {
            if(table[(index + i*i) % size] == key) {
                table[(index + i*i) % size] = DELETED;
                return;
            }
            i++;
            if(i == size) break;
        }
    }

    void display() {
        for(int i = 0; i < size; i++) {
            if(table[i] == EMPTY) cout << i << ": EMPTY" << endl;
            else if(table[i] == DELETED) cout << i << ": DELETED" << endl;
            else cout << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    HashTable ht(5);
    ht.insert(10);
    ht.insert(15);
    ht.insert(20);
    ht.insert(10); // Duplicate

    cout << "Hash Table after inserts:" << endl;
    ht.display();

    cout << "Search 15: " << (ht.search(15) ? "Found" : "Not Found") << endl;
    cout << "Search 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;

    ht.remove(15);
    cout << "After remove 15:" << endl;
    ht.display();

    return 0;
}