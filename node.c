#include<stdio.h>
#include<stdlib.h>

struct node
{
   int data;
   struct node* next;
};

void Display(struct node* head){
    printf("The data of the node: ");
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }

}

struct node* insertAtFirst(struct node *head,int data){
    struct node* newNode;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=head;
    return newNode;
}

/*struct node* insertAtLast(struct node* head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
     if (newNode == NULL) { // Check for malloc failure
        perror("Memory allocation failed");
        exit(1); 
    }
    newNode->data = data;
    newNode->next = NULL; // New node will be the last

    if (head == NULL) { // If the list is empty
        return newNode;
    }
}*/

int main(){
struct node* head;
head=(struct node*)malloc(sizeof(struct node));
head->data=33;
head->next=NULL;

struct node* first;
first=(struct node*)malloc(sizeof(struct node));
first->data=35;
first->next=NULL;
head->next=first;

struct node* second;
second=(struct node*)malloc(sizeof(struct node));
second->data=33;
second->next=NULL;
first->next=second;

struct node* Third;
Third=(struct node*)malloc(sizeof(struct node));
Third->data=45;
Third->next=NULL;
second->next=Third;

struct node* four;
four=(struct node*)malloc(sizeof(struct node));
four->data=60;
four->next=NULL;
Third->next=four;

Display(head);
int data;
printf("\nenter your inserting data at first: \n");
scanf("%d",&data);
head=insertAtFirst(head,data);
Display(head);

/*printf("\nenter your inserting data at last: \n");
scanf("%d",&data);
head=insertAtLast(head,data);
Display(head);
    return 0;*/
}