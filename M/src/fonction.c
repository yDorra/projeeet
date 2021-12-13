#ifdef HAVE_CONFIIG_H
#include <config.h>
#endif



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonction.h"
#include <gtk/gtk.h>

enum{
	EID,
	EJOUR,
	EMOIS,
	EANNEE,
	ETYPE,
	EREPAS,
	ENATURE,
	EENTREE,
	EPLAT_PRINCIPAL,
	EDESSERT,
	COLUMNS

};

/********ajout*****/
void ajout_m(me m,char Menu[])
{
    FILE *f;
    f=fopen(Menu,"a+");
    if (f!=NULL)
    {
    fprintf(f,"%s %d %d %d %s %s %s %s %s %s \n",m.id,m.jour,m.mois,m.annee,m.repas,m.type,m.nature,m.entree,m.plat_principal,m.dessert);
    }
    fclose(f);


}
/**********affiche****/
void affiche_m(GtkWidget *liste, char Menu[])
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	/*char id[100];
	int jour;
	int mois;
	int annee;
	char repas[100];
	char  type[100];
	char  nature[100];
	char entree[100];
	char plat_principal[100];
	char dessert [500];*/
	
	me m;
	char jour1[100];
	char mois1[100];
	char annee1[100];
	store= NULL;
	FILE *f;
	store=gtk_tree_view_get_model(liste);


	if (store == NULL)
	{
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" id" , renderer, "text" , EID  ,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("jour " , renderer, "text" , EJOUR  ,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" mois" , renderer, "text" , EMOIS  ,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("annee " , renderer, "text" , EANNEE  ,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" repas" , renderer, "text" , EREPAS  ,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes("type " , renderer, "text" , ETYPE  ,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" nature" , renderer, "text" , ENATURE  ,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	
	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" entree" , renderer, "text" , EENTREE  ,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" plat_principal" , renderer, "text" , EPLAT_PRINCIPAL  ,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);

	renderer = gtk_cell_renderer_text_new ();
	column = gtk_tree_view_column_new_with_attributes(" dessert" , renderer, "text" , EDESSERT  ,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste), column);
	}
	store=gtk_list_store_new(COLUMNS , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	f=fopen("Menu.txt","r");
	if (f==NULL)
	{
		return;

	}

	else
	{
		f=fopen("Menu.txt","a+");
		while (fscanf(f,"%s %d %d %d %s %s %s %s %s %s \n",m.id , &m.jour , &m.mois , &m.annee , m.repas , m.type , m.nature , m.entree, m.plat_principal , m.dessert)!=EOF)
	{
	//convertir int to char 
	sprintf(jour1, "%d" ,m.jour);
	sprintf(mois1 , "%d ",m.mois);
	sprintf(annee1, "%d ", m.annee);




	gtk_list_store_append (store , &iter);
	gtk_list_store_set (store, &iter,EID, m.id ,EJOUR, jour1 ,EMOIS, mois1 ,EANNEE, annee1 ,EREPAS, m.repas ,ETYPE, m.type ,ENATURE, m.nature ,EENTREE, m.entree, EPLAT_PRINCIPAL,m.plat_principal ,EDESSERT, m.dessert, -1);

	} 
	fclose(f);
	gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL(store));
	g_object_unref (store);

	}
	

}
/********supprimer********/
void supprime_m(char id[] , char Menu[])
{

me b; 
FILE * f ,*g;
	
	f=fopen("Menu.txt","r");
	g=fopen("aux.txt","w");

	if ( (f==NULL ) || (g==NULL))
		return ; 
	else 
	{
		while (fscanf(f,"%s %d %d %d %s %s %s %s %s %s \n", b.id ,&b.jour ,&b.mois , &b.annee, b.repas , b.type , b.nature , b.entree , b.plat_principal , b.dessert)!=EOF)

		
	{

		if ( (strcmp(id,b.id)!=0) )

	fprintf(g,"%s %d %d %d %s %s %s %s %s %s \n", b.id ,b.jour ,b.mois , b.annee, b.repas , b.type , b.nature , b.entree , b.plat_principal , b.dessert);

	}
	
	fclose(f);
	fclose(g);

remove("Menu.txt");
rename("aux.txt","Menu.txt");
	}

}


   

/**********recherche*********/
me recherche_m(char id[],char Menu[])
{
FILE *f=NULL;
  

me a;
me b;          

f = fopen ("Menu.txt", "r");


  if (f!=NULL)
 {
	while (fscanf(f,"%s %d %d %d %s %s %s %s %s %s \n", b.id ,&b.jour ,&b.mois , &b.annee, b.repas , b.type , b.nature , b.entree , b.plat_principal , b.dessert)!=EOF)
    
	if (strcmp (b.id, id) == 0)
	{
        a.jour=b.jour;
	a.mois=b.mois;
        a.annee=b.annee;
	strcpy(a.repas,b.repas);
	strcpy(a.type,b.type);
	strcpy(a.nature,b.nature);
 	strcpy(a.entree,b.entree);
        strcpy(a.plat_principal,b.plat_principal);
	strcpy(a.dessert,b.dessert);
	}
 	
	
        

    
 fclose(f);
 }
return(a);
}



////*****************modiiifierrrr**************//
void modifie_m(me a,char id [],char Menu[])
/*{
	me m1;
	FILE *f,*g;
	char jour[20];
	char mois[20];
	char annee[20];
	char jour2[20];
	char mois2[20];
	char annee2[20];


f=fopen("Menu.txt","r");
g=fopen("aux.txt","w");
    if((f==NULL) && (g==NULL))
{
    return;}
    else
{


sprintf(jour,"%d",m.jour);
sprintf(mois,"%d",m.mois);
sprintf(annee,"%d",m.annee);
sprintf(jour2,"%d",m1.jour);
sprintf(mois2,"%d",m1.mois);
sprintf(annee2,"%d",m1.annee);
    while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s\n",m1.id,jour2,mois2,annee2,m1.repas,m1.type,m1.nature,m1.entree ,m1.plat_principal,m1.dessert)!=EOF)  
    {
      	if (strcmp(m.id,m1.id)!=0)
          fprintf(g,"%s %s %s %s %s %s %s %s %s %s\n",m1.id,jour2,mois2,annee2,m1.repas,m1.type,m1.nature,m1.entree ,m1.plat_principal,m1.dessert);
        else
          fprintf(g,"%s %s %s %s %s %s %s %s %s %s\n",m.id,jour,mois,annee,m.repas,m.type,m.nature,m.entree ,m.plat_principal,m.dessert);
    }
   fclose(f);
   fclose(g);
remove("Menu.txt");
rename("aux.txt","Menu.txt");       
	}

}
*/
{
    FILE *f,*g;
    me b;
   f=fopen("Menu.txt","r");
    g=fopen("aux.txt","w");
    while(fscanf(f,"%s %d %d %d %s %s %s %s %s %s \n", b.id ,&b.jour ,&b.mois , &b.annee, b.repas , b.type , b.nature , b.entree , b.plat_principal , b.dessert)!=EOF)
    {
        if(strcmp(id,b.id)!=0)
          fprintf(g,"%s %d %d %d %s %s %s %s %s %s \n", a.id ,a.jour ,a.mois , a.annee, a.repas ,a.type , a.nature ,a.entree , a.plat_principal ,a.dessert);
        else
          fprintf(g,"%s %d %d %d %s %s %s %s %s %s \n", b.id ,b.jour ,b.mois , b.annee, b.repas , b.type , b.nature , b.entree , b.plat_principal , b.dessert);
    }
    fclose(f);
    fclose(g);
    remove("Menu.txt");
    rename("aux.txt","Menu.txt");
}







