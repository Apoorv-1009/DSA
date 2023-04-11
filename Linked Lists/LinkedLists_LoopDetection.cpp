// Cpp program to find loops in a List with Floyds Cycle Detection Algorithm
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

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

void printList(Node *ptr)
{
    cout << "\n Current list: ";
    while(ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

Node *LoopDetection(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while(fast!= NULL && fast->next != NULL)
    {
        // Increment slow pointer by 1
        slow = slow->next;
        // Increment fast pointer by 2
        fast = fast->next->next;
        // If both addresses are equal, loop exists
        if(slow == fast)
            return slow;
    }
    return 0;
}

Node *DetectFirstNode(Node *&head)
{
    Node *intr = LoopDetection(head);
    Node *start = head;

    // Iterate toward each other from the 
    // intersecting node and the starting node
    while(intr != start)
    {
        intr = intr->next;
        start = start->next;
    }
    return intr;
}

int main()
{
    Node *head;
    head = NULL;
    // Append first 5 natural numbers to the list
    for(int i=1; i<6; i++)
        append(head, i);
    printList(head);
  
    /* Create a loop for testing 
    1 -> 2 -> 3 -> 4 -> 5 
              |         |
              -----------  
    3 and 5 are connected       
    */
    head->next->next->next->next->next = head->next->next;
    //printList(head);

    bool loop = LoopDetection(head);
    if(loop)
    {
        Node *intr = DetectFirstNode(head);
        cout << "\n Loop present at this address: " << intr;
        cout << "\n Data present at this address: " << intr->data;
    }
    else 
        cout << "\n Loop is not present";

}