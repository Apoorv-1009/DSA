//Cpp code to test the deletion operations in Linked Lists

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void printList(Node *ptr)
{
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

void pop(Node *&head)
{   // Code to delete the last element in a list

    // Create 2 temp pointers 
    Node *temp, *prev;
    temp = head;
    prev = NULL;

    // Find the 2nd last element
    // Use temp to find last element
    // Use prev to find 2nd last
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    // Declare the 2nd last element pointer as NULL
    // to break linkage
    prev->next = NULL;

}

void popfirst(Node *&head)
{
    head = head->next;
}

void deletion(Node *&head, int pos)
{
    Node *temp, *prev;
    temp = head;
    prev = NULL;

    int i = 1;
    // Find the pos and pos-1 node
    while(i < pos)
    {
        prev = temp;
        temp = temp->next;
        i++;
    }


    prev->next = temp->next;
    temp->next = NULL;
}

int main()
{
    Node *head;
    head = NULL;

    // Append first 10 natural numbers to the list
    for(int i=1; i<11; i++)
        append(head, i);
    printList(head);

    // Pop off last element
    pop(head);
    printList(head);

    // Pop off first element
    popfirst(head);
    printList(head);

    // Pop off an element in specific position
    deletion(head, 3);
    printList(head);
    return 0;
}