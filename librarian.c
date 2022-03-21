#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "librarian.h"
#include "book_mangement.h"
int Lib(){
    char a[10];
    int b;
    printf("\n");
    printf("Enter your choice:\n");
    printf("1.Add a book\n");
    printf("2.Remove a book\n");
    printf("3.Search for books\n");
    printf("4.Display all books\n");
    printf("5.Quit\n");
    printf("option:");
    scanf("%s",&a);
    b=strlen(a);

    while(b>=2||(a[0]!='1'&&a[0]!='2'&&a[0]!='3'&&a[0]!='4'&&a[0]!='5')){
        printf("\n");
        printf("Sorry the option is invalid,please try again.");
        printf("Enter your choice:\n");
        printf("1.Add a book\n");
        printf("2.Remove a book\n");
        printf("3.Search for books\n");
        printf("4.Display all books\n");
        printf("5.Quit\n");
        printf("option:");
        scanf("%s",&a);
        b=strlen(a);}
    if(a[0]=='1'){
        return 1;
    }
    else if(a[0]=='2'){
        return 2;

    }
    else if(a[0]=='3'){
        return 3;

    }
    else if(a[0]=='4'){
        return 4;

    }
    else if(a[0]=='5'){
        return 5;

    }

};
Book *create(){
    Book *head = (Book*)malloc(sizeof(Book));
    head->next=NULL;
    FILE *fp = fopen("booklist.txt","r+");
    if(NULL == fp)
    {
        printf("FILE NOT FOUND");
        exit(-1);
    }

    struct _Book* c = head;
    while(1)
    {
        Book* temp = (Book*)malloc(sizeof(Book));
        if(!temp)
            exit(-1);


        if(5!=fscanf(fp,"%i%s%s%i%i",temp->id,temp->title,temp->authors,temp->year,temp->copies))
        {
            free(temp);
            break;
        }
        c->next=temp;
        c = temp;
        c->next = NULL;
    }
    return head;

}

int add_book(FILE *file,Book *head){
    Book* temp = head->next;
    char *booktitle,*bookauthor;
    int year,copies;
    printf("Enter the title:");

}



