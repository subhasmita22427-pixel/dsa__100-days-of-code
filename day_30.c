#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coef, exp;
    struct node *next;
};

int main()
{
    struct node *head = NULL, *temp, *ptr;
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        ptr = (struct node*)malloc(sizeof(struct node));

        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &ptr->coef, &ptr->exp);

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

    printf("Polynomial:\n");

    temp = head;
    while(temp != NULL)
    {
        if(temp->exp == 0)
            printf("%d", temp->coef);
        else if(temp->exp == 1)
            printf("%dx", temp->coef);
        else
            printf("%dx^%d", temp->coef, temp->exp);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}
