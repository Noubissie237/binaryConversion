#ifndef __CONVERT_H__
#define __CONVERT_H__

    /*  Definition des prototypes   */
    char *check_convert(int initialBase, int finalBase, int number); 
    char *convert_ten_to_other(int number, int finalBase); // declaration de la fonction permettant de convertir un nombre de la base 10 vers une quelconque autre base
    char *convert_eight_to_other(int number, int finalBase); // declaration de la fonction permettant de convertir un nombre de la base 8 vers une quelconque autre base
    char *convert_sixteen_to_other(int number, int finalBase); // declaration de la fonction permettant de convertir un nombre de la base 16 vers une quelconque autre base
    int transition(const char * arrayOfNumber);

#endif