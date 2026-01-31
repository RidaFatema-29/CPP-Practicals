#include <iostream>
#include <list>
using namespace std;

#define BUCKET 7        // fixed size hash table
list<int> hashTable[BUCKET];

// Hash function
int hashFunction(int key) {
    return key % BUCKET;
}

// Insert key
void insertItem(int key) {
    int index = hashFunction(key);
    hashTable[index].push_back(key);
}

// Delete key
void deleteItem(int key) {
    int index = hashFunction(key);
    
    for (auto it = hashTable[index].begin(); it != hashTable[index].end(); it++) {
        if (*it == key) {
            hashTable[index].erase(it);
            break;
        }
    }
}

// Display table
void displayHash() {
    for (int i = 0; i < BUCKET; i++) {
        cout << i;
        for (int x : hashTable[i]) {
            cout << " --> " << x;
        }
        cout << endl;
    }
}

int main() {

    insertItem(15);
    insertItem(11);
    insertItem(27);
    insertItem(8);
    insertItem(12);
    insertItem(22);

    cout << "\nHash Table:\n";
    displayHash();

    deleteItem(12);
    deleteItem(15);

    cout << "\nAfter Deletion:\n";
    displayHash();

    return 0;
}
