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
void insertAtThird(int value) {   //inserts a new node at the 3rd position of the list
    Node* newNode = new Node();
    newNode->data = value;
    if (head == nullptr || head->next == nullptr) {
        cout << "List has fewer than 2 nodes. Inserting " << value
             << " at the end instead." << endl;
        if (head == nullptr) {
            head = newNode;
        } else {
            head->next = newNode;
        }
        newNode->next = nullptr;
        return;
    }
    Node* temp = head;
    for (int i = 1; i < 2 && temp->next != nullptr; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;    //insert new node right after the 2nd node
    temp->next = newNode;
    cout << value << " inserted at 3rd position." << endl;
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
int main() { 
    insertAtHead(80);
    insertAtHead(30);
    insertAtHead(10);
    cout << "Before insertion:" << endl;
    displayList();
    // Insert 23 at the 3rd position
    insertAtThird(23);
    cout << "After insertion:" << endl;
    displayList();
    return 0;
}

