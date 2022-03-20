#include <stdio.h>
#include <string.h>

#include"register.h"
#include "interface.h"

int main()
{

    int a;
    a=Face();
    while (a){
        switch (a) {

            case 1:

                registerUser( createList());
                a=Face();
                break;
            case 2:
                login(createList());
                a=Face();
                break;


            case 3:
                printf("y");


            case 4:
                printf("y");


            case 5:
                return 0;



    return 0;
}}}
