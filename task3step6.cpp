#include <iostream>
using namespace std;
struct Node { int data;
    Node* next;};
Node* head = nullptr;
void insertAtHead(int value) {Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;}
void displayList() { Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) { cout << temp->data << " -> ";
        temp = temp->next;   }
    cout << "NULL" << endl;}
void reverseList() { Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;   // save the next node before overwriting
        current->next = prev;   // reverse the link
        prev = current;         // move prev forward
        current = next;}
    head = prev;  
    cout << "List reversed." << endl;}
int main() {  insertAtHead(10);
    insertAtHead(20);
    insertAtHead(30);
    cout << "Before reversal:" << endl;
    displayList();
    reverseList();
    cout << "After reversal:" << endl;
    displayList();
    return 0;}