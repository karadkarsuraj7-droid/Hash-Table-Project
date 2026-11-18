#include <iostream>
using namespace std;

#define TABLE_SIZE 23
#define DATA_SIZE 20

// Node for separate chaining (linked list)
struct Node {
    int key;
    Node* next;
    Node(int k) : key(k), next(NULL) {}
};

class HashTable {
private:
    Node* table[TABLE_SIZE];

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }

    // Mid-Square Method Hash Function
    int hashFunction(int key) {
        int square = key * key;                 // Step 1: square the key
        int middle = (square / 10) % 100;       // Steps 2-3: middle two digits of 4-digit square
        return middle % TABLE_SIZE;             // Step 4: remainder after dividing by 23
    }

    // Insert using Separate Chaining (append at end of chain)
    void insert(int key) {
        int index = hashFunction(key);
        Node* newNode = new Node(key);
        bool collision = (table[index] != NULL);

        if (table[index] == NULL) {
            table[index] = newNode;
        } else {
            Node* temp = table[index];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }

        cout << "Inserted " << key << " at index " << index;
        if (collision) cout << " (Collision - added to chain)";
        cout << endl;
    }

    // Display Hash Table
    void display() {
        cout << "\nFinal Hash Table\n";
        cout << "-------------------------\n";
        cout << "Index\tLinked List\n";

        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << "\t";

            if (table[i] == NULL) {
                cout << "EMPTY";
            } else {
                Node* temp = table[i];
                while (temp != NULL) {
                    cout << temp->key;
                    if (temp->next != NULL) cout << " -> ";
                    temp = temp->next;
                }
            }
            cout << endl;
        }
    }
};

int main() {

    HashTable ht;
    int S = 173;
    int values[DATA_SIZE];

    // Personalized dataset: V[i] = (S + 13 * i) mod 100
    for (int i = 0; i < DATA_SIZE; i++) {
        values[i] = (S + 13 * i) % 100;
    }

    cout << "DATA STRUCTURES INTERNAL ACTIVITY 3\n";
    cout << "PRN: 202501100173\n";
    cout << "Scenario: Student Marks\n";
    cout << "Hashing: Mid-Square Method\n";
    cout << "Collision Handling: Separate Chaining\n";
    cout << "Table Size: " << TABLE_SIZE << endl;

    cout << "\nInsertion Process\n";
    cout << "-------------------------\n";

    for (int i = 0; i < DATA_SIZE; i++) {
        ht.insert(values[i]);
    }

    ht.display();

    return 0;
}
