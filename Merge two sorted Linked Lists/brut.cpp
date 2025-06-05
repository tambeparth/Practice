
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
Node *convertArrIntoLinkedList(vector<int> &arr)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    for (int i = 0; i < arr.size(); i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return dummyNode->next;
}
Node *sortTwoLinkedLists(Node *list1, Node *list2)
{
    vector<int> arr;
    Node *temp1 = list1;
    Node *temp2 = list2;

    while (temp1 != NULL)
    {
        arr.push_back(temp1->data);
        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        arr.push_back(temp2->data);
        temp2 = temp2->next;
    }

    sort(arr.begin(), arr.end());
    Node *head = convertArrIntoLinkedList(arr);
    return head;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *list1 = new Node(1);
    list1->next = new Node(2);
    list1->next->next = new Node(5);

    Node *list2 = new Node(3);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "First Sorted Linked List: ";
    printLL(list1);

    cout << "Second sorted Linked List: ";
    printLL(list2);

    Node *mergeLL = sortTwoLinkedLists(list1, list2);
    cout << "Merge Sorted LinkedList: ";
    printLL(mergeLL);
    return 0;
}