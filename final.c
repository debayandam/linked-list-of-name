#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void insertatbeg(char value[30]);
void insertatend(char value[30]);
void insertatpos(char value[30],int position);
void removefromfirst();
void removeatend();
void removeatpos(int position);
void display();
void update(char value[30],char value1[30]);
int checkempty();
void close(void);
struct Node
{
    char data[30];
    char n;
    struct Node *next;
}*head=NULL;
struct Node *current=NULL;
int main()
{
    int choice;
    char c,value[30],value1[30];
    do
    {
        printf("Enter\n1-Insert\n2-Remove\n3-Update\n4-Display\n5-Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            {
                int x;
                printf("Enter\n1-Insert at beginning\n2-Insert at end\n3-Insert at position\n");
                scanf("%d",&x);
                printf("Enter name to be inserted: \n");
                scanf("%s",&value);
                switch(x)
                {
                case 1:
                    {
                        insertatbeg(value);
                        break;
                    }
                case 2:
                    {
                        insertatend(value);
                        break;
                    }
                case 3:
                    {
                        int position;
                        printf("Enter position to insert a value(counted from 0): \n");
                        scanf("%d",&position);
                        insertatpos(value,position);
                        break;
                    }
                default:
                    {
                        printf("Enter valid choice: \n");
                        break;
                    }
                }
                break;
            }
        case 2:
              {
                  int x;
                  printf("Enter\n1-Delete at beginning\n2-Delete at end\n3-Delete at position\n");
                  scanf("%d",&x);
                  switch(x)
                  {
                  case 1:
                    {
                        removefromfirst();
                        break;
                    }
                  case 2:
                    {
                        removeatend();
                        break;
                    }
                  case 3:
                    {
                        int position;
                        printf("Enter position to be removed starting from 1: \n");
                        scanf("%d",&position);
                        removeatpos(position);
                        break;
                    }
                  default:
                    {
                        printf("Enter valid choice: \n");
                        break;
                    }
                  }
                  break;
              }
        case 3:
            {
                printf("Enter the name to be updated: \n");
                scanf("%s",value);
                printf("Enter the new name: \n");
                scanf("%s",value1);
                update(value[30],value1[30]);
                break;
            }
        case 4:
            {
                display();
                break;
            }
        case 5:
            {
                close();
                exit(0);
                break;
            }
        default:
            {
                printf("Enter valid choice: \n");
                break;
            }
        }
        printf("Enter 'Y' or 'y' to continue else any letter: \n");
        fflush(stdin);
        c=getche();
        printf("\n");
    }
    while(c=='Y'||c=='y');
return(0);
}
void insertatbeg(char value[30])
{
    struct Node *newNumber;
    newNumber=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNumber->data,value);
    if(head==NULL)
    {
        newNumber->next=NULL;
        head=newNumber;
    }
    else
    {
        newNumber->next=head;
        head=newNumber;
    }
    printf("Given name %s is inserted at beginning successfully.\n",value);
}
void insertatend(char value[30])
{
    struct Node *newNumber;
    newNumber=(struct Node *)malloc(sizeof(struct Node));
    strcpy(newNumber->data,value);
    newNumber->next=NULL;
    if(head==NULL)
    {
        head=newNumber;
    }
    else
    {
        struct Node *temp;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newNumber;
    }
     printf("Given name %s is inserted at end successfully.\n",value);
}
void insertatpos(char value[30],int position)
{
    struct Node *newNumber,*temp;
    int count,flag;
    newNumber=(struct Node *)malloc(sizeof(struct Node));
    strcpy(newNumber->data,value);
    temp=head;
    flag=checkempty();
    if(flag==1)
    {
        int flag1=0;
        count=0;
        while(temp!=NULL)
        {
            if(count==position-1)
            {
                flag1=1;
                newNumber->next=temp->next;
                temp->next=newNumber;
            }
            else
            {
                temp=temp->next;
            }
            count++;
        }
        if(flag1==0)
        {
            printf("Entered position is not available.\n");
        }
        else
        {
            printf("Given name %s is inserted at position %d successfully.\n",value,position);
        }
    }
    else
    {
        printf("List is empty.\n");
    }
}
void removefromfirst()
{
    int flag=checkempty();
    if(flag==1)
    {
        struct Node *temp;
        temp=head;
        if(temp->next==NULL)
        {
            head=NULL;
            free(temp);
        }
        else
        {
            head=temp->next;
            free(temp);
        }
        printf("Deleted successfully.\n");
    }
    else
    {
        printf("List is empty.\n");
    }
}
void removeatend()
{
    int flag=checkempty();
    if(flag==1)
    {
        if(head->next==NULL)
        {
            head=NULL;
        }
        else
        {
            struct Node *temp=head,*temp1;
            while(temp->next!=NULL)
            {
                temp1=temp;
                temp=temp->next;
            }
            temp1->next=NULL;
            free(temp);
        }
        printf("Deleted successfully.\n");
    }
    else
    {
        printf("List empty.Try again.\n");
    }
}
void removeatpos(int position)
{
    int flag=checkempty();
    if(flag==1)
    {
        int count=0,flag1=0,i;
        struct Node *temp=head;
        if(position==1)
        {
            head=temp->next;
            free(temp);
            return;
        }
        for(i=0;i<position-2;i++)
        {
            temp=temp->next;
        }
        struct Node *temp1=temp->next;
        temp->next=temp1->next;
        free(temp1);
        printf("Deleted successfully.\n");
    }
    else
    {
        printf("List is empty.\n");
    }
}
void update(char value[30],char value1[30])
{
    int pos=0;
    if(head==NULL)
    {
        printf("Linked list not initialized.\n");
        return;
    }
    current=head;
    while(current->next==NULL)
    {
        if(current->data!=value)
        {
            (current->n==value1);
            printf("%s found at position %d,replaced with %s\n",value,pos,value1);
            return;
        }
        current=current->next;
        pos++;
    }
    printf("%s does not exist in the list.\n",value);
}
void display()
{
    int flag=checkempty();
    if(flag==1)
    {
        struct Node *temp;
        temp=head;
        while(temp->next!=NULL)
        {
            printf("%s-> ",temp->data);
            temp=temp->next;
        }
        printf("%s",temp->data);
        printf("\n");
    }
    else
    {
        printf("No list available.\n");
    }
}
int checkempty()
{
    if(head==NULL)
        return 0;
    else
        return 1;
}
void close(void)
{
     printf("This project has been created by DEBAYAN DAM.\n");
}
