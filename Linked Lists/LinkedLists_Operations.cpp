/*Code to push, append, pop, remove elements from a Linked List*/
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void print(Node *&head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void push(Node *&head, int data)
{
    Node *temp = new Node();

    // Check if head is empty
    if(head == NULL)
    {
        head = temp;
        head->data = data;
        head->next = NULL;
    }

    // Iterate to last node
    else 
    {
        temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        // temp is now at last node
        Node *temp2 = new Node();
        temp->next = temp2;
        temp2->data = data;
        temp2->next = NULL;
    }
}

void append(Node *&head, int pos, int data)
{
    if(head == NULL)
    {
        if(pos != 1)
        {
            cout << "\n Empty list, cannot append";
            return;
        }
        else 
        {
            Node *temp = new Node();
            head = temp;
            head->next = NULL;
            head->data = data;
        }
    }

    // Calculate length of the List
    Node *temp = head;
    int l = 0;
    while(temp != NULL)
    {
        l++;
        temp = temp->next;
    }

    if(pos > l)
    {
        cout << "\n Given position is out of bounds, cannot append";
        return;
    }
    else
    {
        // Iterate to the given pos-1 position
        int i=1;
        Node *temp = head;
        while(i < pos-1)
        {
            i++;
            temp = temp->next;
        }
        Node *temp2 = new Node();
        temp2->next = temp->next;
        temp->next = temp2;
        temp2->data = data;
    }
}

void add2beginning(Node *&head, int data)
{
    Node *temp = new Node();
    temp->data = data;

    if(head == NULL)
    {
        head = temp;
        temp->next = NULL;
        return;
    }

    temp->next = head;
    head = temp;
}

void pop(Node *&head)
{
    if(head == NULL)
        cout << "\n No elements present";

    else if(head->next == NULL)
        head = NULL;

    else 
    {
        Node *temp = head;
        // Stop at 2nd last element
        while(temp->next->next != NULL)
            temp = temp->next;
        temp->next = NULL;
    }
}

void remove(Node *&head, int pos)
{
    if(head == NULL)
    {
        cout << "\n List is empty, cannot be removed";
        return;
    }

    // Calculate the list length
    Node *temp = head;
    int l = 0;
    while(temp != NULL)
    {
        temp = temp->next;
        l++;
    }
    if(pos > l)
    {
        cout << "\n Given position is out of bounds, cannot remove";
        return;
    }

    temp = head;
    // Iterate to the pos-1 element
    int i = 1;
    while(i < pos-1)
    {
        temp = temp->next;
        i++;
    }
    
    Node *temp2 = temp->next;
    temp->next = temp2->next;
    temp2->next = NULL;
}

void deletefrombeginning(Node *&head)
{
    if(head == NULL)
    {
        cout << "\n Cannot delete from beginning, Empty list";
        return;
    }

    Node *temp = head;
    head = head->next;
    temp->next = NULL;
}

int main()
{
    Node *head = NULL;

    // Add 5 elements to the List
    for(int i=0; i<5; i++)
        push(head, i);

    // Print list
    print(head);

    // Pop off last element
    pop(head);

    // Print list
    print(head);

    // Add 7 to the 3rd position
    append(head, 3, 7);

    // Print list
    print(head);    

    // Remove element at 3rd position
    remove(head, 3);
    
    // Print list
    print(head); 

    // Add 9 to the beginning of the List
    add2beginning(head, 9);
    
    // Print list
    print(head); 

    // Remove the beginning element of the List
    deletefrombeginning(head);
    
    // Print list
    print(head); 

    return 0;
}