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
 
void printPreOrder(struct Node* node)
{
    if (node == NULL)
        return;
 
    // Print data of root
    cout << node->data << " ";
 
    // Recurr to left subtree
    printPreOrder(node->left);
 
    //Recurr to right subtree
    printPreOrder(node->right);
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
    printPreOrder(root);
 
    return 0;
}