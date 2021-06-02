#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h>

char* searchrecord(char*,int);

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

char* login()
{
    int count;
    char *emailid,*password,*tempemailid,*temppassword,*number;

    emailid=(char*)malloc(sizeof(char)*40);
    password=(char*)malloc(sizeof(char)*40);
    tempemailid=(char*)malloc(sizeof(char)*40);
    temppassword=(char*)malloc(sizeof(char)*40);
    number=(char*)malloc(sizeof(char)*11);

    x:
    count=0;
    printf(" Enter Email id \n");
    scanf("%s",emailid);
    printf(" Enter Password");
    scanf("%s",password);
    FILE *ptr=fopen("all_users_id_and_password.txt","r");
    while(!feof(ptr))
    {
        fscanf(ptr,"%s ",tempemailid);
        if(!strcmp(emailid,tempemailid))
        {
            count=1;
            fscanf(ptr,"%s ",temppassword);
            if(!strcmp(password,temppassword))
            {
                fscanf(ptr,"%s ",number);
                break;
            }
            else
            {
                printf(" Incorrect Password");
                goto x;
            }
        }
    }
        if(count==0)
        {
            printf("Email id not found");
            fclose(ptr);
            goto x;
        }
        fclose(ptr);
        ptr=NULL;

        free(emailid);
        free(password);
        free(tempemailid);
        free(temppassword);
        return number;

}
char* userdetails()
{
    int i;
    char *firstname,*middlename,*lastname,*dob,*emailid,*password,*number,filename[26];
    char temp[]="userdetails.txt";

    firstname=(char*)malloc(sizeof(char)*30);
    lastname=(char*)malloc(sizeof(char)*30);
    middlename=(char*)malloc(sizeof(char)*30);
    dob=(char*)malloc(sizeof(char)*30);
    emailid=(char*)malloc(sizeof(char)*40);
    password=(char*)malloc(sizeof(char)*40);
    number=(char*)malloc(sizeof(char)*11);

    printf(" Enter your First Name");
    scanf("%s",firstname);

    system("cls");

    printf("  Enter your Middle Name\n");
    printf(" (if no middle name press '!')\n");
    scanf("%s",middlename);


    system("cls");

    printf(" Enter your Last Name");
    scanf("%s",lastname);

    system("cls");

    printf(" Enter your Mobile Number");
    scanf("%s",number);

    system("cls");

    printf(" Enter your Date of Birth");
    scanf("%s",dob);

    strcpy(filename,number);

    for(i=0;i<strlen(temp);i++)
    {
        filename[i+10]=temp[i];
    }
    filename[25]='\0';

    FILE *ptr1=fopen(filename,"w");
    fprintf(ptr1,"%s ",firstname);
    fprintf(ptr1,"%s ",middlename);
    fprintf(ptr1,"%s ",lastname);
    fprintf(ptr1,"%s ",number);
    fprintf(ptr1,"%s ",dob);

    fclose(ptr1);
    ptr1=NULL;

    printf(" Enter your email id\n");
    scanf("%s",emailid);

    printf(" create password\n");
    scanf("%s",password);

    FILE *ptr2=fopen("all_users_id_and_password.txt","a");

    fprintf(ptr2,"%s ",emailid);
    fprintf(ptr2,"%s ",password);
    fprintf(ptr2,"%s ",number);

    fclose(ptr2);
    ptr2=NULL;

    free(firstname);
    free(middlename);
    free(lastname);
    free(dob);
    free(emailid);
    free(password);

    return number;

}
void addcontact(char *number)
{
    system("cls");
    int i;
    char *firstname,*middlename,*lastname,contactnumber[11],filename[23],c;
    char temp[]="contacts.txt";

    firstname=(char*)malloc(sizeof(char)*30);
    middlename=(char*)malloc(sizeof(char)*30);
    lastname=(char*)malloc(sizeof(char)*30);

    printf("Enter First Name");
    scanf("%s",firstname);

    printf("enter Middle Name\nenter '!' if no middle name");
    scanf("%s",middlename);

    printf("enter Last Name");
    scanf("%s",lastname);

    printf("Enter Contact Number");
    scanf("%s",contactnumber);

    strcpy(filename,number);

    for(i=0;i<strlen(temp);i++)
    {
        filename[i+10]=temp[i];
    }
    filename[22]='\0';

    FILE *ptr=fopen(filename,"a");

    fprintf(ptr,"%s ",firstname);
    fprintf(ptr,"%s ",middlename);
    fprintf(ptr,"%s ",lastname);
    fprintf(ptr,"%s ",contactnumber);

    fclose(ptr);
    ptr=NULL;

    free(firstname);
    free(middlename);
    free(lastname);
    while(1)
        {
            printf("\n Press 1 to add another contact\n\n Press 2 to return to menu\n");
            fflush(stdin);
            scanf("%c",&c);
            if(c=='1')
            {
                addcontact(number);
                break;
            }
            else if(c=='2')
            {
                break;
            }
            else
            {
                printf("    INVALID INPUT!!!\n Please Enter a Valid choice\n\n\n");
            }

        }


}
void showcontacts(char *number)
{
    typedef struct NODE
    {
        char *firstname;
        char *middlename;
        char *lastname;
        char contactnumber[11];
        struct NODE *link;
    }node;
    system("cls");

    char filename[23];
    char temparray[]="contacts.txt";

    node *start=NULL;
    node *temp=NULL;
    node *t=NULL;

    int i,j=1;

    strcpy(filename,number);

    for(i=0;i<strlen(temparray);i++)
    {
        filename[i+10]=temparray[i];
    }
    filename[22]='\0';

    system("cls");

    FILE *ptr=fopen(filename,"r");

    if(ptr==NULL)
        printf("No contacts to show\n Press enter to return to menu");
    else
    {

        while(1)
        {
            if(feof(ptr))
                break;
            else
            {
                temp=(node*)malloc(sizeof(node));
                temp->firstname=(char*)malloc(sizeof(char)*30);
                temp->middlename=(char*)malloc(sizeof(char)*30);
                temp->lastname=(char*)malloc(sizeof(char)*30);
                fscanf(ptr,"%s ",temp->firstname);
                fscanf(ptr,"%s ",temp->middlename);
                fscanf(ptr,"%s ",temp->lastname);
                fscanf(ptr,"%s ",temp->contactnumber);
                temp->link=NULL;

                if(start==NULL)
                    start=temp;
                else
                {
                    t=start;
                    while(t->link!=NULL)
                    {
                        t=t->link;
                    }
                    t->link=temp;
                    t=NULL;
                    temp=NULL;
                }
            }

        }
        fclose(ptr);
        ptr=NULL;

        {
            t=start;
            while(t!=NULL)
            {
                printf("%d. Name :   %s ",j,t->firstname);
                if(strcmp("!",t->middlename))
                {
                    printf("%s ",t->middlename);
                }
                printf("%s\n",t->lastname);
                printf("   Number : %s\n",t->contactnumber);
                j++;
                t=t->link;

            }
        }

        t=start;
        temp=start;

        while(temp!=NULL)
        {
            temp=t->link;
            free(t->firstname);
            free(t->middlename);
            free(t->lastname);
            free(t);
            t=temp;
        }
    }

        getch();

}

void editcontact(char *number)
{
    typedef struct NODE
    {
        char *firstname;
        char *middlename;
        char *lastname;
        char contactnumber[11];
        struct NODE *link;
    }node;
    system("cls");

    char filename[23];
    char temparray[]="contacts.txt";
    char c1,c2;

    node *start=NULL;
    node *temp=NULL;
    node *t=NULL;

    char *search1,*search2,*search3,c,searchnumber[11];

    search1=(char*)malloc(sizeof(char)*30);
    search2=(char*)malloc(sizeof(char)*30);
    search3=(char*)malloc(sizeof(char)*30);

    int i;

    strcpy(filename,number);

    for(i=0;i<strlen(temparray);i++)
    {
        filename[i+10]=temparray[i];
    }
    filename[22]='\0';

    system("cls");

    FILE *ptr=fopen(filename,"r");

    if(ptr==NULL)
    {
        printf("No contacts to edit");
        getch();
    }
    else
    {

    while(1)
    {
        if(feof(ptr))
            break;
        else
        {
            temp=(node*)malloc(sizeof(node));
            temp->firstname=(char*)malloc(sizeof(char)*30);
            temp->middlename=(char*)malloc(sizeof(char)*30);
            temp->lastname=(char*)malloc(sizeof(char)*30);
            fscanf(ptr,"%s ",temp->firstname);
            fscanf(ptr,"%s ",temp->middlename);
            fscanf(ptr,"%s ",temp->lastname);
            fscanf(ptr,"%s ",temp->contactnumber);
            temp->link=NULL;

            if(start==NULL)
            {
                start=temp;
                temp=NULL;
            }
            else
            {
                t=start;
                while(t->link!=NULL)
                {
                    t=t->link;
                }
                t->link=temp;
                t=NULL;
                temp=NULL;
            }
        }

    }
    fclose(ptr);
    ptr=NULL;
    {
        x:
        while(1)
        {
            printf("1.Enter the Name of the contact you want to edit \n2.Enter the number of the contact you want to edit");
            fflush(stdin);
            scanf("%c",&c);
            if(c=='1')
            {
                printf("enter first name");
                scanf("%s",search1);
                printf("enter middle name \n (If no middle name press '!')");
                scanf("%s",search2);
                printf("enter last name\n");
                scanf("%s",search3);
                temp=start;
                while(temp!=NULL)
                {
                    if(!strcmp(search1,temp->firstname))
                    {
                        if(!strcmp(search2,temp->middlename))
                        {
                            if(!strcmp(search3,temp->lastname))
                            {
                                break;
                            }
                        }
                    }
                    temp=temp->link;
                }
                if(temp==NULL)
                {
                    printf("NO contact with name %s ",search1);
                    if(strcmp("!",search2))
                    printf("%s ",search2);
                    printf("%s \n please enter correct details\n",search3);
                    goto x;
                }
                else
                {
                    printf("Contact found\n");
                    printf("Name :   %s ",temp->firstname);
                    if(strcmp("!",temp->middlename))
                    printf("%s ",temp->middlename);
                    printf("%s \n",temp->lastname);
                    printf("Number : %s",temp->contactnumber);

                    y:

                    printf("1. Edit name\t2.Edit number");
                    fflush(stdin);
                    scanf("%c",&c1);

                    if(c1=='1')
                    {
                        system("cls");
                        printf("Enter First Name");
                        scanf("%s",temp->firstname);
                        printf("enter Middle Name\nenter '!' if no middle name");
                        scanf("%s",temp->middlename);
                        printf("enter Last Name");
                        scanf("%s",temp->lastname);

                    }
                    else if(c1=='2')
                    {
                        system("cls");

                        printf("enter number");
                        scanf("%s",temp->contactnumber);
                    }
                    else
                    {
                        system("cls");

                        printf("Invalid Input!!!\n\n Please enter a valid choice");
                        goto y;
                    }
                    system("cls");
                    printf("  Updated contact :\n\n");
                    printf("Name :   %s ",temp->firstname);
                    if(strcmp("!",temp->middlename))
                    printf("%s ",temp->middlename);
                    printf("%s \n",temp->lastname);
                    printf("Number : %s",temp->contactnumber);

                    temp=start;

                    ptr=fopen(filename,"w");

                    while(temp!=NULL)
                    {
                        fprintf(ptr,"%s ",temp->firstname);
                        fprintf(ptr,"%s ",temp->middlename);
                        fprintf(ptr,"%s ",temp->lastname);
                        fprintf(ptr,"%s ",temp->contactnumber);
                        temp=temp->link;
                    }
                    temp=NULL;
                    fclose(ptr);
                    ptr=NULL;

                    t=start;
                    temp=start;

                    while(temp!=NULL)
                    {
                        temp=t->link;
                        free(t->firstname);
                        free(t->middlename);
                        free(t->lastname);
                        free(t);
                        t=temp;
                    }
                    printf("\n\nPress enter to return to menu");
                    getch();
                }
                break;
            }
            else if(c=='2')
            {
                printf("Enter Number");
                scanf("%s",&searchnumber);

                temp=start;
                while(temp!=NULL)
                {
                    if(!strcmp(searchnumber,temp->contactnumber))
                    {
                        break;
                    }
                    temp=temp->link;
                }
                if(temp==NULL)
                {
                    printf("  No contact with number %s \n\n Please enter correct details\n",searchnumber);
                    goto x;
                }
                else
                {
                    printf("Contact found\n");
                    printf("Name :   %s ",temp->firstname);
                    if(strcmp("!",temp->middlename))
                    printf("%s ",temp->middlename);
                    printf("%s \n",temp->lastname);
                    printf("Number : %s",temp->contactnumber);

                    z:

                    printf("1. Edit name\t2.Edit number");
                    fflush(stdin);
                    scanf("%c",&c2);

                    if(c2=='1')
                    {
                        system("cls");

                        printf("Enter First Name");
                        scanf("%s",temp->firstname);

                        printf("enter Middle Name\nenter '!' if no middle name");
                        scanf("%s",temp->middlename);

                        printf("enter Last Name");
                        scanf("%s",temp->lastname);

                    }
                    else if(c2=='2')
                    {
                        system("cls");

                        printf("enter number");
                        scanf("%s",temp->contactnumber);
                    }
                    else
                    {
                        system("cls");

                        printf("Invalid Input!!!\n\n Please enter a valid choice");
                        goto z;
                    }
                    system("cls");
                    printf("  Updated contact :\n\n");
                    printf("Name :   %s ",temp->firstname);
                    if(strcmp("!",temp->middlename))
                    printf("%s ",temp->middlename);
                    printf("%s \n",temp->lastname);
                    printf("Number : %s",temp->contactnumber);

                    temp=start;

                    ptr=fopen(filename,"w");

                    while(temp!=NULL)
                    {
                        fprintf(ptr,"%s ",temp->firstname);
                        fprintf(ptr,"%s ",temp->middlename);
                        fprintf(ptr,"%s ",temp->lastname);
                        fprintf(ptr,"%s ",temp->contactnumber);
                        temp=temp->link;
                    }
                    temp=NULL;
                    fclose(ptr);
                    ptr=NULL;

                    t=start;
                    temp=start;

                    while(temp!=NULL)
                    {
                        temp=t->link;
                        free(t->firstname);
                        free(t->middlename);
                        free(t->lastname);
                        free(t);
                        t=temp;
                    }
                    printf("\n\nPress enter to return to menu");
                    getch();

                }
                break;

            }
            else
            {
                system("cls");
                printf("Invalid Input!!!\n\n Please enter a valid choice\n\n");
                goto x;
            }
        }
    }
    }
    free(search1);
    free(search2);
    free(search3);
}
void paytocontact(char *number)
{
    int i,amount1,walletbalance1;
    char filename1[21],*filename2,walletbalance[10],*contactnumber1,*contactnumber2,c1,c2,c3,c4,amount2[10];
    char temparray1[]="wallet.txt";

    contactnumber1=(char*)malloc(sizeof(char)*11);
    filename2=(char*)malloc(sizeof(char)*40);

    strcpy(filename1,number);

    for(i=0;i<strlen(temparray1);i++)
    {
        filename1[i+10]=temparray1[i];
    }
    filename1[20]='\0';

    FILE *ptr1=fopen(filename1,"r");

    if(ptr1==NULL)
    {
        while(1)
        {
            printf("Your Wallet is not activated \n\npress 1 to activate wallet\n\npress 2 to go back to main menu");
            fflush(stdin);
            scanf("%c",&c1);
            if(c1=='1')
            {
                ptr1=fopen(filename1,"w");
                fprintf(ptr1,"0 ");
                printf(" \n\nWallet Activated....press enter to continue");
                getch();
                break;
            }
            else if(c1=='2')
            {
                break;
            }
            else
            {
                system("cls");
                printf("\nInvalid Input!!!\n Please enter a valid choice\n\n");
            }
        }
    }
    if(ptr1!=NULL)
    {
        fclose(ptr1);
        ptr1=fopen(filename1,"r");

        fscanf(ptr1,"%s ",walletbalance);

        system("cls");
        printf("\n\n\t\t\tYour Wallet Balance is Rs %s\n\n",walletbalance);
        fclose(ptr1);

        while(1)
        {
            l:
            printf("1.Add money to Wallet\n\n2.Do Payment\n");
            fflush(stdin);
            scanf("%c",&c2);
            if(c2=='1')
            {
                system("cls");
                //addmoney();
                system("cls");
                m:
                printf("\n\n1.Do Payment\n\n2.Return to menu");
                fflush(stdin);
                scanf("%c",&c3);
                if(c3=='1')
                    goto l;
                else if(c3=='2')
                    break;
                else
                {
                    system("cls");
                    printf("Invalid Input!!!.......Please enter a valid input\n\n");
                    goto m;

                }
            }
            else if(c2=='2')
            {
                system("cls");
                while(1)
                {
                    printf(" 1.Enter number \n\n 2.Search contact\n\n");
                    fflush(stdin);
                    scanf("%c",&c4);
                    if(c4=='1')
                    {
                        system("cls");
                        printf("Enter number");
                        scanf("%s ",contactnumber1);
                        break;
                    }
                    else if(c4=='2')
                    {
                        system("cls");
                        contactnumber2=searchrecord(number,1);
                        strcpy(contactnumber1,contactnumber2);
                        free(contactnumber2);
                        break;
                    }
                    else
                    {
                        system("cls");
                        printf("\t\tInvalid Input......Please enter a valid choice\n\n");
                    }
                }
                n:
                printf("Enter the amount you want to pay to %s and press enter",contactnumber1);
                scanf("%d",&amount1);
                ptr1=fopen(filename1,"r");
                fscanf(ptr1,"%s ",walletbalance);
                fclose(ptr1);
                walletbalance1=atoi(walletbalance);
                if(amount1>10000)
                {
                    system("cls");
                    printf("Amount must be less than 100000\n\n");
                    goto n;
                }
                else if(amount1>walletbalance1)
                {
                    system("cls");
                    printf("Amount exceeds your wallet balance!!!\n\n");
                    goto n;
                }
                else
                {
                     printf("\n\nYou have successfully paid Rs%d to %s \n\n\t\tPress any key to return to menu",amount1,contactnumber1);
                     getch();
                     walletbalance1=walletbalance1-amount1;
                     itoa(amount1,amount2,10);
                     itoa(walletbalance1,walletbalance,10);

                     ptr1=fopen(filename1,"w");
                     fprintf(ptr1,"%s ",walletbalance);
                     fclose(ptr1);
                     ptr1=NULL;

                     strcpy(filename2,number);
                     strcpy(filename2+10,contactnumber1);
                     strcpy(filename2+20,".txt");

                     ptr1=fopen(filename2,"a");
                     fprintf(ptr1,"-%s ",amount2);
                     fclose(ptr1);
                     ptr1=NULL;

                     strcpy(filename2,contactnumber1);
                     strcpy(filename2+10,number);
                     strcpy(filename2+20,".txt");

                     ptr1=fopen(filename2,"a");
                     fprintf(ptr1,"+%s ",amount2);
                     fclose(ptr1);
                     ptr1=NULL;

                     strcpy(filename2,contactnumber1);
                     strcpy(filename2+10,"wallet.txt");

                     ptr1=fopen(filename2,"r");
                     if(ptr1==NULL)
                     {
                         ptr1=fopen(filename2,"w");
                         fprintf(ptr1,"%s",amount2);
                         fclose(ptr1);
                     }
                     else
                     {
                         ptr1=fopen(filename2,"r");
                         fscanf(ptr1,"%s",walletbalance);
                         fclose(ptr1);
                         ptr1=NULL;

                         walletbalance1=atoi(walletbalance);
                         walletbalance1=walletbalance1+amount1;
                         itoa(walletbalance1,walletbalance,10);

                         ptr1=fopen(filename2,"w");
                         fprintf(ptr1,"%s",walletbalance);
                         fclose(ptr1);
                         ptr1=NULL;
                     }
                     strcpy(filename2,number);
                     strcpy(filename2+10,"transaction.txt");

                     ptr1=fopen(filename2,"a");
                     fprintf(ptr1,"-%s ",amount2);
                     fclose(ptr1);
                     ptr1=NULL;

                     strcpy(filename2,contactnumber1);
                     strcpy(filename2+10,"transaction.txt");

                     ptr1=fopen(filename2,"a");
                     fprintf(ptr1,"+%s ",amount2);
                     fclose(ptr1);
                     ptr1=NULL;


                }
                break;
            }
            else
            {
                system("cls");
                printf("Invalid Input!!!.......Please enter a valid choice\n\n");
            }

        }
    }
}
char* searchrecord(char* number,int count)
{
    typedef struct NODE
    {
        char *firstname;
        char *middlename;
        char *lastname;
        char contactnumber[11];
        struct NODE *link;
    }node;

    typedef struct STACK
    {
        int top;
        int capacity;
        int *array;
    }stack;

    system("cls");

    int i,transaction,returned;
    char filename1[23],filename2[21],*filepointer;
    char temparray[]="contacts.txt";
    char c,c1,c2,x1,x2;

    node *start=NULL;
    node *temp=NULL;
    node *t=NULL;

    char *search1,*search2,*search3,searchnumber[11],transac[10],*returning;

    search1=(char*)malloc(sizeof(char)*30);
    search2=(char*)malloc(sizeof(char)*30);
    search3=(char*)malloc(sizeof(char)*30);
    returning=(char*)malloc(sizeof(char)*11);

    strcpy(filename1,number);

    for(i=0;i<strlen(temparray);i++)
    {
        filename1[i+10]=temparray[i];
    }
    filename1[22]='\0';

    FILE *ptr=fopen(filename1,"r");

    if(ptr==NULL)
    {
        printf("No contacts to search\n\n Press any key to return to menu");
        free(search1);
        free(search2);
        free(search3);
        getch();
        return returning;
    }
    else
    {

        while(1)
        {
            if(feof(ptr))
                break;
            else
            {
                temp=(node*)malloc(sizeof(node));
                temp->firstname=(char*)malloc(sizeof(char)*30);
                temp->middlename=(char*)malloc(sizeof(char)*30);
                temp->lastname=(char*)malloc(sizeof(char)*30);
                fscanf(ptr,"%s ",temp->firstname);
                fscanf(ptr,"%s ",temp->middlename);
                fscanf(ptr,"%s ",temp->lastname);
                fscanf(ptr,"%s ",temp->contactnumber);
                temp->link=NULL;

                if(start==NULL)
                {
                    start=temp;
                    temp=NULL;
                }
                else
                {
                    t=start;
                    while(t->link!=NULL)
                    {
                        t=t->link;
                    }
                    t->link=temp;
                    t=NULL;
                    temp=NULL;
                }
            }

        }
        fclose(ptr);
        ptr=NULL;
        x:
        while(1)
        {
            printf("1.Enter the Name of the contact you want to search \n\n2.Enter the number of the contact you want to search");
            fflush(stdin);
            scanf("%c",&c);
            if(c=='1')
            {
                printf("enter first name");
                scanf("%s",search1);
                printf("enter middle name \n (If no middle name press '!')");
                scanf("%s",search2);
                printf("enter last name\n");
                scanf("%s",search3);
                temp=start;
                while(temp!=NULL)
                {
                    if(!strcmp(search1,temp->firstname))
                    {
                        if(!strcmp(search2,temp->middlename))
                        {
                            if(!strcmp(search3,temp->lastname))
                            {
                            break;
                            }
                        }
                    }
                    temp=temp->link;
                }
                if(temp==NULL)
                {
                    printf("NO contact with name %s ",search1);
                    if(strcmp("!",search2))
                    printf("%s ",search2);
                    printf("%s \n please enter correct details\n",search3);
                    goto x;
                }
                else
                {
                    printf("Contact found\n");
                    printf("Name :   %s ",temp->firstname);
                    if(strcmp("!",temp->middlename))
                    printf("%s ",temp->middlename);
                    printf("%s \n",temp->lastname);
                    printf("Number : %s\n\n",temp->contactnumber);
                    strcpy(returning,temp->contactnumber);
                }
                while(1)
                {
                    l:
                    if(count==0)
                    {
                        fflush(stdin);
                        printf("\n\nPress 1 to view Transaction History with %s ",temp->firstname);
                        if(strcmp("!",temp->middlename))
                        printf("%s ",temp->middlename);
                        printf("%s \n\nPress 2 to go back to main menu",temp->lastname);
                        scanf("%c",&x1);
                        if(x1=='1')
                        {
                            filepointer=filename2;
                            strcpy(filepointer,number);
                            filepointer=filepointer+10;
                            strcpy(filepointer,temp->contactnumber);
                            strcpy(filepointer+10,".txt");

                            FILE *ptr1=fopen(filename2,"r");
                            if(ptr1==NULL)
                            {
                                printf("No transactions yet with %s ",temp->firstname);
                                if(strcmp("!",temp->middlename))
                                printf("%s ",temp->middlename);
                                printf("%s \n\n",temp->lastname);
                                printf("Press any key to go back to menu");
                                getch();
                            }
                            else
                            {
                                stack *t=(stack*)malloc(sizeof(stack));
                                t->top=0;
                                t->capacity=1;
                                t->array=(int*)malloc(sizeof(int)*t->capacity);
                                fscanf(ptr1,"%s ",transac);
                                transaction=atoi(transac);
                                t->array[0]=transaction;
                                for(i=1;!feof(ptr1);i++)
                                {
                                    t->top=t->top+1;
                                    t->capacity=t->capacity+1;
                                    t->array=(int*)realloc(t->array,sizeof(int)*t->capacity);
                                    fscanf(ptr1,"%s ",transac);
                                    transaction=atoi(transac);
                                    t->array[t->top]=transaction;
                                }
                                fclose(ptr1);
                                ptr1=NULL;
                                while(t->top!=-1)
                                {
                                    system("cls");
                                    printf("\t\tTransaction history with %s ",temp->firstname);
                                    if(strcmp("!",temp->middlename))
                                    printf("%s ",temp->middlename);
                                    printf("%s \t (%s)",temp->lastname,temp->contactnumber);

                                    if(t->array[t->top]>0)
                                    {
                                        printf("Received Rs%d \n\n",t->array[t->top]);
                                    }
                                    else
                                    {
                                        printf("Paid Rs%d \n\n",t->array[t->top]);
                                    }
                                    t->top=t->top-1;
                                }
                                printf("Press any key to go back to menu");
                                getch();
                                free(t->array);
                                free(t);
                            }
                            break;
                        }
                        else if(x1=='2')
                        {
                            break;
                        }
                        else
                        {
                            printf("Invalid input!!!.......Please enter a valid choice\n\n");
                            goto l;
                        }
                    }
                    else
                        break;
                }
                temp=NULL;
                break;
            }
            else if(c=='2')
            {
                printf("Enter Number");
                scanf("%s",&searchnumber);
                temp=start;
                while(temp!=NULL)
                {
                    if(!strcmp(searchnumber,temp->contactnumber))
                    {
                        break;
                    }
                    temp=temp->link;
                }
                if(temp==NULL)
                {
                    printf("  No contact with number %s \n\n Please enter correct details\n",searchnumber);
                    goto x;
                }
                else
                {
                    printf("Contact found\n");
                    printf("Name :   %s ",temp->firstname);
                    if(strcmp("!",temp->middlename))
                    printf("%s ",temp->middlename);
                    printf("%s \n",temp->lastname);
                    printf("Number : %s",temp->contactnumber);
                    strcpy(returning,temp->contactnumber);

                }
                while(1)
                {
                    m:
                    if(count==0)
                    {
                        fflush(stdin);
                        printf("\n\nPress 1 to view Transaction History with %s ",temp->firstname);
                        if(strcmp("!",temp->middlename))
                        printf("%s ",temp->middlename);
                        printf("%s \n\nPress 2 to go back to main menu",temp->lastname);
                        scanf("%c",&x2);
                        if(x2=='1')
                        {
                            filepointer=filename2;
                            strcpy(filepointer,number);
                            filepointer=filepointer+10;
                            strcpy(filepointer,temp->contactnumber);
                            strcpy(filepointer+10,".txt");

                            FILE *ptr1=fopen(filename2,"r");
                            if(ptr1==NULL)
                            {
                                printf("No transactions yet with %s ",temp->firstname);
                                if(strcmp("!",temp->middlename))
                                printf("%s ",temp->middlename);
                                printf("%s \n\n",temp->lastname);
                                printf("Press any key to go back to menu");
                                getch();
                            }
                            else
                            {
                                stack *t=(stack*)malloc(sizeof(stack));
                                t->top=0;
                                t->capacity=1;
                                t->array=(int*)malloc(sizeof(int)*t->capacity);
                                fscanf(ptr1,"%s ",transac);
                                transaction=atoi(transac);
                                t->array[0]=transaction;
                                for(i=1;!feof(ptr1);i++)
                                {
                                    t->top=t->top+1;
                                    t->capacity=t->capacity+1;
                                    t->array=(int*)realloc(t->array,sizeof(int)*t->capacity);
                                    fscanf(ptr1,"%s ",transac);
                                    transaction=atoi(transac);
                                    t->array[t->top]=transaction;
                                }
                                fclose(ptr1);
                                ptr1=NULL;
                                while(t->top!=-1)
                                {
                                    system("cls");
                                    printf("\t\tTransaction history with %s ",temp->firstname);
                                    if(strcmp("!",temp->middlename))
                                    printf("%s ",temp->middlename);
                                    printf("%s \t (%s)",temp->lastname,temp->contactnumber);
                                    if(t->array[t->top]>0)
                                    {
                                        printf("\n\tReceived Rs%d \n\n",t->array[t->top]);
                                    }
                                    else
                                    {
                                        printf("\n\tPaid Rs%d \n\n",t->array[t->top]);
                                    }
                                    t->top=t->top-1;
                                }
                                printf("Press any key to go back to menu");
                                getch();
                                free(t->array);
                                free(t);
                            }
                            break;
                        }
                        else if(x2=='2')
                        {
                            break;
                        }
                        else
                        {
                            printf("Invalid input!!!.......Please enter a valit choice\n\n");
                            goto m;
                        }
                    }
                    else
                        break;
                }
                temp=NULL;
                break;
            }
            else
            {
                system("cls");
                printf("\n Invalid input.........Please enter a valid choice\n\n");
                goto x;
            }
        }
        t=start;
        temp=start;

        while(temp!=NULL)
        {
            temp=t->link;
            free(t->firstname);
            free(t->middlename);
            free(t->lastname);
            free(t);
            t=temp;
        }
    }
    free(search1);
    free(search2);
    free(search3);
    return returning;
}

int main()
{
    char a,*number,*contactnumber;
    gotoxy(43,14);
    printf("   ***WELCOME TO PHONEBOOK***");
    gotoxy(44,28);
    printf("  Press any key to continue");
    getch();
    system("cls");
    o:
    while(1)
    {
        printf("\n Already a User?\n\n Press 1 to Log In\n\n\n\n New to Phonebook? \n\n Press 2 to Create a Account \n\n\n ");
        fflush(stdin);
        scanf("%c",&a);
        if(a=='1')
        {
            number=login();
            break;

        }
        else if(a=='2')
        {
            system("cls");
            number=userdetails();
            break;
        }
        else
        {
            system("cls");
            printf(" Invalid Choice\n");
            printf(" Please Enter a Valid Choice\n\n");
        }

    }
    system("cls");
    while(1)
    {

        int b;
        gotoxy(53,1);
        printf("PHONEBOOK\n\n\n");
        printf("1. Add Contacts to Phonebook\n2. Show Your Contacts\n3. Edit a Contact\n4. Search contact \n5. Make Payment to contact\n6. Delete a contact\n7. Wallet Balance and Transaction History\n8.Add money to Wallet\n9.Edit User Details\n 10.Log out\n11. Exit");
        printf("\n\n\t\tEnter Your Choice");
        fflush(stdin);
        scanf("%d",&b);
        switch (b)
        {
            case 1:
                addcontact(number);
                system("cls");
                break;
            case 2:
                showcontacts(number);
                system("cls");
                break;
            case 3:
                editcontact(number);
                system("cls");
                break;
            case 4:
                contactnumber=searchrecord(number,0);
                system("cls");
                break;
            case 5:
                paytocontact(number);
                system("cls");
                break;
            case 10:
                goto o;
            case 11:
                exit(0);
            default:
                system("cls");
                printf("Invalid Input!!!\n\tPlease Enter a Valid choice");
                break;
        }
    }
}
