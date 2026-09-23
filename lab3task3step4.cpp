#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = nullptr;
void insertAtHead(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}
void displayList() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
//removes the final node in the list
void deleteLast() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Only node deleted. List is now empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;      // free the actual last node
    temp->next = nullptr;   // temp becomes the new last node
    cout << "Last node deleted." << endl;
}
int main() {
    insertAtHead(10);
    insertAtHead(20);
    insertAtHead(30);
    cout << "Before deletion:" << endl;
    displayList();
    deleteLast();
    cout << "After deletion:" << endl;
    displayList();
    deleteLast();
    deleteLast();
    cout << "After deleting all nodes:" << endl;
    displayList();
    deleteLast();   //empty list case
    return 0;
}


