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

    Node *list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(3);
    list1->next->next->next = new Node(4);
    list1->next->next->next->next = new Node(5);

    Node *list2 = new Node(1);
    list2->next = new Node(2);

    cout<<"List 1: "; printList(list1);
    cout<<"List2: ";printList(list2);
    cout<<"Result: ";

    if(isSubList(list1, list2)) {
        cout<<"FOUND!!!"<<endl;
    }
    else{
        cout<<"NOT FOUND!!!"<<endl;
    }


    Node *list3 = new Node(1);
    list3->next = new Node(2);
    list3->next->next = new Node(2);
    list3->next->next->next = new Node(1);
    list3->next->next->next->next = new Node(2);    
    list3->next->next->next->next->next = new Node(3);  
    
    Node *list4 = new Node(1);
    list4->next = new Node(2);
    list4->next->next = new Node(3);
    list4->next->next->next = new Node(4);

    cout<<endl;
    cout<<"List 3: "; printList(list3);
    cout<<"List4: ";printList(list4);
    cout<<"Result: ";

    if(isSubList(list3, list4)) {
        cout<<"FOUND!!!"<<endl;
    }
    else{
        cout<<"NOT FOUND!!!"<<endl;
    }
}