/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practica 1
 * AUTHOR 1: Antonio Vieiro Rial LOGIN 1: antonio.vieiro
 * AUTHOR 2: Ivan Afonso Cerdeira LOGIN 2: ivan.afonso
 * GROUP: 2.4
 * DATE: 19 / 03 / 24
 */

#ifndef DYNAMIC_LIST_H
#define DYNAMIC_LIST_H

#include "types.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LNULL NULL

typedef struct tNode *tPosL;

struct tNode{
    tItemL data;
    tPosL next;
};

typedef tPosL tList;

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
