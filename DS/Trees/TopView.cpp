#include <iostream>
#include <queue>
#include <map>
using namespace std;

typedef struct Tree
{
    int data;
    int distance;
    struct Tree *left;
    struct Tree *right;
} Tree;

Tree *root = NULL;

Tree *BST(Tree *root, int data)
{
    if (root == NULL)
    {
        Tree *node = (Tree *)malloc(sizeof(struct Tree));
        node->data = data;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    else if (root->data > data)
    {
        root->left = BST(root->left, data);
    }
    else if (root->data < data)
    {
        root->right = BST(root->right, data);
    }
    return root;
}

void topView()
{
    queue<Tree *> q;
    map<int, int> m;
    map<int, int>::iterator it;
    int dist = 0;
    root->distance = dist;
    q.push(root);

    while (!q.empty())
    {
        dist = root->distance;
        if (m.find(dist) == m.end())
        {
            m[dist] = root->data;
        }
        if (root->left)
        {
            root->left->distance = dist - 1;
            q.push(root->left);
        }
        if (root->right)
        {
            root->right->distance = dist + 1;
            q.push(root->right);
        }
        q.pop();
        root = q.front();
    }
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << it->second << " ";
    }
}

void PreOrder(struct Tree *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

int main()
{

    root = BST(root, 10);
    root = BST(root, 6);
    root = BST(root, 4);
    root = BST(root, 12);
    root = BST(root, 7);
    root = BST(root, 11);
    root = BST(root, 14);
    root = BST(root, 5);
    root = BST(root, 13);
    root = BST(root, 3);
    root = BST(root, 15);
    // PreOrder(root);
    topView();
}
