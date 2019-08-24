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

struct node *reverseinK(struct node *h, int k)
{
    int count = 0;
    struct node *prev = NULL;
    struct node *curr = h;
    struct node *nextt = NULL;
    while (curr && count < k)
    {
        nextt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextt;
        count++;
    }
    if (nextt)
        h->next = reverseinK(nextt, k);

    return prev;
}

int main()
{
    struct node *head = NULL;
    int k;
    insertAtEnd(&head, 10);
    insertAtEnd(&(head->next), 20);
    insertAtEnd(&(head->next->next), 30);
    insertAtEnd(&(head->next->next->next), 40);
    insertAtEnd(&(head->next->next->next->next), 50);
    insertAtEnd(&(head->next->next->next->next->next), 60);
    struct node *curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\nEnter Size of K : ");
    scanf("%d", &k);
    head = reverseinK(head, k);
    curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}