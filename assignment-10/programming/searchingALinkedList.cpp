#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};


void printList(Node* head) {

    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}


bool isSubList(Node* mainHead, Node* subHead) {

    if(mainHead == nullptr || subHead == nullptr){
        return false;
    }

    Node *mainTemp = mainHead;
    Node *subTemp = subHead;

    while(mainTemp && subTemp) {

        if(mainTemp->data == subTemp->data) {
            subTemp = subTemp->next;
        }
        else {
            subTemp = subHead;
        }

        mainTemp = mainTemp->next;
    }
    
    if(subTemp == nullptr) {
        return true;
    }

    return false;    
}


int main() {



    Node* mainHead = new Node(1);

    mainHead->next = new Node(2);
    mainHead->next->next = new Node(3);
    mainHead->next->next->next = new Node(4);
    mainHead->next->next->next->next = new Node(5);
    mainHead->next->next->next->next->next = new Node(6);

    Node* subHead = new Node(3);

    subHead->next = new Node(4);
    subHead->next->next = new Node(5);


    cout << "Main List: ";
    printList(mainHead);

    cout << "Sub List: ";
    printList(subHead);

    if (isSubList(mainHead, subHead)) {
        cout << "Sub-list found!" << endl;
    }
    else {
        cout << "Sub-list not found!" << endl;
    }


    return 0;
}