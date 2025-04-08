#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *createnewnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
struct node *InsertAtfirst(struct node *head, int data)
{
    struct node *newnode = createnewnode(data);
    if (head != NULL)
    {
        newnode->next = head;
        head->prev = newnode;
    }
    return newnode;
}

struct node *InsertAtlast(struct node *head, int data)
{
    struct node *newnode = createnewnode(data);
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
    return head;
}

struct node *InsertAtspecficposition(struct node *head, int index, int data)
{
    struct node *newnode = createnewnode(data);
    struct node *temp = head;
    if (index = 0)
    {
        return InsertAtfirst(head, data);
    }
    else
    {
        int i = 1;
        while (i != index - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        return head;
    }
}
struct node *DeleteAtfirst(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct node *temp = head;
    head = temp->next;
    temp->next->prev = NULL;
    free(temp);
    return head;
}

struct node *DeleteAtLast(struct node *head)
{
    struct node *temp = head;
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        free(temp);
        temp = NULL;
        return head;
    }
}

struct node *DeleteAtspecificposition(struct node *head, int pos)
{
    struct node *temp = head;
    if (head == NULL)
    {
        return NULL;
    }
    else
    {
        int i = 1;
        while (i != pos)
        {
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
}

struct node *display(struct node *head)
{
    if (head == NULL)
    {
        printf("\nList is empty");
        return NULL;
    }
    struct node *temp = head;
    printf("\nHead->");
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;
    int data, pos, index, choice;
    do
    {
        printf("1.insert at first\n");
        printf("2.insert at last\n");
        printf("3.insertat index\n");
        printf("4.delete at first\n");
        printf("5.delete at last\n");
        printf("6.delete at specific position\n");
        printf("Enter your  choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to insertted at first:"); 
            scanf("%d", &data);
            head = InsertAtfirst(head, data);
            display(head);
            break;

        case 2:
            printf("Enter the data to insertted at last:");
            scanf("%d", &data);
            head = InsertAtlast(head, data);
            display(head);
            break;

        case 3:
            printf("entre the index to insert the data:");
            scanf("%d", &pos);
            printf("ENter the data to insertatpos:");
            scanf("%d", &data);

            head = InsertAtspecficposition(head, data, pos);
            display(head);
            break;

        case 4:
            head = DeleteAtfirst(head);
            display(head);
            break;

        case 5:
            head = DeleteAtLast(head);
            display(head);
            break;

        case 6:
            printf("Enter the index to be deleted:");
            scanf("%d", &index);
            display(head);
            break;

        default:
            printf("Invalid Number data index");
        }
    } while (choice != 7);
}
// int main(){

// }
