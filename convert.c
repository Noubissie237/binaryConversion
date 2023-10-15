#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "convert.h"

//  Selection de la fonction de conversion appropriée selon le cas.
char *check_convert(int initialBase, int finalBase, int number)
{
    char *resultat;
    switch(initialBase)
    {
        case 8: resultat = convert_eight_to_other(number, finalBase);break;
        case 10: resultat = convert_ten_to_other(number, finalBase);break;
        case 16: resultat = convert_sixteen_to_other(number, finalBase);break;
    }

    return resultat;
}

// Conversion intermediaire de la base 2 vers la base 10
int transition(const char * binaryNumber)
{
    int resultTransition=0, puissance=1;
    int taille = strlen(binaryNumber);

    for (int i = taille - 1; i >= 0; i--) {
        if (binaryNumber[i] == '1') {
            resultTransition += puissance;
        }
        puissance *= 2;
    }

    return resultTransition;
}

// declaration de la fonction permettant de convertir un nombre de la base 10 vers une quelconque autre base
char *convert_ten_to_other(int number, int finalBase)
{
    int tailleMax = 1;  // Taille initiale du tableau de résultats
    char* resultat = (char*) malloc(tailleMax * sizeof(char));
    int index = 0;

    while (number > 0) 
    {
        // Vérification de la taille actuelle du tableau
        if (index == tailleMax) {
            tailleMax *= 2;  // Double la taille du tableau
            resultat = (char*) realloc(resultat, tailleMax * sizeof(char));
        }

        int reste = number % finalBase;
        resultat[index] = (reste < 10) ? (reste + '0') : (reste - 10 + 'A');
        number /= finalBase;
        index++;
    }

    // Ajout du caractère de fin de chaîne
    resultat[index] = '\0';

    // Inversion du résultat
    int debut = 0, fin = index - 1;
    while (debut < fin) {
        char temp = resultat[debut];
        resultat[debut] = resultat[fin];
        resultat[fin] = temp;
        debut++;
        fin--;
    }

    return resultat;

} 

// declaration de la fonction permettant de convertir un nombre de la base 8 vers une quelconque autre base
char *convert_eight_to_other(int number, int finalBase)
{
    int tailleMax = 1;
    char* resultat = (char*) malloc(tailleMax * sizeof(char));
    int index = 0;

    // Conversion du nombre de la base 8 vers la base finalBase
    while (number > 0) {
        if (index == tailleMax) {
            tailleMax *= 2;
            resultat = (char*) realloc(resultat, tailleMax * sizeof(char));
        }

        int reste = number % finalBase;
        resultat[index] = (reste < 10) ? (reste + '0') : (reste - 10 + 'A');
        number /= finalBase;
        index++;
    }

    if (index == 0) {
        resultat[index] = '0';
        index++;
    }

    resultat[index] = '\0';

    // Inversion du résultat
    int debut = 0, fin = index - 1;
    while (debut < fin) {
        char temp = resultat[debut];
        resultat[debut] = resultat[fin];
        resultat[fin] = temp;
        debut++;
        fin--;
    }

    return resultat;
}

// declaration de la fonction permettant de convertir un nombre de la base 16 vers une quelconque autre base
char *convert_sixteen_to_other(int number, int finalBase)
{
    int tailleMax = 16;
    char* resultat = (char*) malloc(tailleMax * sizeof(char));
    int index = 0;

    // Conversion du nombre de la base 16 vers la base final
    while (number > 0) {
        if (index == tailleMax) {
            tailleMax *= 2;
            resultat = (char*) realloc(resultat, tailleMax * sizeof(char));
        }

        int reste = number % finalBase;
        resultat[index] = (reste < 10) ? (reste + '0') : (reste - 10 + 'A');
        number /= finalBase;
        index++;
    }

    if (index == 0) {
        resultat[index] = '0';
        index++;
    }

    resultat[index] = '\0';

    // Inversion du résultat
    int debut = 0, fin = index - 1;
    while (debut < fin) {
        char temp = resultat[debut];
        resultat[debut] = resultat[fin];
        resultat[fin] = temp;
        debut++;
        fin--;
    }

    return resultat;
}
