#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;

void Push(int x)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = x;
    n->next = top;
    top = n;
}

void Pop()
{
    if (top == NULL)
    {
        return;
    }
    struct node *temp = top;
    top = top->next;
    free(temp);
}

int Top()
{
    return top->data;
}
bool IsEmpty()
{
    if (top == NULL)
        return true;
    else
        return false;
}

void Print()
{
    struct node *temp = top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Push(2);
    Print();
    Push(5);
    Print();
    Push(7);
    Print();
    Pop();
    Print();
    Push(10);
    Print();
    printf("\n%d", Top());
    printf("\n%s", IsEmpty() ? "true" : "false");
}