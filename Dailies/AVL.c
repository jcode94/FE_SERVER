/**
 * @file AVL.c
 * @author Justice
 * @brief How To Code an AVL
 * @version 0.1
 * @date 2021-03-23
 * @copyright Copyright (c) 2021
 */

//Preprocessor Directives
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define IMPOSSIBLE 999999

//Structs
typedef struct Node Node;
struct Node {
    int value;
    Node * right;
    Node * left;
    Node * parent;
    // int size; //Number of nodes under root
    int height; //depth, the number of nodes in the largest sub-tree
};

//Prototypes
Node * createNode(int value);
Node * insert(Node * root, int value);
Node * delete(Node * root, int value);
void destroyNode(Node * root);
Node * findSmallest(Node * root);
int balanceFactor(Node * root); //Returns the differenct between the left and right child
int max(Node * leftRoot, Node * rightRoot); //Find the largest child

//Traversal functions
void postOrder(Node * root);
void preOrder(Node * root);
void inOrder(Node * root);
bool contains(Node * root, int value);
void destroyTree(Node * root);
Node* rightRot(Node* root);
Node* leftRot(Node* root);

//Main
int main(){
    Node * root = NULL;
    root = insert(root, 7);
    root = insert(root, 8);
    root = insert(root, 9);
    
    printf("Pre order: ");
    preOrder(root);
    printf("\n");
    
    // root = insert(root, 6);
    // root = insert(root, 5);
    // root = insert(root, 8);
    printf("Pre order after balancing: ");
    preOrder(root);
    printf("\n");
    
    return 0;
}

/* 1. Perform the normal BST insertion */
/* 2. Update height of this ancestor node */
/* 3. Get the balance factor of this 
    ancestor node to check whether this node became unbalanced */
// If this node becomes unbalanced, then there are 4 cases
    // Left Left Case
    // Right Right Case
    // Left Right Case
    // Right Left Case
    
/* return the (unchanged) node pointer */

//Functions
Node * createNode(int value){
    Node * ret = (Node*)malloc(sizeof(Node));
    ret->value = value;
    ret->left = ret->right = ret->parent = NULL;
    ret->height = 0;
    return ret;
}

Node * insert(Node * root, int value)
{
    // empty tree
    if (root == NULL)
        return createNode(value);

    if (root->value == value)
        return root;
    
    if (root->value < value) {
        root->right = insert(root->right, value);
        if (root->right->parent == NULL) {
            root->right->parent = root;
            printf("%d's parent = %d\n", root->right->value, root->right->parent->value);
        }
    }        
    if (root->value > value) {
        root->left = insert(root->left, value);
        if (root->left->parent == NULL) {
            root->left->parent = root;
            printf("%d's parent = %d\n", root->left->value, root->left->parent->value);
        }
    }   
    root->height = max(root->left, root->right) + 1;
    
    int bf = balanceFactor(root);
    
    // LL case
    if (bf < -1 && balanceFactor(root->left) < 0)
    {
        rightRot(root);
    }
    
    // LR case
    else if (bf < -1 && balanceFactor(root->left) > 0)
    {
        leftRot(root->left);
        rightRot(root);
    }
    
    // RR case
    else if (bf > 1 && balanceFactor(root->right) > 0)
    {
        leftRot(root);
    }
    
    // RL case
    else if (bf > 1 && balanceFactor(root->right) < 0)
    {
        rightRot(root->right);
        leftRot(root);
    }
            
    return root;        
}

Node* rightRot(Node* cur)
{
    Node* parent = cur->parent; // curNode's parent
    Node* child  = cur->left;   // curNode's right child
    
    if (child == NULL)
        return NULL; // Can't rotate
    
    Node* grandChild = child->right; // getting node to move 
    
    child->parent = parent; // closing the gap
    
    // Find which side of the tree the move is happening on
    if (parent != NULL) {
        if (parent->left == cur) {
            parent->left = child;
        }
        else {
            parent->right = child;
        }
    }
    
    // Set the pointers of child and current to point to each other
    // but the relationship is inverted
    child->right = cur;
    cur->parent = child;
    
    cur->left = grandChild;
    if (grandChild != NULL)
        grandChild->parent = cur;
        
    return child;
}

Node* leftRot(Node* cur)
{
    Node* parent = cur->parent; // curNode's parent
    Node* child  = cur->right;   // curNode's right child
    
    if (child == NULL)
        return NULL; // Can't rotate
    
    Node* grandChild = child->left; // getting node to move 
    
    child->parent =  cur->parent; // closing the gap
    
    // Find which side of the tree the move is happening on
    if (parent != NULL)
    {
        if (parent->right == cur) {
            parent->right = child;
        }
        else {
            parent->left = child;
        }
    }
    // Set child's parent to parent of current
    child->parent = parent;
    
    // Set the pointers of child and current to point to each other
    // but the relationship is inverted
    child->left = cur;
    cur->parent = child;
    
    cur->right = grandChild;
    if (grandChild != NULL)
        grandChild->parent = cur;
        
    return child;
}

int max(Node * leftRoot, Node * rightRoot)
{
    // No children
    if (leftRoot == NULL && rightRoot == NULL)
        return 0;
    
    // 1 child
    if (leftRoot == NULL || rightRoot == NULL)
    {    
        if (leftRoot == NULL)
            return rightRoot->height;
        else
            return leftRoot->height;
    }
        
    // 2 children
    int left = max(leftRoot->left, leftRoot->right) + 1;
    int right = max(rightRoot->left, rightRoot->right) + 1;
    
    // Return the larger height of the two subtrees
    if (left > right) return left;
    else return right;
}

int getHeight(Node* root)
{
    if (root == NULL)
        return 0;
        
    return root->height;
}

Node * delete(Node * root, int value);
void destroyNode(Node * root);
Node * findSmallest(Node * root);

int balanceFactor(Node * root)
{
    if (root == NULL)
        return IMPOSSIBLE;
    if (root->left == NULL && root->right == NULL)
        return 0;
    if (root->left == NULL || root->right == NULL)
    {
        if (root->left == NULL) return balanceFactor(root->right) + 1;
        if (root->right == NULL) return balanceFactor(root->left) - 1;
    }
    
    return root->right->height - root->left->height;
}

//Traversal functions
void postOrder(Node * root);
void preOrder(Node * root)
{
    if (root == NULL) return;
    printf(" %d:%d ", root->value, root->height);
    preOrder(root->left);
    preOrder(root->right);
}    
void inOrder(Node * root);
bool contains(Node * root, int value);
void destroyTree(Node * root);
