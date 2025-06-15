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

int getDifference(Node *head1, Node *head2)
{
    int len1 = 0;
    int len2 = 0;
    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL)
        {
            len1++;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            len2++;
            head2 = head2->next;
        }
    }
    return len1 - len2;
}

Node *intersectionPresent(Node *head1, Node *head2)
{
    int diff = getDifference(head1, head2);
    if (diff < 0)

        while (diff++ != 0)
            head2 = head2->next;
    else
        while (diff-- != 0)
            head1 = head1->next;

    while (head1 != NULL)
    {
        if (head1 == head2)
            return head1;
        head2 = head2->next;
        head1 = head1->next;
    }
    return head1;
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
    // creation of both lists
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
    // printing of the lists
    cout << "List1: ";
    printList(head1);
    cout << "List2: ";
    printList(head2);
    // checking if intersection is present
    Node *answerNode = intersectionPresent(head1, head2);
    if (answerNode == NULL)
        cout << "No intersection\n";
    else
        cout << "The intersection point is " << answerNode->num << endl;
    return 0;
}
