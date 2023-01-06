#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
    struct Node *head1=NULL;
    struct Node *head2=NULL;

void append(struct Node **head_ref,int new_data)
{
    struct Node *last;
    struct Node *new_node=(struct Node *)malloc(sizeof(struct Node));
    new_node->data=new_data;
    new_node->next=NULL;
    if(*head_ref==NULL)
    {
        *head_ref=new_node;
    }
    else
    {
        last = *head_ref;
        while(last->next!=NULL)
            last=last->next;
        last->next=new_node;
    }
}

void printlist(struct Node *node)
{
    while(node!=NULL)
    {
        printf("%d ",node->data);
        node=node->next;
    }
}
void end_del(struct Node **head_ref)
{
    struct Node *ptr, *temp;
    if(*head_ref==NULL)
    {
        printf("\nList is empty\n");
    }
    else if( ((*head_ref)->next) == NULL)
    {
        *head_ref= NULL;
        free(head_ref);


    }
    else
    {
        temp = *head_ref;
        ptr = *head_ref;
        while((ptr->next) !=NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);
        printf("Deleted node from the end of the list\n");
    }
}
void beg_del(struct Node **head_ref)
{
    struct Node *ptr;
    if(*head_ref == NULL)
    {
       printf("\nList is empty\n");
    }
    else
    {
        ptr = *head_ref;
        printf("\n%d is deleted\n", ptr->data);
        *head_ref = ((*head_ref)->next);
        free(ptr);
    }
}
void item_del(struct Node **head)
{
    int x;
    printf("\nEnter the element\n");
            scanf("%d",&x);
    int pos=0,i,flag=0;
     struct Node *ptr,*temp, *ptr1;
     ptr=*head;

      while(ptr!=NULL)
    {
        pos++;

        if(ptr->data==x)
        {
         flag=1;
         break;
        }
        ptr=ptr->next;
    }
    if(flag==1)
        {
             ptr = *head;
        temp = *head;
        for(i=0;i<pos-1;i++)
        {
            ptr=temp;
            temp = temp->next;
        }
        ptr->next = temp ->next;
        free(temp);
        printf("\nDeleted node");
    }
    else{
        printf("Element not found");
    }

}
void reverse(struct Node **head_ref)
{
    //int next, prev;
    struct Node *current, *next, *prev;
    current= *head_ref;
    while(current!=NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current=next;

    }
    *head_ref=prev;
}
void sort(struct Node **head)
{
    struct Node *temp, *ptr;
    int x;
    temp = *head;
    while(temp!=NULL)
    {
        ptr=temp->next;
        while(ptr!=NULL)
        {
          if(temp->data > ptr->data)
            {
            x=temp->data;
            temp->data=ptr->data;
            ptr->data = x;
            }
          ptr=ptr->next;
        }
        temp = temp->next;
    }
}

void concatenate(struct Node *a,struct Node *b)
{
    if(a!=NULL && b!=NULL)
    {
        if(a->next==NULL)
            a->next = b;
        else
            concatenate(a->next, b);
    }
    else
    {
        printf("Either of the linked list is null\n");
    }
}

int main()
{
    int size=0;
    int choice,x;
    int position;

    while(1)
    {
        printf("\n\nMenu\n");
        printf("1.sort\n2.reverse\n3.concatenate 2 lists\n4.Insert at end for first list\n5.Display list 1\n6.Insert at end for second list\n7.Display list 2\n8.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            sort(&head1);
            break;
        case 2:
            reverse(&head1);
            break;
        case 3:
            concatenate(head1, head2);
            break;
        case 5:
            printf("Created list 1 is: ");
            printlist(head1);
            break;
        case 4:
            printf("\nEnter the element\n");
            scanf("%d",&x);
            size++;
            append(&head1, x);
            break;
        case 6:
            printf("\nEnter the element\n");
            scanf("%d",&x);
            size++;
            append(&head2, x);
            break;
        case 7:
            printf("Created list 2 is: ");
            printlist(head2);
            break;

        case 8:exit(0);
        /*case 6:
            count(&head);
            break;*/

        default:
            printf("\nWrong choice\n");
        }
    }
    return 0;
}

