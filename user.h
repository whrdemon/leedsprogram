//
// Created by Demon。 on 2022/3/24.
//

#ifndef CWK1_USER_H
#define CWK1_USER_H

#include "book_mangement.h"

int Userface();
int Borrowbook(Book*head,Book *borrow,char *username);
int displayborrowbook(Book *borrow);
Book *borrow(char *username);
int returnbook(Book*head,Book *borrow,char *username);
#endif //CWK1_USER_H

