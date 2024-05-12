#include <iostream>
using namespace std;

// Define Node structure
struct Node {
    int data;
    Node* next;
    
    // Constructor to initialize data and next pointer
    Node(int value) : data(value), next(nullptr) {}
};

// Define LinkedList class
class LinkedList {
private:
    Node* head;

public:
    // Constructor to initialize head to nullptr
    LinkedList() : head(nullptr) {}

    // Function to insert a node at the beginning of the linked list
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Function to print the linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // Create a linked list object
    LinkedList myList;

    // Insert elements into the linked list
    myList.insertAtBeginning(5);
    myList.insertAtBeginning(10);
    myList.insertAtBeginning(15);

    // Print the linked list
    cout << "Linked List: ";
    myList.printList();

    return 0;
}
