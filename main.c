#include <stdio.h>
#include <string.h>

#include"register.h"
#include "interface.h"
#include "librarian.h"
#include "book_mangement.h"
int main()
{
    int a,b,c;
    a=Face();
    while (a){
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
                    printf("1");
                    return 0;
                }
                if (b == 2) {
                    printf("Welcome,librarian!\n");
                    c = Lib();
                    while (c){
                        switch (c) {
                            case 1:{
                                FILE *fp = fopen("booklist.txt","a");
                                if(add_book(fp,create())==0){
                                    printf("Add successful!");
                                    c=Lib();
                                    if(c!=1){
                                        if(store_books(fp,create())==0){
                                            load_books(fp);
                                        }

                                    }
                                    break;}}
                                case 2:{
                                    return 0;
                            }


                    }
                }}


            case 3:
                return 0;


        }
}}
