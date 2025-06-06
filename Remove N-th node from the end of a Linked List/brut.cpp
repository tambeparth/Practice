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
    if (head == nullptr)
    {
        return head;
    }

    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->next;
    }

    if (cnt == N)
    {
        Node *newNode = head->next;
        delete (head);
        return newNode;
    }

    int res = cnt - N;
    temp = head;

    while (temp != NULL)
    {
        res--;
        if (res == 0)
        {
            break;
        }

        temp = temp->next;
    }

    Node *deletNode = temp->next;
    temp->next = temp->next->next;
    delete (deletNode);
    return head;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};

    int N = 3;
    Node *head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);
    print(head);

    head = deleteNode(head, N);
    print(head);
}
