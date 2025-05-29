
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;

    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *reverseLinkedList(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newHead = reverseLinkedList(head->next);

    Node *front = head->next;

    front->next = head;

    head->next = NULL;

    return newHead;
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{

    Node *head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = reverseLinkedList(head);

    cout << "Reversed Linked List: ";
    printLinkedList(head);

    return 0;
}
