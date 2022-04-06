#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "user.h"
#include "book_mangement.h"
int Userface(){
    char a[10];
    int b;
    printf("\n");
    printf("Enter your choice:\n");
    printf("1.Borrow the book\n");
    printf("2.Return the book\n");
    printf("3.Search for books\n");
    printf("4.Display all books\n");
    printf("5.Quit\n");
    printf("option:");
    scanf("%s",&a);
    b=strlen(a);
    while(b>=2||(a[0]!='1'&&a[0]!='2'&&a[0]!='3'&&a[0]!='4'&&a[0]!='5')){
        printf("\n");
        printf("Sorry the option is invalid,please try again.\n");
        printf("Enter your choice:\n");
        printf("1.Borrow the book\n");
        printf("2.Return the book\n");
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



}
int Borrowbook(Book *head,Book *borrow,char *username){


    FILE *fw= fopen(username,"a");
    if(head->next==NULL){
        printf("Sorry,there are no books in the library.");
        return 1;
    }
    display(head);
    char *i;
    int a,b;
    b=0;
    i=(char *)malloc(sizeof(char));
    printf("Please enter the ID of the book you want to borrow:");
    scanf("%s",i);
    if(check(i)==0){
        printf("Please enter a positive integer.");
        return 1;
    }
    a= atoi(i);
    Book *temp=head;
    Book *t=borrow;
    Book *abc = borrow->next;
    Book *no = head->next;
    while(no)
    {
        if(no->id==a&&no->now==0)
        {
            printf("Sorry.The number of books available for borrowing is 0.");
            return 1;

        }
        no = no->next;
    }
    while(abc)
    {
        if(abc->id==a)
        {
            printf("You have borrowed this book.");
            return 1;

        }
        abc = abc->next;
    }

    while (t->next!=NULL){
        t=t->next;
    }
    while(temp->next!=NULL){
        temp=temp->next;
        if (temp->id==a ){
            t->id=temp->id;
            t->year=temp->year;
            t->authors=temp->authors;
            t->title=temp->title;
            t->copies=temp->copies;
            t->now=temp->now;
            temp->now=temp->now-1;
            b=1;
            fprintf(fw,"%i",temp->id);
            fprintf(fw,";");
            fprintf(fw,"%s",temp->title);
            fprintf(fw,";");
            fprintf(fw,"%s",temp->authors);
            fprintf(fw,";");
            fprintf(fw,"%i",temp->year);
            fprintf(fw,"\n");
        }
        if(b==1){
            fclose(fw);
            break;
        }


    }
    if(b==0){
        printf("Invalid input, please enter a correct ID.");
        return 1;
    }
    return 0;

}
int displayborrowbook(Book *borrow){
    Book *temp=borrow;

    while (temp->next!=NULL){
        temp=temp->next;
        printf("ID:");
        printf("%i",temp->id);
        printf("\0");
        printf("Title:");
        printf("%s",temp->title);
        printf("\0");
        printf("Authors::");
        printf("%s",temp->authors);
        printf("\0");
        printf("Year:");
        printf("%i",temp->year);
        printf("\n");
    }

}
Book *borrow(char *username) {
    FILE *creat= fopen(username,"a");
    fclose(creat);

    Book *head = (Book *) malloc(sizeof(Book));
    head->next = NULL;
    FILE *fp = fopen(username, "r");
    Book *last = head;
    char line[300];
    while (fgets(line, 300, fp) != NULL) {
        Book *temp = (Book *) malloc(sizeof(Book));

        temp->id = atoi(strtok(line, ";"));
        temp->title = strddd(strtok(NULL, ";"));
        temp->title[strlen(temp->title)] = '\0';

        temp->authors = strddd(strtok(NULL, ";"));
        temp->authors[strlen(temp->authors)] = '\0';
        temp->year = atoi(strtok(NULL, "\n"));

        last->next = temp;
        last = temp;
        last->next = NULL;

    }
    fclose(fp);
    return head;
}
int returnbook(Book*head,Book*borrow,char *username){
    char *i;
    int a,b;
    b=0;
    if(borrow->next==NULL){
        printf("You hava not borrowed any books.");
        return 1;
    }
    i=(char *)malloc(sizeof(char));
    printf("Please enter the book ID to return the book:");
    scanf("%s",i);
    if(check(i)==0){
        printf("Please enter a positive integer.");
        return 1;
    }
    a= atoi(i);

    Book *x=head;
    Book *temp=borrow;
    while(x->next!=NULL){
        x=x->next;
        if(x->id==a){
            x->now=x->now+1;
            break;
        }
    }
    while (temp->next!=NULL){
        if (temp->next->id == a&&temp->next->next!=NULL){
            temp->next= temp->next->next;;
            b=1;
        }
        else if(temp->next->id == a&&temp->next->next==NULL){
            temp->next=NULL;
            b=1;
        }

        if(b==1){
            break;
        }
        temp=temp->next;

    }
    if(b==0){
        printf("Invalid input, please enter a correct ID");
        return 1;
    }
    Book *t=borrow;
    FILE *fg= fopen(username,"w");
    while (t->next!=NULL){
        t=t->next;
        fprintf(fg,"%i",t->id);
        fprintf(fg,";");
        fprintf(fg,"%s",t->title);
        fprintf(fg,";");
        fprintf(fg,"%s",t->authors);
        fprintf(fg,";");
        fprintf(fg,"%i",t->year);
        fprintf(fg,"\n");
    }
    fclose(fg);
    return 0;

}

