#include <iostream>
using namespace std;
template <typename T> // class is generic and c++ template declaration
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data) // constructor- it's called automatically when you create a new node
    // The constructor receives data and assigns it to the class's data member.

    // It also sets next = NULL because when a node is first created, it's not connected to any other node.
    {
        // this-> is used to refer to the current object's data.
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *curr = head;

    while (curr != NULL)
    {
        LinkedListNode<int> *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

LinkedListNode<int> *takeInput()
{
    int data;
    cin >> data;

    LinkedListNode<int> *head = NULL;
    LinkedListNode<int> *tail = NULL;
    while (data != -1)
    {
        LinkedListNode<int> *newNode = new LinkedListNode<int>(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void printLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "-1" << endl;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        LinkedListNode<int> *head = takeInput();
        LinkedListNode<int> *reverseHead = reverseLinkedList(head);
        printLinkedList(reverseHead);
    }
    return 0;
}