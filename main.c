#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    int id,day,month,year;
    char fname[20];
    char lname[20];
    float score;
    struct student *next;
};
struct student *head=NULL; //head pointer of linked list
int num_inserted_arr=0;
int num_inserted_list=0;
int N=0;
int ii; //counter in for loop

int main()
{
    int j,choice1,choice2,choice3;
    system("color 3");
    struct student *ptr=NULL;
    printf("\n**************************************\n");
    printf("\n               WELCOME                \n");
    printf("\n**************************************\n");
    printf("\n\n Enter the number of students required to be inserted: ");
    scanf("%d",&N);
    system("CLS");
    ptr=(struct student*)calloc(N,sizeof(struct student));
    printf("\n--------------------------------------\n");
    printf("\n 1.Insert using Linked List \n");
    printf("\n 2.Insert using Array \n");
    printf("\n 3.Exit \n");
    printf("\n\nEnter your choice: "); scanf("%d",&choice1);
        switch(choice1)
        {
        case 1:
            for(j=0;j<N;j++)
            {
                printf("\n--------------------------------------\n");
                printf("\n 1.Insert in the beginning \n");
                printf("\n 2.Insert in the end \n");
                printf("\n 3.Insert in the middle \n");
                printf("\nEnter your choice: ");
                scanf("%d",&choice2);
                system("CLS");
                switch(choice2)
                {
                    case 1:
                        insert_list_begin();
                        num_inserted_list++;
                        system("pause");
                        system("CLS");
                        break;
                    case 2:
                        insert_list_end();
                        num_inserted_list++;
                        system("pause");
                        system("CLS");
                        break;
                    case 3:
                        insert_list_mid();
                        num_inserted_list++;
                        system("pause");
                        system("CLS");
                        break;
                    default:
                        printf("\n Wrong Choice\n");
                        system("pause");
                        system("CLS");
                        break;
                }
            }
            break;
        case 2:
            for(j=0;j<N;j++)
            {
                printf("\n--------------------------------------\n");
                printf("\n 1.Insert in the beginning \n"); printf("\n 2.Insert in the end \n");
                printf("\n 3.Insert in the middle \n");
                printf("\nEnter your choice: "); scanf("%d",&choice3);
                system("CLS");
                switch(choice3)
                {
                    case 1:
                        insert_array_begin(ptr,num_inserted_arr);
                        num_inserted_arr++;
                        system("pause");
                        system("CLS");
                        break;
                    case 2:
                        insert_array_end(ptr,num_inserted_arr);
                        num_inserted_arr++;
                        system("pause");
                        system("CLS");
                        break;
                    case 3:
                        insert_array_mid(ptr,num_inserted_arr);
                        num_inserted_arr++;
                        system("pause");
                        system("CLS");
                        break;
                    default:
                        printf("\n Wrong Choice\n");
                        system("pause");
                        system("CLS");
                        break;
                }
            }
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\n Wrong Choice\n");
            break;
        }
    switch(choice1)
        {
        case 1:
                display_list();
                break;
        case 2:
                display_array(ptr,num_inserted_arr);
                break;
        }
    return 0;
}
void insert_list_begin()
{
    struct student *temp;
    temp=(struct student *)malloc(sizeof(struct student));
    if(temp==NULL)
    {
        printf("\n Out of Memory Space\n");
        return;
    }
    printf("\n Enter the data of student:\n");
    printf(" id: "); scanf("%d",&temp->id);
    printf("\n first name: ");     scanf("%s",temp->fname);
    printf(" last name: ");        scanf("%s",temp->lname);
    printf("\n day of birth: ");   scanf("%d",&temp->day);
    printf(" month of birth: ");   scanf("%d",&temp->month);
    printf(" year of birth: ");    scanf("%d",&temp->year);
    printf("\n Score: ");          scanf("%f",&temp->score);
    temp->next =NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        temp->next=head;
        head=temp;
    }
}
void insert_list_end()
{
    struct student *temp,*ptr;
    temp=(struct student *)malloc(sizeof(struct student));
    if(temp==NULL)
    {
        printf("\n Out of Memory Space \n");
        return;
    }
    printf("\n Enter the data of student:\n");
    printf(" id: ");               scanf("%d",&temp->id);
    printf("\n first name: ");     scanf("%s",temp->fname);
    printf(" last name: ");        scanf("%s",temp->lname);
    printf("\n day of birth: ");   scanf("%d",&temp->day);
    printf(" month of birth: ");   scanf("%d",&temp->month);
    printf(" year of birth: ");    scanf("%d",&temp->year);
    printf("\n Score: ");          scanf("%f",&temp->score);
    temp->next =NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
        ptr=head;
        while(ptr->next !=NULL)
        {
            ptr=ptr->next ;
        }
        ptr->next =temp;
    }
}
void insert_list_mid()
{
    struct student *ptr,*temp;
    int i;
    int pos=num_inserted_list/2;
    temp=(struct student *)malloc(sizeof(struct student));
    if(temp==NULL)
    {
        printf("\n Out of Memory Space:\n");
        return;
    }
    printf("\n Enter the data of student:\n");
    printf(" id: "); scanf("%d",&temp->id);
    printf("\n first name: ");     scanf("%s",temp->fname);
    printf(" last name: ");        scanf("%s",temp->lname);
    printf("\n day of birth: ");   scanf("%d",&temp->day);
    printf(" month of birth: ");   scanf("%d",&temp->month);
    printf(" year of birth: ");    scanf("%d",&temp->year);
    printf("\n Score: ");          scanf("%f",&temp->score);
    temp->next=NULL;
    if(pos==0)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        for(i=0,ptr=head;i<pos-1;i++)
        {
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("\n Position not found:[Handle with care] \n");
                return;
            }
        }
        temp->next =ptr->next ;
        ptr->next=temp;
    }
}
