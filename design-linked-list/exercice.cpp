
#include<iostream>
using namespace std;


class Node {
public:
    Node *next = nullptr;
    int value;

    Node(int val) {
        value = val;
    }
};

class MyLinkedList {
    Node *head = nullptr;
    Node *tail = nullptr;

public:
    friend ostream& operator <<(ostream& outputStream, const MyLinkedList& list);

    /** Initialize your data structure here. */
    MyLinkedList() {

    }

    MyLinkedList(int value) {
        Node *n = new Node(value);
        head = n;
        tail = n;
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int count = 0;

        for (Node *p = head; p != nullptr; p = p->next) {
            if (count == index) {
                return p->value;
            }
            count++;
        }

        return -1;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node *new_node = new Node(val);

        new_node->next = head;
        head = new_node;

        if (head->next == nullptr) {
            tail = head;
        }
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if (tail) {
            Node *new_node = new Node(val);
            tail->next = new_node;
            tail = new_node;
        } else {
            addAtHead(val);
        }

    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        int count = 0;

        for (Node *p = head; p != nullptr; p = p->next) {
            count++;
            if (count == index) {
                Node *new_node = new Node(val);
                new_node->next = p->next;
                p->next = new_node;

                if (tail == p) {
                    tail = new_node;
                }

                return;
            }
        }
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int count = 0;
        Node *prev = nullptr;


        if (index == 0) {
            if (head) {
                Node *p = head;
                head = p->next;

                if (!head or !head->next) {
                    tail = head;
                }
                delete p;

                return;
            }
        }


        for (Node *p = head; p != nullptr; p = p->next) {
            if (count == index) {
                prev->next = p->next;
                if (!prev->next) {
                    tail = prev;
                }
                delete p;

                return;
            }
            prev = p;
            count++;
        }

    }
};

ostream& operator <<(ostream& outputStream, const MyLinkedList& list){
    for (Node *p = list.head; p != nullptr; p = p->next) {
        outputStream << p->value;
        outputStream << " ";
    }

    outputStream.flush();
    return outputStream;
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */


int main() {
    MyLinkedList lista = MyLinkedList();
    cout << lista << endl;


    cout << "lista.addAtHead(7);" << endl;
    lista.addAtHead(7);
    cout << lista << endl<< endl;

    cout << "lista.addAtHead(2);" << endl;
    lista.addAtHead(2);
    cout << lista << endl<< endl;

    cout << "lista.addAtHead(1);" << endl;
    lista.addAtHead(1);
    cout << lista << endl<< endl;

    cout << "lista.addAtIndex(3, 0);" << endl;
    lista.addAtIndex(3, 0);
    cout << lista << endl<< endl;

    cout << "lista.deleteAtIndex(2);" << endl;
    lista.deleteAtIndex(2);
    cout << lista << endl<< endl;

    cout << "lista.addAtHead(6);" << endl;
    lista.addAtHead(6);
    cout << lista << endl<< endl;

    cout << "lista.addAtTail(4);" << endl;
    lista.addAtTail(4);
    cout << lista << endl<< endl;

    cout << "lista.get(4);" << endl;
    lista.get(4);
    cout << lista << endl<< endl;

    cout << "lista.addAtHead(4);" << endl;
    lista.addAtHead(4);
    cout << lista << endl<< endl;

    cout << "lista.addAtIndex(5,0);" << endl;
    lista.addAtIndex(5,0);
    cout << lista << endl<< endl;

    cout << "lista.addAtHead(6);" << endl;
    lista.addAtHead(6);
    cout << lista << endl<< endl;



    // lista.addAtHead(0);
    // lista.addAtTail(2);
    // cout << lista << endl;


    // lista.addAtIndex(1, 1);
    // cout << lista << endl;
    // lista.addAtIndex(1, 2);
    // cout << lista << endl;
    // lista.addAtIndex(1, 3);
    // cout << lista << endl;

    // lista.deleteAtIndex(0);
    // cout << lista << endl;



    return 0;
}
