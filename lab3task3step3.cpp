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
        return;}
    Node* temp = head;   //pointer starts at head
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;   // move to next node
    }
    cout << "NULL" << endl;   // shows termination of the list
}
int main() {
    displayList();
    insertAtHead(30);
    insertAtHead(20);
    insertAtHead(10);
    displayList();
    return 0;
}