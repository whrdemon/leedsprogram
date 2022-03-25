#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"register.h"
#include "interface.h"
#include "librarian.h"
#include "book_mangement.h"
#include "user.h"
int main()
{
    int a,b,c,d,p;

    Book *head = (Book*)malloc(sizeof(Book));
    head->next=NULL;
    while (1){
        a=Face();
        switch (a) {

            case 1:

                registerUser(createList());
                a = Face();
                break;
            case 2:
                b = login(createList());
                while (b == 0) {
                    b = login(createList());
                }
                if (b == 1) {

                    printf("Welcome the library!\n");
                    d=Userface();
                    if(d==1){
                        printf("Borrow book");
                    }

                }
                if (b == 2) {
                    printf("Welcome,librarian!\n");
                    c = Lib();
                    while (c){
                        switch (c) {
                            case 1:{
                                FILE *fp=fopen("booklist.txt","r");
                                load_books(fp,head);
                                if(add_book(fp,head)==0){
                                    printf("Add successful!");
                                    fclose(fp);
                                    FILE *fm= fopen("booklist.txt","w");
                                    store_books(fm,head);
                                    fclose(fm);
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
                                printf("Remove successfully!\n");
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

                            case 4:{
                                FILE *fp=fopen("booklist.txt","r");
                                load_books(fp,head);
                                fclose(fp);
                                display(head);
                                c=Lib();

                                break;
                            }
                            case 5:{
                                return 0;
                            }

                    }
                }}


            case 3:
                return 0;


        }
}}
