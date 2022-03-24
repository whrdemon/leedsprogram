#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "librarian.h"
#include "book_mangement.h"
char *strddd(const char *s){
    size_t size = strlen(s) + 1;
    char *p = (char *)malloc(size*sizeof(char));
    if (p) {
        memcpy(p, s, size);
    }
    return p;}
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


int add_book(FILE *file,Book *head){
    Book *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    char booktitle[100],bookauthor[100];
    int year,copies;
    int id;
    if(head->next == NULL){
        id = 1;
    }
    else{
        Book *n = head;
        while(n->next != NULL){
            n = n->next;
        }
        id = n->id + 1;
    }
    printf("Enter the title:");
    scanf("%s",&booktitle);
    printf("Enter the author:");
    scanf("%s",&bookauthor);
    printf("Enter the year:");
    scanf("%d",&year);
    printf("Enter the copies:");
    scanf("%d",&copies);
    Book *new = (Book *) malloc(sizeof (Book));
    new->id=id;

    new->title = (char *) malloc(100*sizeof (char));
    new->title= strddd(booktitle);
    new->title[strlen(new->title)] = '\0';
    new->authors = (char *) malloc(100*sizeof (char));
    new->authors= strddd(bookauthor);
    new->authors[strlen(new->authors)] = '\0';
    new->year=year;
    new->copies=copies;
    temp->next = new;
    new->next = NULL;
    return 0;

}
int remove_book(Book*head){

    display(head);
    int a;
    printf("Pleaser enter the id to remove the book:");
    scanf("%i",&a);

    return 0;
}
int store_books(FILE *file,Book *head){

    Book *temp=head;
    while (temp->next!=NULL){
    temp=temp->next;
    fprintf(file,"%i",temp->id);
    fprintf(file,";");
    fprintf(file,"%s",temp->title);
    fprintf(file,";");
    fprintf(file,"%s",temp->authors);
    fprintf(file,";");
    fprintf(file,"%i",temp->year);
    fprintf(file,";");
    fprintf(file,"%i",temp->copies);
    fprintf(file,"\n");
    }
    return 0;

}
int load_books(FILE *file,Book*head){

    char line[300];
    if(NULL == file)
    {
        printf("FILE NOT FOUND");
        exit(-1);
    }
    Book *last = head;

    while(fgets(line,300,file)!=NULL){
        Book *temp = (Book *)malloc(sizeof (Book));

        temp->id= atoi(strtok(line,";"));
        temp->title= strddd(strtok(NULL,";"));
        temp->title[strlen(temp->title)] = '\0';

        temp->authors= strddd(strtok(NULL,";"));
        temp->authors[strlen(temp->authors)] = '\0';
        temp->year= atoi(strtok(NULL,";"));
        temp->copies= atoi(strtok(NULL,"\n"));
        last->next = temp;
        last = temp;
        last->next = NULL;
    }



    return 0;



}
void display(Book *head){
    Book *temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
        printf("%i",temp->id);
        printf("\t");
        printf("%s",temp->title);
        printf("\t");
        printf("%s",temp->authors);
        printf("\t");
        printf("%i",temp->year);
        printf("\t");
        printf("%i",temp->copies);
        printf("\n");
    }
    }



