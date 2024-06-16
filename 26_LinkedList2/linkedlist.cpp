#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }

    // ~Node() {
    //     if(next != NULL) {
    //         delete next;
    //         next = NULL;
    //     }
    // }
};

class List {
public:
    Node* head;
    Node* tail;

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

        if(head == NULL) {
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

    // ~List() {
    //     if(head != NULL) {
    //         delete head; 
    //         head = NULL; 
    //     }
    // }  
};

//cycle detection
bool isCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            return true;
        }
    }

    return false;
}

void removeCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    bool isCycle = false;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            isCycle = true;
            break;
        }
    }

    if(!isCycle) {
        return;
    }

    //Removing Loop
    slow = head;

   if(slow == fast) { 
    //special case when tail is connected to head
        while(fast->next != slow) {
            fast = fast->next;
        }
        fast->next = NULL;

   } else {
        Node* prev = fast;
        while(slow != fast) {
            prev = fast;
            slow = slow->next;
            fast = fast->next;
        }

        //prev is the last node
        prev->next = NULL;
   }
}

Node* splitAtMid(Node* head) {
    Node* slow = head;
    Node* fast = head;
    Node* prev = NULL;

    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if(prev != NULL) {
        prev->next = NULL;
    }

    return slow;
}

Node* merge(Node* h1, Node*h2) {
    List ans;
    Node* i = h1;
    Node* j = h2;

    while(i != NULL && j != NULL) {
        if(i->data <= j->data) {
            ans.push_back(i->data);
            i = i->next;
        } else {
            ans.push_back(j->data);
            j = j->next;
        }
    }

    while(i != NULL) {
        ans.push_back(i->data);
        i = i->next;
    }

    while(j != NULL) {
        ans.push_back(j->data);
        j = j->next;
    }
    return ans.head;
}

Node* mergeSort(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* rightHead = splitAtMid(head);
    Node* sortedLeft = mergeSort(head);
    Node* sortedRight =mergeSort(rightHead);

    return merge(sortedLeft, sortedRight);
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;

    while(curr != NULL) {
        Node* next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev; // prev is head
}

void printList(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* zigzag(Node* head) {
    Node* rightHead = splitAtMid(head);
    Node* rightRev = reverse(rightHead);

    //alternate merging
    Node* left = head;
    Node* right = rightRev;
    Node* nextLeft = NULL;
    Node* nextRight = NULL;
    Node* tail = head;

    while(left != NULL && right != NULL) {
        nextLeft = left->next;
        left->next = right;

        nextRight = right->next;
        right->next = nextLeft;

        tail = right;
        left = nextLeft;
        right = nextRight;
    }

    if(right != NULL) {
        tail->next = right;
    }
    return head;
}

int main(){
       List ll;

       //QS : Cycle Detection & Removal
       /* ll.push_front(4);
       ll.push_front(3);
       ll.push_front(2);
       ll.push_front(1);

       ll.tail->next = ll.head; //creating a cycle

        cout << isCycle(ll.head) << endl;
        removeCycle(ll.head);
        cout << isCycle(ll.head) << endl;
        ll.printList(); */

        //QS : Merge Sort the Linked List
        // ll.push_front(1);
        // ll.push_front(2);
        // ll.push_front(3);
        // ll.push_front(4);
        // ll.printList();

        // ll.head = mergeSort(ll.head);
        // ll.printList();

        //QS : Zig Zag Linked List
        ll.push_front(5);
        ll.push_front(4);
        ll.push_front(3);
        ll.push_front(2);
        ll.push_front(1);
        ll.printList();

        ll.head = zigzag(ll.head);
        ll.printList();
}
