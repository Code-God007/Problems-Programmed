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

void removeDuplicates(struct node *curr)
{
    struct node *ptr = curr;
    struct node *next_next = NULL;
    if (ptr == NULL)
    {
        return;
    }
    while (ptr->next != NULL)
    {
        if (ptr->data == ptr->next->data)
        {
            next_next = ptr->next->next;
            free(ptr->next);
            ptr->next = next_next;
        }
        else
        {
            ptr = ptr->next;
        }
    }
}

int main()
{
    struct node *head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&(head->next), 10);
    insertAtEnd(&(head->next->next), 30);
    insertAtEnd(&(head->next->next->next), 30);
    insertAtEnd(&(head->next->next->next->next), 30);
    insertAtEnd(&(head->next->next->next->next->next), 60);
    struct node *curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    removeDuplicates(head);

    printf("\n");
    curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}