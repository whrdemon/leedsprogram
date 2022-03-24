#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "user.h"
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
        printf("Sorry the option is invalid,please try again.");
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



};

