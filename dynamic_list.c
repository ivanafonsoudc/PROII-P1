/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practica 1
 * AUTHOR 1: Antonio Vieiro Rial LOGIN 1: antonio.vieiro
 * AUTHOR 2: Ivan Afonso Cerdeira LOGIN 2: ivan.afonso
 * GROUP: 2.4
 * DATE: 19 / 03 / 24
 */

#include "dynamic_list.h"

void createEmptyList(tList *L){
    *L=LNULL;
}

bool isEmptyList(tList L){
    return L==LNULL;
}

tPosL first(tList L){
    return L;
}

tPosL last(tList L){
    tPosL i;
    for(i=L;i->next!=LNULL;i=i->next);
    return i;
}

tPosL next(tPosL p, tList L){
    return p->next;
}

tPosL previous(tPosL p, tList L){
    tPosL i;
    if(p==L){
        return LNULL;
    }
    for(i=L;i->next!=p;i=i->next);
    return i;
}


bool createNode(tPosL *p){
    *p= malloc(sizeof(**p));
    return (*p!=LNULL);
}

bool insertItem(tItemL d,tPosL p, tList *L){
    tPosL q,aux;
    if(!createNode(&q)){
        return false;
    }
    else{
        q->data=d;
        q->next=LNULL;
        if(isEmptyList(*L)){
            *L=q;
        }
        else if(p==LNULL){
            for(aux= first(*L);aux->next!=LNULL;aux=aux->next);
            aux->next=q;
        }
        else if(p==*L){
            q->next=p;
            *L=q;
        }
        else{
            q->data=p->data;
            p->data=d;
            q->next=p->next;
            p->next=q;
        }
        return true;
    }

}


void deleteAtPosition(tPosL p,tList *L){
    tPosL aux;
    if(isEmptyList(*L)){
        return;
    }
    else if(p==*L){
        *L=p->next;
        free(p);
    }
    else{
        for(aux=*L;aux->next!=p;aux=aux->next);
        aux->next=p->next;
        p->next=LNULL;
        free(p);
    }
}

tItemL getItem(tPosL p, tList L){
    return p->data;
}

void updateItem(tItemL d,tPosL p,tList *L){
    p->data=d;
}

tPosL findItem(tUserName d,tList L){
    tPosL aux;
    for(aux= first(L);aux!=LNULL;aux=aux->next){
        if(strcmp(aux->data.userName,d)==0){
            return aux;
        }
    }

    return LNULL;
}