#include <iostream>

using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int val) {
    data = val;
    next = NULL;
  }
};

class Stack {
private:
  Node *head = NULL;

public:
  int stackSize;
  int count = 0;

  Stack() {
    cout << "Enter the size of stack" << endl;
    cin >> stackSize;
  }

  void push(int value) {
    if (count == stackSize) {
      cout << "Value can't be pushed, Because Stack is full" << endl;
      return;
    }
    Node *n = new Node(value);
    if (head == NULL) {
      head = n;
      count++;
    } else {
      n->next = head;
      head = n;
      count++;
    }
  }

  void pop() {
    if (head == NULL) {
      cout << "Stack is empty" << endl;
      return;
    } else {
      cout << head->data << endl;
      head = head->next;
      count--;
    }
  }

  void display() {
    Node *temp = head;

    while (temp != NULL) {
      cout << temp->data << "\t";
      temp = temp->next;
    }
    cout << endl;
  }
};

int main() {

  Stack myStack;

  bool isStop = false;

  int option;
  while (!isStop) {
    cout << "Enter an option (1: Push, 2: Pop, 3: Display, 4: Exit): ";
    cin >> option;

    if (option == 1) {
      int value;
      cout << "Enter digit to push: ";
      cin >> value;
      myStack.push(value);
    } else if (option == 2) {
      myStack.pop();
    } else if (option == 3) {
      myStack.display();
    } else if (option == 4) {
      isStop = true;
    } else {
      cout << "Invalid option. Please try again." << endl;
    }
  }

  return 0;
}