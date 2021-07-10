//Sec:3 BN:2 Name: عزالدين احمد عثمان
//Sec:3 BN:3 Name: علاء ربيع سالم
//Sec:3 BN:5 Name: علي ماهر عبدالسلام
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
void insert_array_begin(struct student* ptr1,int num_inserted1)
{
    if(num_inserted_arr==0)
    {
        goto insert;
        return;
    }
    else //there is elements at the beginning
    {
        for (ii=1; ii<=num_inserted1 ;ii++)
        {
            strncpy((ptr1+num_inserted1-(ii-1))->fname , (ptr1+(num_inserted1-ii))->fname , 20);
            strncpy((ptr1+num_inserted1-(ii-1))->lname , (ptr1+(num_inserted1-ii))->lname , 20);
            (ptr1+num_inserted1-(ii-1))->id    = (ptr1+(num_inserted1-ii))->id;      //5 inserted => ptr+5=ptr+4  and ptr+4=ptr+3....
            (ptr1+num_inserted1-(ii-1))->day   = (ptr1+(num_inserted1-ii))->day ;
            (ptr1+num_inserted1-(ii-1))->month = (ptr1+(num_inserted1-ii))->month;
            (ptr1+num_inserted1-(ii-1))->year  = (ptr1+(num_inserted1-ii))->year;
            (ptr1+num_inserted1-(ii-1))->score = (ptr1+(num_inserted1-ii))->score;
        }

    }

    insert:
    printf("\n Enter the data of student:\n");
    printf(" id: ");                 scanf("%d",&ptr1->id);
    printf("\n first name: ");       scanf("%s",ptr1->fname);
    printf("\n last name: ");        scanf("%s",ptr1->lname);
    printf("\n day of birth: ");     scanf("%d",&ptr1->day);
    printf("\n month of birth: ");   scanf("%d",&ptr1->month);
    printf("\n year of birth: ");    scanf("%d",&ptr1->year);
    printf("\n Score: ");            scanf("%f",&ptr1->score);
};
void insert_array_end(struct student *ptr, int num_inserted)
{

    if (num_inserted==0)
   {
        printf("\n Enter the data of student:\n");
        printf(" id: ");               scanf("%d",&ptr->id);
        printf("\n first name: ");     scanf("%s",ptr->fname);
        printf(" last name: ");        scanf("%s",ptr->lname);
        printf("\n day of birth: ");   scanf("%d",&ptr->day);
        printf(" month of birth: ");   scanf("%d",&ptr->month);
        printf(" year of birth: ");    scanf("%d",&ptr->year);
        printf("\n Score: ");          scanf("%f",&ptr->score);
   }
   else
   {
        printf("\n Enter the data of student:\n");
        printf(" id: ");               scanf("%d",&(ptr+(num_inserted))->id);
        printf("\n first name: ");     scanf("%s",(ptr+(num_inserted))->fname);
        printf(" last name: ");        scanf("%s",(ptr+(num_inserted))->lname);
        printf("\n day of birth: ");   scanf("%d",&(ptr+(num_inserted))->day);
        printf(" month of birth: ");   scanf("%d",&(ptr+(num_inserted))->month);
        printf(" year of birth: ");    scanf("%d",&(ptr+(num_inserted))->year);
        printf("\n Score: ");          scanf("%f",&(ptr+(num_inserted))->score);
    }

}
void insert_array_mid(struct student *ptr1, int num_inserted)
{
    if (num_inserted==0)
    {
        printf("\n Enter the data of student:\n");
        printf(" id: ");               scanf("%d",&ptr1->id);
        printf("\n first name: ");     scanf("%s",ptr1->fname);
        printf(" last name: ");        scanf("%s",ptr1->lname);
        printf("\n day of birth: ");   scanf("%d",&ptr1->day);
        printf(" month of birth: ");   scanf("%d",&ptr1->month);
        printf(" year of birth: ");    scanf("%d",&ptr1->year);
        printf("\n Score: ");          scanf("%f",&ptr1->score);

    }
    else if (num_inserted%2==0) //even
    {
        //n=n+1, n-1=n, .....
        for (ii=1; ii<=((num_inserted/2)+1) ;ii++)
        {
            strncpy((ptr1+num_inserted-(ii-1))->fname , (ptr1+(num_inserted-ii))->fname , 20);
            strncpy((ptr1+num_inserted-(ii-1))->lname , (ptr1+(num_inserted-ii))->lname , 20);
            (ptr1+num_inserted-ii+1)->id    = (ptr1+(num_inserted-ii))->id;      //4 inserted => ptr+4=ptr+3  and ptr+3=ptr+2....
            (ptr1+num_inserted-ii+1)->day   = (ptr1+(num_inserted-ii))->day ;
            (ptr1+num_inserted-ii+1)->month = (ptr1+(num_inserted-ii))->month;
            (ptr1+num_inserted-ii+1)->year  = (ptr1+(num_inserted-ii))->year;
            (ptr1+num_inserted-ii+1)->score  = (ptr1+(num_inserted-ii))->score;
        }

        num_inserted=(num_inserted/2);
        printf("\n Enter the data of student:\n");
        printf(" id: ");               scanf("%d",&(ptr1+(num_inserted))->id);
        printf("\n first name: ");     scanf("%s",(ptr1+(num_inserted))->fname);
        printf(" last name: ");        scanf("%s",(ptr1+(num_inserted))->lname);
        printf("\n day of birth: ");   scanf("%d",&(ptr1+(num_inserted))->day);
        printf(" month of birth: ");   scanf("%d",&(ptr1+(num_inserted))->month);
        printf(" year of birth: ");    scanf("%d",&(ptr1+(num_inserted))->year);
        printf("\n Score: ");          scanf("%f",&(ptr1+(num_inserted))->score);

    }

    else if (num_inserted%2 != 0) //odd
    {
        //n=n+1, n-1=n, .....
        for (ii=1; ii<=((num_inserted/2)+1) ;ii++)
        {
            strncpy((ptr1+num_inserted-(ii-1))->fname , (ptr1+(num_inserted-ii))->fname , 20);
            strncpy((ptr1+num_inserted-(ii-1))->lname , (ptr1+(num_inserted-ii))->lname , 20);
            (ptr1+num_inserted-ii+1)->id    = (ptr1+(num_inserted-ii))->id;      //4 inserted => ptr+4 "5"=ptr+3 "4"  and ptr+3 "4"=ptr+2 "3{last}"....
            (ptr1+num_inserted-ii+1)->day   = (ptr1+(num_inserted-ii))->day ;
            (ptr1+num_inserted-ii+1)->month = (ptr1+(num_inserted-ii))->month;
            (ptr1+num_inserted-ii+1)->year  = (ptr1+(num_inserted-ii))->year;
            (ptr1+num_inserted-ii+1)->score  = (ptr1+(num_inserted-ii))->score;
        }

        num_inserted=(num_inserted/2);
        printf("\n Enter the data of student:\n");
        printf(" id: ");               scanf("%d",&(ptr1+(num_inserted))->id);
        printf("\n first name: ");     scanf("%s",(ptr1+(num_inserted))->fname);
        printf(" last name: ");        scanf("%s",(ptr1+(num_inserted))->lname);
        printf("\n day of birth: ");   scanf("%d",&(ptr1+(num_inserted))->day);
        printf(" month of birth: ");   scanf("%d",&(ptr1+(num_inserted))->month);
        printf(" year of birth: ");    scanf("%d",&(ptr1+(num_inserted))->year);
        printf("\n Score: ");          scanf("%f",&(ptr1+(num_inserted))->score);

    }
}
void display_list()
{
    struct student *ptr;
    if(head==NULL)
    {
        printf("\n Linked List is empty\n");
        return;
    }
    else
    {
        ptr=head;
        printf("\nThe Linked List of student are:\n");
        printf("\n ");
        while(ptr!=NULL)
        {
            printf("%d\t",ptr->id);     printf("%s\t",ptr->fname);
            printf("%s\t",ptr->lname);  printf("%d/",ptr->day);
            printf("%d/",ptr->month);  printf("%d\t",ptr->year);
            printf("%f\t",ptr->score);  printf("\n ");
            ptr=ptr->next ;
        }
        printf("\nThe size of the List = %d Byte\n",N*sizeof(struct student));
    }
    return;

}
void display_array(struct student* ptr_display, int num_inserted_display)
{
    if(num_inserted_display == 0)
    {
        printf("\n Array list is empty\n");
        return;
    }
    else
    {
        printf("\nThe Array list of student are:\n");
        printf("\n ");
        ii=0;
        while(ii < num_inserted_display)
        {
            printf("%d\t",(ptr_display+ii)->id);     printf("%s\t",(ptr_display+ii)->fname);
            printf("%s\t",(ptr_display+ii)->lname);  printf("%d/",(ptr_display+ii)->day);
            printf("%d/",(ptr_display+ii)->month);  printf("%d\t",(ptr_display+ii)->year);
            printf("%f\t",(ptr_display+ii)->score);  printf("\n ");
            ii++;

        }
    }
    return;
}
