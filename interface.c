#include <stdio.h>
#include <string.h>
#include "interface.h"
int Face(){
    char a[10];
    int b;
    printf("\n");
    printf("========================================================\n");
    printf("\t");
    printf("Enter your choice:\n");
    printf("\t");
    printf("1.Register an account\n");
    printf("\t");
    printf("2.Login\n");
    printf("\t");
    printf("3.Quit\n");
    printf("\t");
    printf("option:");
    scanf("%s",&a);
    b=strlen(a);
    while(b>=2||(a[0]!='1'&&a[0]!='2'&&a[0]!='3')){
        printf("\n");
        printf("Sorry the option is invalid,please try again.\n");
        printf("Enter your choice:\n");
        printf("1.Register an account\n");
        printf("2.Login\n");
        printf("3.Quit\n");
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
}
// Created by Demon。 on 2022/3/20.
//

