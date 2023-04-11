#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void printList(Node *ptr)
{   // Print the list
    cout << "\n Current list: ";
    while(ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void append(Node *&head, int data)
{   // Add element to end of the list
    
    // Create a new node
    Node *newnode;
    newnode = new Node();
    newnode->data = data;
    // Point new node to NULL since it is the last node
    newnode->next = NULL;

    // if List is empty
    if(head == NULL)
        head = newnode;

    else
    {
        Node *temp;
        temp = head;
        // Iterate till you reach the last element of list
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = newnode;
    }
    // printList(head);

}

void ListReversal(Node *&head)
{   // Reverse the list
    Node *curr = head, *prev = NULL, *next = NULL;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main()
{
    // Declare head node
    Node *head = NULL;

    // Create a list
    for(int i=0; i<5; i++)
        append(head, i);
    printList(head);

    // Reverse a list
    ListReversal(head);
    printList(head);

}