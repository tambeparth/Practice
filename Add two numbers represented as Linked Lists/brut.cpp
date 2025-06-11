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
    // Dummy node to simplify list creation
    Node *dummy = new Node(0);
    Node *temp = dummy; // Pointer to traverse and build result list
    int carry = 0;

    // Loop until both lists are done and no carry remains
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

        // Update carry for next digit
        carry = sum / 10;

        // Create a new node with the digit (sum % 10)
        temp->next = new Node(sum % 10);
        temp = temp->next; // Move to the next node in result
    }

    // Return the head of the resulting list (excluding dummy)
    return dummy->next;
}

// Helper function to create a linked list from a vector of digits
Node *createList(const vector<int> &digits)
{
    if (digits.empty())
        return nullptr; // Return null if input vector is empty

    // Create head node with the first digit
    Node *head = new Node(digits[0]);
    Node *temp = head;

    // Create remaining nodes
    for (size_t i = 1; i < digits.size(); ++i)
    {
        temp->next = new Node(digits[i]);
        temp = temp->next;
    }

    return head; // Return head of the linked list
}

// Helper function to print the linked list
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
    // Input numbers represented in reverse: 342 = [2, 4, 3], 465 = [5, 6, 4]
    vector<int> num1 = {2, 4, 3};
    vector<int> num2 = {5, 6, 4};

    // Create linked lists from the digit vectors
    Node *l1 = createList(num1);
    Node *l2 = createList(num2);

    // Print input lists
    cout << "Input 1: ";
    printList(l1);
    cout << "Input 2: ";
    printList(l2);

    // Add the two numbers and get result list
    Node *result = addTwoNumbers(l1, l2);

    // Print the resulting sum list
    cout << "Result : ";
    printList(result); // Expected: 7 -> 0 -> 8 (i.e., 342 + 465 = 807)

    return 0;
}
