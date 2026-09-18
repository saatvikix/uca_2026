#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

Node *findIntersection(Node *head1, Node *head2)
{

    if (head1 == NULL || head2 == NULL)
    {
        return NULL;
    }

    Node *temp1 = head1;
    Node *temp2 = head2;

    Node *result = NULL;
    Node *listBuilder = NULL;

    while (temp1 && temp2)
    {

        if (temp1->data < temp2->data)
        {
            temp1 = temp1->next;
        }

        else if (temp2->data < temp1->data)
        {
            temp2 = temp2->next;
        }

        else
        {
            Node *newNode = new Node(temp1->data);

            if (result == NULL)
            {
                result = newNode;
                listBuilder = newNode;
            }

            else
            {
                listBuilder->next = newNode;
                listBuilder = listBuilder->next;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    return result;
}
