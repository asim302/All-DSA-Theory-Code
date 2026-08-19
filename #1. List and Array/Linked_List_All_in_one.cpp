#include <iostream> 
using namespace std; 
struct Node { 
int data; 
Node* next; 
}; 
class SinglyLinkedList { 
private: 
Node* head; 
public: 
SinglyLinkedList() { 
head = NULL; 
} 
// Display list 
void display() { 
if (head == NULL) { 
cout << "List is empty.\n"; 
return; 
} 
 
        Node* temp = head; 
        while (temp != NULL) { 
            cout << temp->data << " -> "; 
            temp = temp->next; 
        } 
        cout << "NULL\n"; 
    } 
 
    // 1. Add node at the start 
    void addAtStart(int value) { 
        Node* newNode = new Node(); 
        newNode->data = value; 
        newNode->next = head; 
        head = newNode; 
    } 
 
    // 2. Add node at the end 
    void addAtEnd(int value) { 
        Node* newNode = new Node(); 
        newNode->data = value; 
        newNode->next = NULL; 
 
        if (head == NULL) { 
            head = newNode; 
            return; 
        } 
 
        Node* temp = head; 
        while (temp->next != NULL) { 
            temp = temp->next; 
        } 
 
        temp->next = newNode; 
    } 
 
    // 3. Add node at specific position 
    void addAtPosition(int value, int position) { 
        if (position < 1) { 
            cout << "Invalid position.\n"; 
            return; 
        } 
 
        if (position == 1) { 
            addAtStart(value); 
            return; 
        } 
 
        Node* newNode = new Node(); 
        newNode->data = value; 
        newNode->next = NULL; 
 
        Node* temp = head; 
        for (int i = 1; i < position - 1 && temp != NULL; i++) { 
            temp = temp->next; 
        } 
 
        if (temp == NULL) { 
            cout << "Position out of range.\n"; 
            delete newNode; 
            return; 
        } 
 
        newNode->next = temp->next; 
        temp->next = newNode; 
    } 
 
    // 4. Update first node 
    void updateFirstNode(int value) { 
        if (head == NULL) { 
            cout << "List is empty.\n"; 
            return; 
        } 
        head->data = value; 
    } 
 
    // 5. Update last node 
    void updateLastNode(int value) { 
        if (head == NULL) { 
            cout << "List is empty.\n"; 
            return; 
        } 
 
        Node* temp = head; 
        while (temp->next != NULL) { 
            temp = temp->next; 
        } 
 
        temp->data = value; 
    } 
 
    // 6. Update node at specific position 
    void updateAtPosition(int value, int position) { 
        if (position < 1) { 
            cout << "Invalid position.\n"; 
            return; 
        } 
 
        Node* temp = head; 
        for (int i = 1; i < position && temp != NULL; i++) { 
            temp = temp->next; 
        } 
 
        if (temp == NULL) { 
            cout << "Position out of range.\n"; 
            return; 
        } 
 
        temp->data = value; 
    } 
 
    // 7. Delete first node 
    void deleteFirstNode() { 
        if (head == NULL) { 
            cout << "List is empty.\n"; 
            return; 
        } 
 
        Node* temp = head; 
        head = head->next; 
        delete temp; 
    } 
 
    // 8. Delete last node 
    void deleteLastNode() { 
        if (head == NULL) { 
            cout << "List is empty.\n"; 
            return; 
        } 
 
        if (head->next == NULL) { 
            delete head; 
            head = NULL; 
            return; 
        } 
 
        Node* temp = head; 
        while (temp->next->next != NULL) { 
            temp = temp->next; 
        } 
 
        delete temp->next; 
        temp->next = NULL; 
    } 
 
    // 9. Delete node at specific position 
    void deleteAtPosition(int position) { 
        if (head == NULL) { 
            cout << "List is empty.\n"; 
            return; 
        } 
 
        if (position < 1) { 
            cout << "Invalid position.\n"; 
            return; 
        } 
 
        if (position == 1) { 
            deleteFirstNode(); 
            return; 
        } 
 
        Node* temp = head; 
        for (int i = 1; i < position - 1 && temp->next != NULL; i++) { 
            temp = temp->next; 
        } 
 
        if (temp->next == NULL) { 
            cout << "Position out of range.\n"; 
            return; 
        } 
 
        Node* nodeToDelete = temp->next; 
        temp->next = nodeToDelete->next; 
        delete nodeToDelete; 
    } 
}; 
 
int main() { 
    SinglyLinkedList list; 
 
    list.addAtEnd(10); 
    list.addAtEnd(20); 
    list.addAtEnd(30); 
    cout << "Initial List: "; 
    list.display(); 
 
    list.addAtStart(5); 
    cout << "After adding at start: "; 
    list.display(); 
list.addAtPosition(15, 3); 
cout << "After adding 15 at position 3: "; 
list.display(); 
list.updateFirstNode(100); 
cout << "After updating first node: "; 
list.display(); 
list.updateLastNode(300); 
cout << "After updating last node: "; 
list.display(); 
list.updateAtPosition(200, 3); 
cout << "After updating position 3: "; 
list.display(); 
list.deleteFirstNode(); 
cout << "After deleting first node: "; 
list.display(); 
list.deleteLastNode(); 
cout << "After deleting last node: "; 
list.display(); 
list.deleteAtPosition(2); 
cout << "After deleting position 2: "; 
list.display(); 
return 0; 
}