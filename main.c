#include <stdio.h>
#include <string.h>

#include"register.h"
#include "interface.h"
//das rerere
int main()
{
    char a[10];
    int b;
    printf("Enter your choice:\n");
    printf("1.Register an account\n");
    printf("2.Login\n");
    printf("3.Search for books\n");
    printf("4.Display all books\n");
    printf("5.Quit\n");
    scanf("%s",&a);
    b=strlen(a);

    while(b>=2||(a[0]!='1'&&a[0]!='2'&&a[0]!='3'&&a[0]!='4'&&a[0]!='5')){

        printf("Sorry the option is invalid,please try again.");
        printf("Enter your choice:\n");
        printf("1.Register an account\n");
        printf("2.Login\n");
        printf("3.Search for books\n");
        printf("4.Display all books\n");
        printf("5.Quit\n");
        scanf("%s",&a);
        b=strlen(a);}

    if(a[0]=='1'){

        registerUser( createList());


    }
    else if(a[0]=='2'){
        login(createList());

    }
    else if(a[0]=='3'){
        printf("y");

    }
    else if(a[0]=='4'){
        printf("y");

    }
    else if(a[0]=='5'){
        printf("y");

    }

    return 0;
}
