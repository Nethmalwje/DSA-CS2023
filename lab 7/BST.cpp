#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
      if (root != NULL) {
        traverseInOrder(root->left); //travel till found
        cout << root->key <<" ";
        //("%d ", root->key);
        traverseInOrder(root->right);
    }
}
struct node *newNode(int item){                                                 
   struct node *temp = (struct node *)malloc(sizeof(struct node)); //new node object
   temp->key = item;
   temp->left = temp->right = NULL;
   return temp;
}

struct node* minValueNode(struct node* node)
{
    struct node* current = node;

    // loop down to find the leftmost leaf 
    while (current && current->left != NULL)
        current = current->left;

    return current;
}


// Insert a node
struct node *insertNode(struct node *node, int key) {

  if (node == NULL) return newNode(key);
  //instertingg ot left
      if (key < node->key)
         node->left = insertNode(node->left, key);
  //inserting to right       
      else if (key > node->key)
         node->right = insertNode(node->right, key);
   return node;
}


// Deleting a node
struct node *deleteNode(struct node *root, int key)  {
    // base case
    if (root == NULL)
        return root;

    
    if (key < root->key)
        root->left = deleteNode(root->left, key);

   
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        // node has no children
        if (root->left == NULL and root->right == NULL)
            return NULL;

        // node has only one child
        else if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        
        struct node* temp = minValueNode(root->right);

       
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}


// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}
