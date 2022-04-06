#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "register.h"

pNode createList()
{
    pNode Head = (pNode)malloc(sizeof(LNode));
    Head->next=NULL;
    FILE *fp = fopen("user.txt","r");


    pNode c = Head;
    while(1)
    {
        pNode temp = (pNode)malloc(sizeof(LNode));
        if(!temp)
            exit(-1);


        if(2!=fscanf(fp,"%s%s",temp->name,temp->pass))
        {
            free(temp);
            break;
        }
        c->next=temp;
        c = temp;
        c->next = NULL;
    }
    fclose(fp);
    return Head;
}

int login(pNode head,char *uu)
{
    if(NULL==head->next)
    {
        printf("user list empty,please register first\n");
        getchar();
        return 3;
    }
    char name[100];
    char pass[100];
    printf("enter your name:");
    scanf("%s",name);
    printf("enter your password:");
    scanf("%s",pass);
    pNode temp = head->next;
    while(temp)
    {
        if(0==strcmp(temp->name,name) && 0==strcmp(temp->pass,pass))
        {

            if(0==strcmp("librarian",name)){

                return 2;
            }
            printf("(Login in as %s)",name);
            strcat(name,"1.txt");
            strcpy(uu,name);

            return 1;
        }
        if(0==strcmp(temp->name,name) && 0!=strcmp(temp->pass,pass))
        {
            printf("Password is wrong! Please re-enter!\n");
            getchar();
            return 0;
        }
        temp = temp->next;
    }
    printf("User not found,please re-enter!\n");
    return 0;
}


void registerUser(pNode head)
{
    char name[100];
    pNode temp;
    temp=(pNode)malloc(sizeof(LNode));
    printf("enter your name:");
    scanf("%s",name);
    pNode abc = head->next;
    while(abc)
    {
        if(0==strcmp(abc->name,name))
        {
            printf("This username has already been registered.");
            getchar();
            return;

        }
        abc = abc->next;
    }
    strcpy(temp->name,name);
    printf("enter your password:");
    scanf("%s",temp->pass);
    temp->next=NULL;
    FILE *fw = fopen("user.txt","a");
    fprintf(fw,"%s",temp->name);
    fprintf(fw,"\t");
    fprintf(fw,"%s",temp->pass);
    fprintf(fw,"\n");
    fclose(fw);
    printf("Registered successfully\n");
}






