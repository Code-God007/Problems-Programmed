#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void insertAtEnd(struct node **head, int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->next = NULL;
    if (*head == NULL)
    {
        *head = n;
    }
    else
    {
        struct node *curr = *head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = n;
    }
}

struct node *reverse(struct node *curr)
{
    struct node *first = curr;
    struct node *second = NULL;
    if (first)
    {
        second = first->next;
    }
    if (second == NULL)
    {
        return first;
    }
    struct node *h = reverse(first->next);
    first->next = second->next;
    second->next = first;
    return h;
}

int main()
{
    struct node *head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&(head->next), 20);
    insertAtEnd(&(head->next->next), 30);
    printf("\n%d %d %d\n", head->data, head->next->data, head->next->next->data);

    head = reverse(head);
    printf("\n%d %d %d\n", head->data, head->next->data, head->next->next->data);
}
