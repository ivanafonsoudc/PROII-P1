/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Antonio Vieiro Rial LOGIN 1: antonio.vieiro
 * AUTHOR 2: Ivan Afonso Cerdeira LOGIN 2: ivan.afonso
 * GROUP: 2.4
 * DATE: 19 / 03 / 24
 */

#include "static_list.h"
#include <string.h>

void createEmptyList(tList *L){
    L->lastPos=LNULL;
}

bool isEmptyList(tList L){
    return L.lastPos == LNULL;
}

tPosL first(tList L){
    return 0;
}

tPosL last(tList L){
    return L.lastPos;
}

tPosL next(tPosL p,tList L){
    if(p== last(L)){
        return LNULL;
    }
    else{
        return ++p;
    }
}

tPosL previous(tPosL p,tList L){
    return --p;
}

bool insertItem(tItemL d, tPosL p, tList *L){
    if(L->lastPos == MAX_SIZE){
        return false;
    }
    else if(p==LNULL){
        L->lastPos++;
        L->data[L->lastPos]=d;
    }
    else{
        tPosL i;
        L->lastPos++;
        for(i=L->lastPos;i>=p+1;i--){
            L->data[i]=L->data[i-1];
        }
        L->data[p]=d;
    }
    return true;
}

void deleteAtPosition(tPosL p,tList *L){
    tPosL aux;
    L->lastPos--;
    for(aux=p;aux<=L->lastPos;aux++){
        L->data[aux]=L->data[aux+1];
    }
}

tItemL getItem(tPosL p,tList L){
    return L.data[p];
}

void updateItem(tItemL d,tPosL p, tList *L){
    L->data[p]=d;
}

tPosL findItem(tUserName d, tList L){
    tPosL aux;
    if(isEmptyList(L)){
        return LNULL;
    }
    for(aux=first(L);aux<=L.lastPos;aux++){
        if(strcmp(L.data[aux].userName,d)==0){
            return aux;
        }
    }
    return LNULL;
}
