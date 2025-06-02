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
    // Initialize'temp' at
    // head of linked list
    Node *temp = head;

    // Initialize pointer 'prev' to NULL,
    // representing the previous node
    Node *prev = NULL;

    // Traverse the list, continue till
    // 'temp' reaches the end (NULL)
    while (temp != NULL)
    {
        // Store the next node in
        // 'front' to preserve the reference
        Node *front = temp->next;

        temp->next = prev;

        prev = temp;

        temp = front;
    }

    return prev;
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
