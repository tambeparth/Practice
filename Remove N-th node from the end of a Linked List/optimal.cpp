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

Node *print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *deleteNode(Node *head, int N)
{
    Node *slow = head;
    Node *fast = head;

    for (int i = 0; i < N; i++)
    {
        fast = fast->next;
    }

    if (fast == NULL)
    {
        return head->next;
    }

    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node *deleteNode = slow->next;
    slow->next = slow->next->next;
    delete (deleteNode);
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    int N = 2;
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);
    print(head);

    head = deleteNode(head, N);
    print(head);
}
