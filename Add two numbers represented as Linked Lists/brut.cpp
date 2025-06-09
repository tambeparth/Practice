#include <iostream>
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

Node *addTwoNumbers(Node *l1, Node *l2)
{
    Node *dummy = new Node(0);
    Node *temp = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;

        if (l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;

        temp->next = new Node(sum % 10);
        temp = temp->next;
    }

    return dummy->next;
}

Node *createList(const vector<int> &digits)
{
    if (digits.empty())
        return nullptr;

    Node *head = new Node(digits[0]);
    Node *temp = head;

    for (size_t i = 1; i < digits.size(); ++i)
    {
        temp->next = new Node(digits[i]);
        temp = temp->next;
    }

    return head;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data;
        if (head->next)
            cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main()
{

    vector<int> num1 = {2, 4, 3}; // 342
    vector<int> num2 = {5, 6, 4}; // 465

    Node *l1 = createList(num1);
    Node *l2 = createList(num2);

    cout << "Input 1: ";
    printList(l1);
    cout << "Input 2: ";
    printList(l2);

    Node *result = addTwoNumbers(l1, l2);

    cout << "Result : ";
    printList(result); // Expected: 7 -> 0 -> 8

    return 0;
}
