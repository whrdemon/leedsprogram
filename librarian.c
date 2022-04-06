#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "librarian.h"
#include "book_mangement.h"
int check(char *a){
    int b,c;
    c=0;
    for(b=0;b< strlen(a);b++){
        if(a[b]>='0'&&a[b]<='9'){
            c++;
        }
        else
            return 0;
    }
    return 1;

};
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
    scanf("%s",a);
    b=strlen(a);

    while(b>=2||(a[0]!='1'&&a[0]!='2'&&a[0]!='3'&&a[0]!='4'&&a[0]!='5')){
        printf("\n");
        printf("Sorry the option is invalid,please try again.\n");
        printf("Enter your choice:\n");
        printf("1.Add a book\n");
        printf("2.Remove a book\n");
        printf("3.Search for books\n");
        printf("4.Display all books\n");
        printf("5.Quit\n");
        printf("option:");
        scanf("%s",a);
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


int add_book(FILE *file,Book *head){
    Book *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    char *booktitle,*bookauthor,*y,*c,*s;
    int year,copies;
    unsigned  int id;
    bookauthor=(char *)malloc(sizeof(char));
    booktitle=(char *)malloc(sizeof(char));
    y=(char *)malloc(sizeof(char));
    s=(char *)malloc(sizeof(char));
    c=(char *)malloc(sizeof(char));
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
    gets(s);
    printf("Enter the title:");
    gets(booktitle);
    printf("Enter the author:");
    gets(bookauthor);
    Book *x=head;
    while(x->next!=NULL){
        x=x->next;
        if(strcmp(x->title,booktitle)==0&& strcmp(x->authors,bookauthor)==0){
            printf(" The book exists in the library and cannot be added!");
            return 1;
        }
    }
    printf("Enter the year:");
    gets(y);

    if(check(y)==0){
        printf("Please enter the unsigned integer!");
        return 1;
    }

    year= atoi(y);
    printf("Enter the copies:");
    gets(c);
    if(check(c)==0){
        printf("Please enter the unsigned integer!");
        return 1;
    }

    copies= atoi(c);
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
    new->now=copies;
    temp->next = new;
    new->next = NULL;
    return 0;

}
int remove_book(Book*head){
    if(head->next==NULL){
        printf("There are no books in the library, please add them first.");
        return 1;
    }
    display(head);
    int a,b,c;
    char *x;
    x=(char *)malloc(sizeof(char));
    printf("Pleaser enter the id to remove the book:");
    scanf("%s",x);
    if(check(x)==0){
        printf("Please enter a positive integer.");
        return 2;
    }
    a= atoi(x);
    b=0;
    c=0;
    Book *temp=head;

    Book *l=head->next;
    while (l){
        if (l->id== a&&l->copies!=l->now){
            c=1;
        }

        if(c==1) {
            printf("Sorry,this kind of book is being borrowed.Can't remove.");
            return 2;
        }
        l=l->next;

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
        return 2;
    }

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
    fprintf(file,";");
    fprintf(file,"%i",temp->now);
    fprintf(file,"\n");
    }
    return 0;

}
int load_books(FILE *file,Book*head){

    char line[300];
    Book *last = head;

    while(fgets(line,300,file)!=NULL){
        Book *temp = (Book *)malloc(sizeof (Book));

        temp->id= atoi(strtok(line,";"));
        temp->title= strddd(strtok(NULL,";"));
        temp->title[strlen(temp->title)] = '\0';

        temp->authors= strddd(strtok(NULL,";"));
        temp->authors[strlen(temp->authors)] = '\0';
        temp->year= atoi(strtok(NULL,";"));
        temp->copies= atoi(strtok(NULL,";"));
        temp->now= atoi(strtok(NULL,"\n"));
        last->next = temp;
        last = temp;
        last->next = NULL;
    }



    return 0;



}
void display(Book *head){
    Book *temp=head;
	if(head->next==NULL){
		printf("There are no books in the library.");
		return;
				    }

    while (temp->next!=NULL){
        temp=temp->next;
        printf("ID:");
        printf("%i",temp->id);
        printf("\t");
        printf("Title:");
        printf("%s",temp->title);
        printf("\t");
        printf("Authors:");
        printf("%s",temp->authors);
        printf("\t");
        printf("Year:");
        printf("%i",temp->year);
        printf("\t");
        printf("Original Copies:");
        printf("%i",temp->copies);
        printf("\t");
        printf("Available Copies:");
        printf("%i",temp->now);
        printf("\n");
    }
    }

int searcher(){
    char a[10];
    int b;
    printf("\n");
    printf("Enter your choice:\n");
    printf("1.Search books by title\n");
    printf("2.Search books by authors\n");
    printf("3.Search books by year\n");
    printf("4.Quit\n");
    printf("option:");
    scanf("%s",&a);
    b=strlen(a);
    while(b>=2||(a[0]!='1'&&a[0]!='2'&&a[0]!='3'&&a[0]!='4')){
        printf("\n");
        printf("Sorry the option is invalid,please try again.\n");
        printf("Enter your choice:\n");
        printf("1.Search books by title\n");
        printf("2.Search books by authors\n");
        printf("3.Search books by year\n");
        printf("4.Quit\n");
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

}
BookList find_book_by_title (const char *title,Book *head){
    Book *search = (Book*)malloc(sizeof(Book));
    search->next=NULL;
    Book *temp=head;
    Book *last=search;
    while(temp->next!=NULL){
        Book *tt= (Book*)malloc(sizeof(Book));
        temp=temp->next;
        if(strcmp(temp->title,title)==0){

                tt->id=temp->id;
                last->next=tt;
                tt->next=NULL;
                last = tt;
        }
    }


    if(search->next==NULL){

        printf("Can't find the book.");
    }
    if(search->next!=NULL){
        displayfindbook(head,search);

    }



}
BookList find_book_by_author (const char *author,Book *head){
    Book *search = (Book*)malloc(sizeof(Book));
    search->next=NULL;
    Book *temp=head;
    Book *last=search;
    while(temp->next!=NULL){
        Book *tt= (Book*)malloc(sizeof(Book));
        temp=temp->next;
        if(strcmp(temp->authors,author)==0){

            tt->id=temp->id;
            last->next=tt;
            tt->next=NULL;
            last = tt;
        }
    }


    if(search->next==NULL){

        printf("Can't find the book.");
    }
    if(search->next!=NULL){
        displayfindbook(head,search);

    }


}
BookList find_book_by_year (unsigned int year,Book *head){
    Book *search = (Book*)malloc(sizeof(Book));
    search->next=NULL;
    Book *temp=head;
    Book *last=search;
    while(temp->next!=NULL){
        Book *tt= (Book*)malloc(sizeof(Book));
        temp=temp->next;
        if(temp->year==year){

            tt->id=temp->id;
            last->next=tt;
            tt->next=NULL;
            last = tt;
        }
    }


    if(search->next==NULL){

        printf("Can't find the book.");
    }
    if(search->next!=NULL){
        displayfindbook(head,search);

    }
}
int displayfindbook(Book *head,Book *search){


    Book *temp=head;
    Book *aaa=search->next;
    while (temp->next!=0){
        temp=temp->next;
        if(aaa->id==temp->id){
            printf("ID:");
            printf("%i",temp->id);
            printf("\0");
            printf("Title:");
            printf("%s",temp->title);
            printf("\0");
            printf("Authors:");
            printf("%s",temp->authors);
            printf("\0");
            printf("Year:");
            printf("%i",temp->year);
            printf("\0");
            printf("Original Copies:");
            printf("%i",temp->copies);
            printf("\0");
            printf("Available Copies:");
            printf("%i",temp->now);
            printf("\n");
            if(aaa->next)
                aaa=aaa->next;
            else break;
        }

    }

}

