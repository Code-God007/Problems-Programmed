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

struct node *returnMiddle(struct node *head)
{
    struct node *slow_ptr = head;
    struct node *fast_ptr = head;
    if (head != NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
    }
    return slow_ptr;
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
    insertAtEnd(&(head->next->next->next), 40);
    insertAtEnd(&(head->next->next->next->next), 50);
    // insertAtEnd(&(head->next->next->next->next->next), 60);

    //printing list
    struct node *curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }

    struct node *mid = NULL;
    mid = returnMiddle(head);
    //printing middle element
    printf("\n%d\n", mid->data);

    struct node *cur = head;
    while (cur->next != mid)
    {
        cur = cur->next;
    }
    cur->next = NULL;

    //printing first half
    curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");

    mid = reverse(mid);

    //printing second half
    curr = mid;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    struct node *h = head;
    while (head != NULL && mid != NULL)
    {
        struct node *temp = head->next;
        head->next = mid;
        head = temp;

        temp = mid->next;
        mid->next = head;
        mid = temp;
    }
    printf("\n");
    curr = h;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
}