#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;};
Node* head = nullptr;
void insertAtHead(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;}
void displayList() {
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;}
    cout << "NULL" << endl;}
int countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;}
    return count;}
int main() {  cout << "Empty list node count: " << countNodes() << endl;
    insertAtHead(10);
    insertAtHead(20);
    insertAtHead(30);
    insertAtHead(40);
    displayList();
    cout << "Number of nodes: " << countNodes() << endl;
    return 0;}
