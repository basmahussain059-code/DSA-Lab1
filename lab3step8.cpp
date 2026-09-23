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
    cout << value << " inserted at head." << endl;}
void insertAtThird(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    if (head == nullptr || head->next == nullptr) {
        cout << "List has fewer than 2 nodes. Inserting " << value
             << " at the end instead." << endl;
        if (head == nullptr) {
            head = newNode;
            newNode->next = nullptr;
        } else {
            head->next = newNode;
            newNode->next = nullptr;
        }
        return;
    }
    Node* temp = head;
    for (int i = 1; i < 2 && temp->next != nullptr; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    cout << value << " inserted at 3rd position." << endl;
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
void deleteLast() {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
if (head->next == nullptr) {
        // Only one node in the list
        delete head;
        head = nullptr;
        cout << "Only node deleted. List is now empty." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    cout << "Last node deleted." << endl;
}
int countNodes() {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}
void reverseList() {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    cout << "List reversed." << endl;
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
void destroyList() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
    head = nullptr;
}
int main() {
    int choice, value;

    do {
        cout << "\n===== Singly Linked List Menu =====" << endl;
        cout << "1. Insert at head" << endl;
        cout << "2. Insert at 3rd position" << endl;
        cout << "3. Display list" << endl;
        cout << "4. Delete last node" << endl;
        cout << "5. Count nodes" << endl;
        cout << "6. Reverse list" << endl;
        cout << "7. Search for a value" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at head: ";
                cin >> value;
                insertAtHead(value);
                displayList();
                break;
            case 2:
                cout << "Enter value to insert at 3rd position: ";
                cin >> value;
                insertAtThird(value);
                displayList();
                break;
            case 3:
                displayList();
                break;
            case 4:
                deleteLast();
                displayList();
                break;
            case 5:
                cout << "Number of nodes: " << countNodes() << endl;
                break;
            case 6:
                reverseList();
                displayList();
                break;
            case 7:
                cout << "Enter value to search: ";
                cin >> value;
                searchValue(value);
                break;
            case 8:
                cout << "Exiting program. Freeing remaining nodes..." << endl;
                destroyList();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 8);
    return 0;
}



