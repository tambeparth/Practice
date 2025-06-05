// this approach efficient when input already sorted to avoid extra time and space complexity.
// to improve functionality add separate function for sorting given element but it take (NlogN) time complexity for it
#include <iostream>
#include <bits/stdc++.h>
#include <vector>

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

Node *sortTwoLinkedList(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;
    while (list1 != nullptr && list2 != nullptr)
    {

        if (list1->data <= list2->data)
        {
            temp->next = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            list2 = list2->next;
        }

        temp = temp->next;
    }

    if (list1 != nullptr)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }
    return dummyNode->next;
}

Node *printLinkedList(Node *head)
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
    Node *list1 = new Node(5);
    list1->next = new Node(6);
    list1->next->next = new Node(7);

    Node *list2 = new Node(1);
    list2->next = new Node(3);
    list2->next->next = new Node(4);

    cout << "Print First List1: ";
    printLinkedList(list1);

    cout << "Print second List2: ";
    printLinkedList(list2);

    cout << "Final List: ";
    Node *merge = sortTwoLinkedList(list1, list2);
    printLinkedList(merge);
    return 0;
}