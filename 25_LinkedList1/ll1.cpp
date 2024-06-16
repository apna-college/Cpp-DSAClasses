#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }

    ~Node() {
        if(next != NULL) {
            delete next;
            next = NULL;
        }
    }
};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);

        if(tail == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);

        if(tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void printList() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void insert(int val, int pos) {
        if(pos == 0) {
            push_front(val);
            return;
        }

        Node* temp = head;
        int i=0;
        while(temp != NULL && i<pos-1) {
            temp = temp->next;
            i++;
        }

        if(temp == NULL) {
            cout << "Invalid position\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void pop_front() {
        if(head == NULL) {
            return;
        }

        Node* temp = head;
        head = head->next;
        
        temp->next = NULL;
        delete temp;
    }

    void pop_back() {
        if(head == NULL) { //0 els
            return;
        }
        if(head->next == NULL) { //1 el
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        //temp has tail's prev
        temp->next = NULL;
        
        delete tail;
        tail = temp;
    }

    ~List() {
        if(head != NULL) {
            delete head; 
            head = NULL; 
        }
    }

    int searchItr(int key) {
        Node* temp = head;
        int idx = 0;

        while(temp != NULL) {
            if(temp->data == key) {
                return idx;
            }
            temp = temp->next;
            idx++;
        }
        
        return -1;
    }

    int searchRec(int key) {
        return searchHelper(head, key);
    }

    int searchHelper(Node* h, int key) {
        if(h == NULL) {
            return -1;
        }

        if(h-> data == key) {
            return 0; //current idx
        }

        int ans = searchHelper(h->next, key);
        if(ans == -1) {
            return -1;
        }

        return ans + 1;
    }

    void reverseLL() {
        Node* prev = NULL;
        Node* curr = head;

        while(curr != NULL) {
            Node* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        head = prev;
    }

    int sizeLL() {
        Node* temp = head;
        int sz = 0;

        while(temp != NULL) {
            temp = temp->next;
            sz++;
        }
        return sz;
    }

    void removeNth(int n) {
        int size = sizeLL();
        cout << "size : " << size << endl;
        if(n == size) {
            pop_front();
            return;
        }

        Node* temp = head;
        for(int i=1; i<size-n; i++) {
            temp = temp->next;
        }

        Node* toDel = temp->next; //node to delete
        temp->next = temp->next->next;
    }
}; 

int main() {
        List ll;

        ll.push_front(5);
        ll.push_front(4);
        ll.push_front(3);
        ll.push_front(2);
        ll.push_front(1);

       ll.printList();
       ll.removeNth(2); //delete 4
       ll.printList();
       return 0;
}






