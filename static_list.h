/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Antonio Vieiro Rial LOGIN 1: antonio.vieiro
 * AUTHOR 2: Ivan Afonso Cerdeira LOGIN 2: ivan.afonso
 * GROUP: 2.4
 * DATE: 19 / 03 / 24
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H
#define LNULL -1
#define MAX_SIZE 25


#include "types.h"


typedef int tPosL;

typedef struct tList{
    tPosL lastPos;
    tItemL data[MAX_SIZE];
}tList;

void createEmptyList(tList *L);
bool isEmptyList(tList L);
tPosL first(tList L);
tPosL last(tList L);
tPosL next(tPosL p, tList L);
tPosL previous(tPosL p, tList L);
bool insertItem(tItemL d,tPosL p, tList *L);
void deleteAtPosition(tPosL p,tList *L);
tItemL getItem(tPosL p,tList L);
void updateItem(tItemL d,tPosL p,tList *L);
tPosL findItem(tUserName d,tList L);





#endif
