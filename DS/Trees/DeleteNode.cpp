#include <iostream>
#include <queue>
using namespace std;

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} treenode;

// Creating a new node
treenode *newNode(int data)
{
    treenode *temp = (treenode *)malloc(sizeof(treenode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Checking Input
void inOrder(treenode *root)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
}

// Initializing values in Tree
treenode *make(treenode *root)
{
    root = newNode(10);
    root->left = newNode(11);
    root->left->left = newNode(7);
    root->left->right = newNode(12);
    root->right = newNode(9);
    root->right->left = newNode(15);
    root->right->right = newNode(8);
    return root;
}

void deleteDeepest(treenode *root, treenode *temp)
{
    queue<treenode *> q;
    treenode *t = NULL;
    q.push(root);
    while (!q.empty())
    {
        t = q.front();
        q.pop();

        if (t == temp)
        {
            t = NULL;
            free(temp);
            return;
        }

        if (t->right)
        {
            if (t->right == temp)
            {
                t->right = NULL;
                free(temp);
                return;
            }
            else
                q.push(t->right);
        }
        if (t->left)
        {
            if (t->left == temp)
            {
                t->left = NULL;
                free(temp);
                return;
            }
            else
                q.push(t->left);
        }
    }
}

treenode *deleteNode(treenode *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
    {
        if (root->data == key)
            return NULL;
        else
            return root;
    }

    treenode *temp;
    treenode *keyNode = NULL;
    queue<treenode *> q;
    q.push(root);

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == key)
        {
            keyNode = temp;
        }

        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    if (keyNode != NULL)
    {
        int x = temp->data;
        deleteDeepest(root, temp);
        // keyNode->data = x;
    }
    return root;
}

int main()
{
    treenode *root = NULL;
    root = make(root);
    inOrder(root);
    int key = 9;
    root = deleteNode(root, key);
    printf("\n");
    inOrder(root);
}
