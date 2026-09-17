#include <iostream>
using namespace std;


class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
ListNode* reverse(ListNode* prev, ListNode* curr, ListNode* next) {

    if(curr == NULL) {
        return prev;
    }

    next = curr->next;

    curr->next = prev;
    prev = curr;
    curr = next;

    return reverse(prev, curr, next);
        
}

ListNode* reverseList(ListNode* head) {
        
    if(head == NULL) {
        return NULL;
    }

    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;

    return reverse(prev, curr, next);
}

void printList(ListNode *head) {
    if(head == NULL) {
        return;
    }

    ListNode *temp = head;
    while(temp) {
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode *prev = NULL;
    ListNode *next = NULL;

    printList(reverse(prev, head, next));
}