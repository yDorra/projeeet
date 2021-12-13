#ifndef FONCTION_H_
#define FONCTION_H_
#include <gtk/gtk.h> 
#include <string.h>
typedef struct 
{
char id[100];
int jour;
int mois;
int annee;
char repas[100];
char  type[100];
char  nature[100];
char entree[100];
char plat_principal[100];
char dessert [500];
}me;  


void ajout_m(me m,char Menu[]);
void affiche_m(GtkWidget *liste ,char Menu[]);
void supprime_m(char id[] , char Menu[]);
me recherche_m(char id[],char Menu[]);
void modifie_m(me m,char id [],char Menu[]);
#endif
