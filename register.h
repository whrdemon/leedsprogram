//
// Created by Demon。 on 2022/3/17.
//

#ifndef CWK1_REGISTER_H
#define CWK1_REGISTER_H
typedef struct LNode
{
    char name[100];
    char pass[100];
    struct LNode *next;
} LNode,*pNode;
pNode createList();
int login(pNode head);
void registerUser(pNode head);


#endif //CWK1_REGISTER_H
