#include <stdio.h>
#include <stdlib.h>
#include "convert.h"

int main(void)
{
    int basei, basef, nombre;
    char *resultat;

    printf("\n************************PROGRAMME DE CONVERTION DE NOMBRES************************\n");
    printf("!!! NB: Pour ce programme, nous n'utiliserons que 04 bases possibles de depart qui sont les bases 2, 8, 10, et 16, et aucune limite pour la base d'arrivée (celle a laquelle vous souhaitez convertir votre nombre)!!! \n\n");
    printf("Veuillez entrer la base du nombre a convertir : ");
    scanf("%d",&basei);
    while(basei != -1 && basei != 2 && basei != 4 && basei != 10 && basei != 16)
    {
        printf("/!\\ Erreur, Veuillez lire les consignes et choisir un nombre entre 2, 4, 10, et 16 selon votre besoin ou encore entrez -1 pour arreter le programme /!\\\n");
        printf("Base de depart : ");
        scanf("%d",&basei);

        if(basei == -1)
        {
            printf("\n\nMerci et à très bientot :)\nSortie du programme...\n");
            return 1;
        }
    }
    printf("Veuillez entrer la base finale (veuillez a laquelle vous souhaitez convertir le nombre : ");
    scanf("%d",&basef);
    
    printf("Veuillez entrer le nombre a convertir : ");

    switch (basei)
    {
    case 2: 
        char binaryNumber[32];
        scanf("%s",binaryNumber);
        int B2D = transition(binaryNumber);
        resultat = check_convert(10, basef, B2D);
        printf("\n\n( %s )%d = ( %s )%d\n\n",binaryNumber, basei, resultat, basef);
        printf("mark2");
        break;

    case 8: 
        scanf("%o",&nombre);
        resultat = check_convert(basei, basef, nombre);
        printf("\n\n( %o )%d = ( %s )%d\n\n",nombre, basei, resultat, basef);
        break;

    case 10: 
        scanf("%d",&nombre);
        resultat = check_convert(basei, basef, nombre);
        printf("\n\n( %d )%d = ( %s )%d\n\n",nombre, basei, resultat, basef);
        break;

    case 16:
        scanf("%x",&nombre);
        resultat = check_convert(basei, basef, nombre);
        printf("\n\n( %X )%d = ( %s )%d\n\n",nombre, basei, resultat, basef);
        break;
    
    }

    free(resultat);
}