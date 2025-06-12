#include <iostream>
using namespace std;

class Node
{
public:
    int num;
    Node *next;
    Node(int val)
    {
        num = val;
        next = NULL;
    }
};

void insertNode(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    return;
}

Node *intersectionPresent(Node *head1, Node *head2)
{
    while (head2 != NULL)
    {
        Node *temp = head1;
        while (temp != NULL)
        {
            if (temp == head2)
                return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    return NULL;
}

void printList(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
}

int main()
{
    Node *head = NULL;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);
    Node *head1 = head;
    head = head->next->next->next;

    Node *headSec = NULL;
    insertNode(headSec, 3);
    Node *head2 = headSec;
    headSec->next = head;

    cout << "List1: ";
    printList(head1);
    cout << "List2: ";
    printList(head2);

    Node *ans = intersectionPresent(head1, head2);
    if (ans == NULL)
        cout << "No intersection\n";
    else
        cout << "The intersection point is " << ans->num << endl;
    return 0;
}