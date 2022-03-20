#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "register.h"


pNode createList()
{
    pNode Head = (pNode)malloc(sizeof(LNode));
    Head->next=NULL;
    FILE *fp = fopen("user.txt","r+");
    if(NULL == fp)
    {
        printf("FILE NOT FOUND");
        exit(-1);
    }

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
    return Head;
}

int login(pNode head)
{
    if(NULL==head->next)
    {
        printf("user list empty,please register first\n");
        getchar();
        return 0;
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
            printf("success");
            getchar();
            return 1;
        }
        if(0==strcmp(temp->name,name) && 0!=strcmp(temp->pass,pass))
        {
            printf("password is wrong!");
            getchar();
            return 0;
        }
        temp = temp->next;
    }
    printf("user not found");
    return 0;
}


void registerUser(pNode head)
{
    char name[100];
    pNode temp = head->next;
    if(!temp)
    {
        temp = (pNode)malloc(sizeof(LNode));
        head->next = temp;
    }
    else
    {
        while(temp->next)
        {
            temp = temp->next;
        }
        pNode last = (pNode)malloc(sizeof(LNode));
        temp->next = last;
        temp = last;
    }
    printf("enter your name:");
    scanf("%s",name);
    pNode abc = head->next;
    while(abc)
    {
        if(0==strcmp(abc->name,name))
        {
            printf("This username has already been registered.");
            return;

        }
        abc = abc->next;
    }
    strcpy(temp->name,name);
    printf("enter your password:");
    scanf("%s",temp->pass);
    temp->next=NULL;
    FILE *fw = fopen("user.txt","a");
    fprintf(fw,temp->name);
    fprintf(fw,"\t");
    fprintf(fw,temp->pass);
    fprintf(fw,"\n");
    temp  = temp->next;
    fclose(fw);
    printf("Registered successfully");
}






