#include <iostream>
using namespace std;

// algorithm to merge two linked lists

// Create a node structure
class Node
{
public:
    int data;
    Node *next;
};

// Function to merge two linked lists
Node *mergeLists(Node *head1, Node *head2)
{
    // If either list is empty, return the other list
    if (head1 == NULL)
    {
        return head2;
    }
    else if (head2 == NULL)
    {
        return head1;
    }

    // Create a new node to store the merged list
    Node *mergedList = new Node;
    Node *current = mergedList;

    // Iterate through both lists and compare the data
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            current->next = head1;
            head1 = head1->next;
        }
        else
        {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    // Append the remaining elements of the non-empty list
    if (head1 != NULL)
    {
        current->next = head1;
    }
    else
    {
        current->next = head2;
    }

    // Return the merged list
    return mergedList->next;
}

int main()
{
    // Create two linked lists
    Node *head1 = new Node;

    Node *head2 = new Node;

    cout << "Enter the number of elements in the first list: " << endl;
    int n;
    cin >> n;
    cout << "Enter the elements of the first list: " << endl;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (i == 0)
        {
            head1->data = x;
            head1->next = NULL;
        }
        else
        {
            Node *temp = new Node;
            temp->data = x;
            temp->next = head1;
            head1 = temp;
        }
    }
    cout << "Enter the number of elements in the second list: " << endl;
    cin >> n;
    cout << "Enter the elements of the second list: " << endl;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (i == 0)
        {
            head2->data = x;
            head2->next = NULL;
        }
        else
        {
            Node *temp = new Node;
            temp->data = x;
            temp->next = head2;
            head2 = temp;
        }
    }

    // Merge the two linked lists
    Node *mergedList = mergeLists(head1, head2);

    // Print the merged list
    while (mergedList != NULL)
    {
        std::cout << mergedList->data << " ";
        mergedList = mergedList->next;
    }
    return 0;
}