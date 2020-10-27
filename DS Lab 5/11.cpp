#include<iostream>

using namespace std;

class Node {
public:
    int key;
    int data;
    Node* next;
    Node* prev;

    Node() {
        key = 0;
        data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int k, int d) {
        key = k;
        data = d;
    }
};

class DoublyCircularLinkedList {
public:
    Node* head;

    DoublyCircularLinkedList() {
        head = NULL;
    }

    // 1. CHeck if node exists using key value
    Node* nodeExists(int k) {

        Node* temp = NULL;
        Node* ptr = head;

        if (ptr == NULL) {
            return temp;
        }
        else {
            do {
                if (ptr -> key == k) {
                    temp = ptr;
                }
                ptr = ptr -> next;

            } while (ptr != head);
            return temp;
        }

        
    }

    
    void appendNode(Node* n) {
        if (nodeExists(n-> key) != NULL) {
            cout << "Node Already exists with key value : " <<
                n-> key <<
                ". Append another node with different Key value" <<
                endl;
        }
        else {
            if (head == NULL) {
                head = n;
                n-> next = head;
                n->prev = head;
                cout << "Node Appended at first Head position" << endl;
            }
            else {
                Node* ptr = head;
                while (ptr -> next != head) {
                    ptr = ptr -> next;
                }
                ptr -> next = n;
                n->prev = ptr;
                n-> next = head;
                head->prev = n;
                cout << "Node Appended" << endl;
            }
        }

    }

 

   
    void deleteNodeByKey(int k) {
        Node* toDel = nodeExists(k);
        if (toDel == NULL) {
            cout << "No node exists with key value OF : " << k <<
                endl;
        }
        else {

            if (toDel == head) {
                if (head -> next == NULL) {
                    head = NULL;
                    cout << "Head node Unlinked... List Empty";
                }
                else {
                    //Deleting last node in the list
                    Node* ptr1 = head;
                    while (ptr1 -> next != head) {
                        ptr1 = ptr1 -> next;
                    }
                    ptr1 -> next = head -> next;
                    head = head -> next;
                    head->prev = ptr1;
                    cout << "Node UNLINKED with keys value : " << k << endl;
                }
            }
            else {
                Node* temp = NULL;
                Node* prevptr = head;
                Node* currentptr = head -> next;
                while (currentptr != NULL) {
                    if (currentptr -> key == k) {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else {
                        prevptr = prevptr -> next;
                        currentptr = currentptr -> next;
                    }
                }

                prevptr -> next = temp -> next;
                cout << "Node UNLINKED with keys value : " << k << endl;

            }

        }

    }
   

    // 7th printing
    void printList() {
        if (head == NULL) {
            cout << "No Nodes in Doubly Circular Linked List";
        }
        else {
            cout << endl << "head address : " << head << endl;
            cout << "Doubly Circular Linked List Values : " << endl;

            Node* temp = head;

            do {
                cout << "("  << temp->prev<< "," <<  temp -> key << "," << temp -> data << "," << temp -> next << ") <--> ";
                temp = temp -> next;
            } while (temp != head);
        }

    }

    void updateNodeByKey(int k, int new_data) {

        Node* ptr = nodeExists(k);
        if (ptr != NULL) {
            ptr -> data = new_data;
            cout << "Node Data Updated Successfully" << endl;
        }
        else {
            cout << "Node Doesn't exist with key value : " << k << endl;
        }

    }

};

int main()
{
    Node a(1, 10);
    Node b(2, 20);
    Node c(3, 30);

    DoublyCircularLinkedList cl;
    cl.appendNode(&a);
    cl.appendNode(&b);
    cl.appendNode(&c);
    cl.deleteNodeByKey(2);
    cl.printList();
}
