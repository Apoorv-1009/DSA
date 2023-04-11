#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int coeff;
    int pow;
    struct Node *next;
};

void print(Node *&head)
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout << temp->coeff << " ";
        cout << temp->pow << "\n";
        temp = temp->next;
    }
    cout << "\n";
}

void push(Node *&head, int coeff, int pow)
{
    Node *temp = new Node();

    // Check if head is empty
    if(head == NULL)
    {
        head = temp;
        head->coeff = coeff;
        head->pow = pow;
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
        temp2->coeff = coeff;
        temp2->pow = pow;
        temp2->next = NULL;
    }
}

void add2polynomials(Node *&p1, Node *&p2)
{
    Node *t1 = p1, *t2 = p2;
    Node *sum = NULL;
    Node *sumhead = sum;

    if(t1 == NULL)
    {
        sum = t2;
        return;
    }

    if(t2 == NULL)
    {
        sum = t1;
        return;
    }

    while(t1 != NULL || t2 != NULL)
    {
        print(sumhead);
        
        Node *temp = new Node;
        if(sum == NULL)
        {
            sumhead = temp;
            sum = temp;
        }
        else 
        {
            sum->next = temp;
            sum = sum->next;
        }

        if(t1->pow == t2->pow)
        {
            temp->coeff = t1->coeff + t2->coeff;
            temp->pow = t1->pow;
            t1 = t1->next;
            t2 = t2->next;
        }
        if(t1->pow > t2->pow)
        {
            temp->coeff = t1->coeff;
            temp->pow = t1->pow;
            t1 = t1->next;
        }
        if(t2->pow > t1->pow)
        {
            temp->coeff = t2->coeff;
            temp->pow = t2->pow;
            t2 = t2->next;
        }
    }

    print(sumhead);
}


int main()
{

    Node *head = NULL;

    // Create a polynomials in Linked Lists format
    Node *poly1 = NULL;
    // x^5 + x^3 + 1
    push(poly1, 1, 5);
    push(poly1, 1, 3);
    push(poly1, 1, 0);

    // Display polynomial
    print(poly1);

    // Create a polynomials in Linked Lists format
    Node *poly2 = NULL;
    // x^5 + x^4 + x^2
    push(poly2, 1, 5);
    push(poly2, 1, 4);
    push(poly2, 1, 2);

    // Display polynomial
    print(poly2);

    add2polynomials(poly1, poly2);
    return 0;

}