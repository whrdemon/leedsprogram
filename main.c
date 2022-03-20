#include <stdio.h>
#include <string.h>

#include"register.h"
#include "interface.h"

int main()
{
    int a,b;
    a=Face();
    while (a){
        switch (a) {

            case 1:

                registerUser( createList());
                a=Face();
                break;
            case 2:
                b= login(createList());
                if(b==0){
                a=Face();
                break;}
                else if(b==1){
                    printf("1");
                    return 0;
                }


            case 3:
                printf("y");


            case 4:
                printf("y");


            case 5:
                return 0;



    return 0;
}}}
