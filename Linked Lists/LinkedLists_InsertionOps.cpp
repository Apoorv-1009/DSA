//Cpp code to test the insertion operations in Linked Lists

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

void add2beginning(Node *&head, int data)
{   // Add element to the beginning of the list

    // Create a new node
    Node *newnode;
    newnode = new Node();
    newnode->data = data;
    // Point the new node to the beginning of the list
    newnode->next = head;

    //Update the new head of the list
    head = newnode;

}

void insert(Node *&head, int data, int pos)
{   // Add element to a given position

    // Iterate to pos and find the address
    int i = 1;
    Node *temp;
    temp = new Node();
    temp = head;
    while(i < pos-1)
    {
        if(i<pos && temp->next == NULL)
        {
            cout << "\n Position is out of index";
            return;
        }

        else
            temp = temp->next;
        i++;
    }

    // Create a new node
    Node *newnode;
    newnode = new Node();
    newnode->data = data; 
    // Make the new node point to the pos element
    newnode->next = temp->next;
    // Make the pos-1 element point to the new node
    temp->next = newnode;

}

int main()
{
    Node *head;
    head = NULL;

    // Append first 5 natural numbers to the list
    for(int i=1; i<6; i++)
        append(head, i);
    printList(head);

    // Add 6, 7, 8 to the starting of the list
    for(int i=8; i>5; i--)
        add2beginning(head, i);
    printList(head);

    // Add a value to a specific position
    insert(head, 9, 8);
    printList(head);
    return 0;
}