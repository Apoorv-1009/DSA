// Cpp code to study the basics of linked list

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

int main()
{
   // Create 3 pointers of type node
   // head points to first element of the list
   // new points to the address of the newest node created
   // last points to the address of the last node created
   Node *head, *newnode, *last;
   head = NULL;
   newnode = head;
   last = head;

   cout << "\n Enter 5 values: ";
   int data, i = 0;
   while(i < 5)
   {
        cin >> data;

        // Create a new node
        newnode = new Node();
        // Assign the data 
        newnode->data = data;
        // Assign the next pointer of the newest node as NULL
        newnode->next = NULL;

        // Update value of the pointers

        // If the new node created is the first node then 
        // assign the head and last node to it
        if(head == NULL)
            head = newnode;

        // If this is not the first node, assign the value 
        // of the next pointer of the previous node to the 
        // new node
        else 
            last->next = newnode;

        // Update the last node
        last = newnode;

        i++;
   }

    // print elements of the list
    printList(head);

    return 0;
}