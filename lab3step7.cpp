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
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
void searchValue(int value) {
    Node* temp = head;
    int position = 0;
    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Value " << value << " found at position " << position << "." << endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "Value " << value << " not found in the list." << endl;
}
int main() {
    insertAtHead(10);
    insertAtHead(20);
    insertAtHead(30);
    displayList();
    searchValue(20);   // should be found
    searchValue(99);   // should not be found
    return 0;
}


