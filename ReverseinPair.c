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

void reversePair(struct node *head)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (head == NULL || head->next == NULL)
    {
        return;
    }
    else
    {
        temp->data = head->data;
        head->data = head->next->data;
        head->next->data = temp->data;
        reversePair(head->next->next);
    }
}

int main()
{
    struct node *head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&(head->next), 20);
    insertAtEnd(&(head->next->next), 30);
    insertAtEnd(&(head->next->next->next), 40);
    insertAtEnd(&(head->next->next->next->next), 50);
    printf("\n%d %d %d %d %d\n", head->data, head->next->data, head->next->next->data, head->next->next->next->data, head->next->next->next->next->data);

    reversePair(head);
    printf("\n%d %d %d %d %d\n", head->data, head->next->data, head->next->next->data, head->next->next->next->data, head->next->next->next->next->data);
}