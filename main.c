#include <stdio.h>
#include <stdlib.h>
#include"register.h"
#include "interface.h"
#include "librarian.h"
#include "book_mangement.h"
#include "user.h"
int main()
{
    int a,b,c,d,p,g,s,bo,us,re;

    Book *head = (Book*)malloc(sizeof(Book));
    head->next=NULL;
    FILE *fo= fopen("user.txt","a");
    fprintf(fo,"librarian");
    fprintf(fo,"\t");
    fprintf(fo,"librarian");
    fprintf(fo,"\n");
    fclose(fo);
    while (1){
        a=Face();
        switch (a) {

            case 1:

                registerUser(createList());
                break;
            case 2:
                b = login(createList());
                if(b==3){
                    break;
                }
                while (b == 0) {
                    b = login(createList());
                }
                if (b == 1) {
                    d=Userface();
                    while(d){
                        switch (d) {


                            case 1: {
                                FILE *fp = fopen("booklist.txt", "r");
                                load_books(fp, head);
                                bo = Borrowbook(head, borrow());
                                if (bo == 0) {
                                    printf("Borrow successfully!\n");
                                    fclose(fp);
                                    FILE *fm= fopen("booklist.txt","w");
                                    store_books(fm,head);
                                    fclose(fm);

                                    d=Userface();
                                    break;

                                }
                                else if(bo==1){
                                    fclose(fp);
                                    d=Userface();
                                    break;
                                }
                            }
                            case 2:{
                                displayborrowbook(borrow());
                                FILE *fp = fopen("booklist.txt", "r");
                                load_books(fp, head);
                                re=returnbook(head,borrow());
                                if (re == 0) {
                                    printf("Return successfully!\n");
                                    fclose(fp);
                                    FILE *fm= fopen("booklist.txt","w");
                                    store_books(fm,head);
                                    fclose(fm);

                                    d=Userface();
                                    break;

                                }
                                else if(re==1){
                                    fclose(fp);
                                    d=Userface();
                                    break;
                                }


                            }
                            case 3:{
                                us=search();
                                unsigned int year;
                                char *title,*t,*y,*author;
                                title=(char *)malloc(sizeof(char));
                                author=(char *)malloc(sizeof(char));
                                t=(char *)malloc(sizeof(char));
                                y=(char *)malloc(sizeof(char));
                                if(us==1){
                                    printf("Please enter the book title:");
                                    FILE *fp=fopen("booklist.txt","r");
                                    load_books(fp,head);
                                    fclose(fp);
                                    gets(t);
                                    gets(title);
                                    find_book_by_title(title,head);
                                    break;
                                }
                                else if(us==2){
                                    printf("Please enter the book authors:");
                                    FILE *fp=fopen("booklist.txt","r");
                                    load_books(fp,head);
                                    fclose(fp);
                                    gets(t);
                                    gets(author);
                                    find_book_by_author(author,head);
                                    break;

                                }
                                else if(us==3){
                                    printf("Please enter the book year:");
                                    FILE *fp=fopen("booklist.txt","r");
                                    load_books(fp,head);
                                    fclose(fp);
                                    gets(t);
                                    gets(y);
                                    year= atoi(y);
                                    find_book_by_year(year,head);
                                    break;

                                }
                                else if(us==4){
                                    d=Userface();
                                    break;
                                }

                            }
                            case 4:{
                                FILE *fp=fopen("booklist.txt","r");
                                load_books(fp,head);
                                fclose(fp);
                                display(head);
                                d=Userface();
                                break;
                            }
                        }
                        if(d==5){
                            break;
                        }
                }}
                if (b == 2) {
                    printf("Welcome,librarian!\n");
                    c = Lib();
                    while (c){
                        switch (c) {
                            case 1:{
                                FILE *fp=fopen("booklist.txt","r");
                                load_books(fp,head);
                                g= add_book(fp,head);
                                if(g==0){
                                    printf("Add successful!");
                                    fclose(fp);
                                    FILE *fm= fopen("booklist.txt","w");
                                    store_books(fm,head);
                                    fclose(fm);
                                    c=Lib();
                                    break;
                                }
                                if(g==1){
                                    fclose(fp);
                                    c=Lib();
                                    break;

                                }}
                            case 2:{
                                FILE *fp=fopen("booklist.txt","r");
                                load_books(fp,head);
                                p= remove_book(head);
                                if(p==1){
                                    fclose(fp);
                                    c=Lib();
                                    break;
                                }
                                else if(p==0){
                                printf("Remove successfully!");
                                fclose(fp);
                                FILE *fm= fopen("booklist.txt","w");
                                store_books(fm,head);
                                fclose(fm);
                                c=Lib();
                                break;}
                                else if(p==2){
                                    fclose(fp);
                                    c=Lib();
                                    break;

                                }

                            }
                            case 3:{
                                s=search();
                                unsigned int year;
                                char *title,*t,*y,*author;
                                title=(char *)malloc(sizeof(char));
                                author=(char *)malloc(sizeof(char));
                                t=(char *)malloc(sizeof(char));
                                y=(char *)malloc(sizeof(char));
                                if(s==1){
                                    printf("Please enter the book title:");
                                    FILE *fp=fopen("booklist.txt","r");
                                    load_books(fp,head);
                                    fclose(fp);
                                    gets(t);
                                    gets(title);
                                    find_book_by_title(title,head);
                                    break;
                                }
                                else if(s==2){
                                    printf("Please enter the book authors:");
                                    FILE *fp=fopen("booklist.txt","r");
                                    load_books(fp,head);
                                    fclose(fp);
                                    gets(t);
                                    gets(author);
                                    find_book_by_author(author,head);
                                    break;

                                }
                                else if(s==3){
                                    printf("Please enter the book year:");
                                    FILE *fp=fopen("booklist.txt","r");
                                    load_books(fp,head);
                                    fclose(fp);
                                    gets(t);
                                    gets(y);
                                    year= atoi(y);
                                    find_book_by_year(year,head);
                                    break;

                                }
                                else if(s==4){
                                    c=Lib();
                                    break;
                                }
                            }

                            case 4:{
                                FILE *fp=fopen("booklist.txt","r");
                                load_books(fp,head);
                                fclose(fp);
                                display(head);
                                c=Lib();
                                break;
                            }


                    }
                    if(c==5){
                        break;
                    }
                }
                }


            case 3:
                printf("Welcome to use it next time. Bye!");
                return 0;


        }
}}
