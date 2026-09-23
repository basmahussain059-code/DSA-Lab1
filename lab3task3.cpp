#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* head = nullptr;
//inserts a new node at the beginning of the list
void insertAtHead(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;   // new node points to old head
    head = newNode;          // new node becomes the head
    cout << value << " inserted at head." << endl;
}
void displayList() {
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main() {   //insert several nodes at the head
    insertAtHead(10);
    displayList();
    insertAtHead(20);
    displayList();
    insertAtHead(30);
    displayList(); //most recently inserted node 30 is now the head
    return 0;
}