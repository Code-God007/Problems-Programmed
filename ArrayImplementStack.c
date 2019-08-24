#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 101

int A[MAX_SIZE];
int top = -1;

void Push(int x)
{
    A[++top] = x;
}

void Pop()
{
    top--;
}

int Top()
{
    return A[top];
}
bool IsEmpty()
{
    if (top == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Print()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main()
{
    Push(2);
    Print();
    Push(10);
    Print();
    Push(5);
    Print();
    Pop();
    Print();
    Push(7);
    Print();
    printf("\n%d", Top());
    printf("\n%s", IsEmpty() ? "true" : "false");
    return 0;
}
