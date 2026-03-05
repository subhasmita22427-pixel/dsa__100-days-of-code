#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp, *ptr;
    int n, i, k;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        ptr = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &ptr->data);
        ptr->next = NULL;

        if(head == NULL)
        {
            head = ptr;
            temp = head;
        }
        else
        {
            temp->next = ptr;
            temp = ptr;
        }
    }

    printf("Enter k: ");
    scanf("%d", &k);

    k = k % n;

    temp->next = head;   // make circular

    int steps = n - k;
    temp = head;

    for(i = 1; i < steps; i++)
        temp = temp->next;

    head = temp->next;
    temp->next = NULL;

    printf("Rotated List:\n");
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
