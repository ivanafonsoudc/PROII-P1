/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practica 1
 * AUTHOR 1: Antonio Vieiro Rial LOGIN 1: antonio.vieiro
 * AUTHOR 2: Ivan Afonso Cerdeira LOGIN 2: ivan.afonso
 * GROUP: 2.4
 * DATE: 19 / 03 / 24
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

#define MAX_BUFFER 255

#ifdef DYNAMIC_LIST
#include "dynamic_list.h"
#endif
#ifdef STATIC_LIST
#include "static_list.h"
#endif

int proBasic(char *c){
    int result=strcmp(c,"basic");
    if(result==0){
        return 0;
    }else{
        return 1;
    }
}

char * CategoryToString(tUserCategory cat){
    switch(cat){
        case 0:
            return "basic";
        case 1:
            return "pro";

        default:
            break;
    }
}

/* New: Pretende dar de alta a un usuario de categoría basic o pro
 * Entradas: Nombre de usuario (tUserName), categoría basic o pro (tUserCategory) y la lista de usuarios pasada por referencia (tList)
 * Salidas: Se imprime un mensaje de exito en caso de que el usuario a insertar no este ya en la lista y la insercion sea correcta
 y uno de error en caso de que no se pueda añadir.
 * PreCD: La categoría pasada a la función ha de ser valida y el usuario a dar de alta no puede existir en la lista.
 * PostCD: N/A
 */

void New(tUserName name, tUserCategory c,tList *L){
    tItemL d;
    strcpy(d.userName,name);
    d.userCategory=c;
    d.numPlay=0;
        if(findItem(name,*L) != LNULL  || !(insertItem(d,LNULL,L))) {
            printf("+ Error: New not possible\n");
        }else{
        printf("* New: user %s category %s\n",d.userName, CategoryToString(d.userCategory));
    }
}

/* Delete: Pretende dar de baja a un usuario
 * Entradas: Nombre del usuario a eliminar (tUserName) y la lista de usuarios pasada por referencia (tList)
 * Salidas: Se imprime un mensaje de exito en caso de que el usuario a eliminar exista y se pueda eliminar
  y uno de error en caso de que no se pueda eliminar (lista vacía o no existe dicho usuario en la lista).
 * PreCD: La lista debe tener al menos un elemento y el usuario a eliminar debe existir dentro de la lista.
 * PostCD: N/A
 */

void Delete(tUserName name, tList *L){
    tPosL p;
    tItemL d;
    p=findItem(name,*L);
    if(p!=LNULL && !isEmptyList(*L)){
        d=getItem(p,*L);
        deleteAtPosition(p,L);
        printf("* Delete: user %s category %s numplays %d\n",d.userName, CategoryToString(d.userCategory),d.numPlay);
    }
    else{
        printf("+ Error: Delete not possible\n");
    }
}

/* Upgrade: Se busca al usuario en la lista y se actualiza su categoría a pro
 * Entradas: Nombre del usuario del cual se quiere actualizar la categoria (tUserName) y la lista de usuarios (tList)
 * Salidas: Se imprime un mensaje de exito en caso de que se haya podido actualizar la categoria del usuario correctamente,
 *          y uno de error en caso de que no se pueda eliminar (La lista esta vacía, el usuario ya tiene categoria pro)
 * PreCD: La lista debe de tener al menos un elemento, y el usuario a actualizar debe de tener categoria basic
 * PostCD: N/A
 */

void Upgrade (tUserName name, tList *L){
    tPosL p;
    tItemL d;
    p = findItem(name,*L);
    if(p!=LNULL && !isEmptyList(*L) && getItem(p,*L).userCategory==0){
        d = getItem(p,*L);
        d.userCategory=1;
        updateItem(d,p,L);
        printf("* Upgrade: user %s category %s\n", getItem(p,*L).userName, CategoryToString(getItem(p,*L).userCategory));
    }else{
        printf("+ Error: Upgrade not possible\n");
    }
}

/* Play: Se busca al usuario en la lista y se incrementa su contador de reproducciones
 * Entradas: Nombre del usuario del cual se quiere aumentar su contador (tUserName), el titulo de la cancion que se reproduce (tSongTitle) y la lista de usuarios (tList)
 * Salidas: Se imprime un mensaje de exito en caso de que se haya podido aumentar el contador de reproducciones del usuario correctamente,
 *          y uno de error en caso de que no se pueda aumentar (La lista esta vacía)
 * PreCD: La lista debe de tener al menos un elemento, y el usuario al cual se le aumenta el contador debe de haberse inicializado
 * PostCD: N/A
 */

void Play (tUserName name, tSongTitle s, tList *L){
    tPosL p;
    tItemL d;
    p = findItem(name,*L);
    if(p!=LNULL && !isEmptyList(*L)){
        d = getItem(p, *L);
        d.numPlay += 1;
        updateItem(d,p,L);
        printf("* Play: user %s plays song %s numplays %d\n", getItem(p,*L).userName,s, getItem(p,*L).numPlay);
    }else{
        printf("+ Error: Play not possible\n");
    }
}

/* Stats: Se muestra la lista completa de usuarios actuales
 * Entradas: Lista de usuarios (tList)
 * Salidas: Se imprime una tabla con el numero de usaurios de cada categoria, sus reproducciones y la media
 * PreCD: La lista debe de tener al menos un elemento inicializado
 * PostCD: N/A
 */


void Stats(tList L){
    tPosL p;
    tItemL d;
    int basic=0, pro=0, basicPlays=0, proPlays=0;
    float basicAvg, proAvg;
    for(p=first(L); p!=LNULL; p=next(p,L)){
        d=getItem(p,L);
        printf("User %s category %s numplays %d\n",d.userName, CategoryToString(d.userCategory), d.numPlay);
        if(d.userCategory==0){
            basic++;
            basicPlays+=d.numPlay;
        }
        else{
            pro++;
            proPlays+=d.numPlay;
        }
    }
    basicAvg= (basic>0) ? (float)basicPlays/basic : 0;
    proAvg=(pro>0) ? (float)proPlays/pro : 0;
    printf("\nCategory  Users\tPlays\tAverage\n");
    printf("Basic\t  %d\t%d\t%.2f\n",basic, basicPlays, basicAvg);
    printf("Pro\t  %d\t%d\t%.2f\n",pro, proPlays, proAvg);
}


void processCommand(char *commandNumber, char command, char *param1, char *param2,tList *L) {
    tItemL auxItem;
    tPosL auxPos;
    printf("********************\n");
    switch (command) {
        case 'N':
            printf("%s %c: user %s category %s\n", commandNumber, command, param1, param2);
            New(param1, proBasic(param2),L);
            break;
        case 'D':
            printf("%s %c: user %s\n", commandNumber, command, param1);
            Delete(param1,L);
            break;
        case 'U':
            printf("%s %c: user %s\n", commandNumber, command, param1);
            Upgrade(param1,L);
            break;
        case 'P':
            printf("%s %c: user %s song %s\n", commandNumber, command, param1, param2);
            Play(param1,param2,L);
            break;
        case 'S':
            printf("%s %c: \n", commandNumber, command);
            Stats(*L);
            break;
        default:
            break;
    }
}

void readTasks(char *filename,tList *L) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2,L);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {
    tList L;
    createEmptyList(&L);
    char *file_name = "play.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
#ifdef INPUT_FILE
        file_name = INPUT_FILE;
#endif
    }

    readTasks(file_name,&L);

    return 0;
}

