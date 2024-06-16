#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        next = prev = NULL;
    }
};

class DoublyList {
public:
    Node* head;
    Node* tail;

    DoublyList() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if(head == NULL) {
            head = tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " <=> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void pop_front() {
        cout << "deleting : " << head->data << endl;
        Node* temp = head;
        head = head->next;
        if(head != NULL) {
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }

    
};

int main() {
    DoublyList dll;
    
    dll.push_front(3);
    dll.push_front(2);
    dll.push_front(1);

    dll.printList();

    dll.pop_front();
    dll.printList();
}