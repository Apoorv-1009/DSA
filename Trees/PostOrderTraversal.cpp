#include <bits/stdc++.h>
using namespace std;
 
struct Node 
{
    int data;
    struct Node *left, *right;
};
 
// Function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
void printPostOrder(struct Node* node)
{
    if (node == NULL)
        return;
 
    // Recurr to left subtree
    printPostOrder(node->left);
 
    //Recurr to right subtree
    printPostOrder(node->right);
     
    // Print data of root
    cout << node->data << " ";
}
 
int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
 
      // Function call
    cout << "\nPreorder traversal of binary tree is \n";
    printPostOrder(root);
 
    return 0;
}