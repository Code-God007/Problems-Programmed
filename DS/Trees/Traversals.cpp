#include <iostream>
#include <stack>
using namespace std;

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} Tree;

Tree *createTree(Tree *root, int data)
{
    if (root == NULL)
    {
        Tree *node = (Tree *)malloc(sizeof(Tree));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    if (root->data > data)
    {
        root->left = createTree(root->left, data);
    }
    if (root->data < data)
    {
        root->right = createTree(root->right, data);
    }
    return root;
}

// Recursive Methods for Traversal

void InOrder(Tree *root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}

void PreOrder(Tree *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(Tree *root)
{
    if (root == NULL)
        return;
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}

// Iterative methods for Traversal

void InOrderIterative(Tree *root)
{
    if (root == NULL)
        return;
    stack<Tree *> s;
    while (!s.empty() || root)
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
        printf("%d ", s.top()->data);
        root = s.top()->right;
        s.pop();
    }
}

void PreOrderIterative(Tree *root)
{
    if (root == NULL)
        return;
    stack<Tree *> s;
    while (!s.empty() || root)
    {
        while (root)
        {
            printf("%d ", root->data);
            s.push(root);
            root = root->left;
        }
        root = s.top()->right;
        s.pop();
    }
}

void PostOrderIterative(Tree *root)
{
    if (root == NULL)
        return;
    stack<Tree *> s1;
    stack<Tree *> s2;
    Tree *node = root;
    while (!s1.empty() || node)
    {
        if (node)
        {
            s1.push(node);
            s2.push(node);
            node = node->right;
        }
        else
        {
            node = s1.top();
            s1.pop();
            node = node->left;
        }
    }
    while (!s2.empty())
    {
        printf("%d ", s2.top()->data);
        s2.pop();
    }
}

int main()
{
    Tree *root = NULL;

    root = createTree(root, 5);
    root = createTree(root, 10);
    root = createTree(root, 3);
    root = createTree(root, 11);
    root = createTree(root, 2);
    root = createTree(root, 9);
    root = createTree(root, 4);
    PostOrderIterative(root);
}
