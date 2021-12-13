#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include <string.h> 
#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonction.h"

int t=0;
int n[2]={0,0};
int r=0 , H=0;

void
on_radiobutton1_HEALTHY_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
t=1;

}


void
on_radiobutton2_UNHEALTHY_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
t=2;
}


void
on_checkbutton2_GLUTEN_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
n[1]=1;

}


void
on_ajouter_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
 
GtkWidget *id, *jour, *mois, *annee, *repas, *type, *nature, *plat_principal, *entree, *dessert, *fenetre_ajout_menu_ ;

me m;
fenetre_ajout_menu_=lookup_widget(objet_graphique , " fenetre_ajout_menu_"); 

id=lookup_widget(objet_graphique , "id_menu");
jour=lookup_widget(objet_graphique , "spinbutton1_jour");
mois=lookup_widget(objet_graphique , "spinbutton2_mois");
annee=lookup_widget(objet_graphique , "spinbutton3_annee");
repas=lookup_widget(objet_graphique , "combobox1_repas");
type=lookup_widget(objet_graphique , "type");
nature=lookup_widget(objet_graphique , "nature");
entree=lookup_widget(objet_graphique , "entree");
plat_principal=lookup_widget(objet_graphique , "plat_principal");
dessert=lookup_widget(objet_graphique , "dessert");

strcpy(m.id,gtk_entry_get_text(GTK_ENTRY(id)));
m.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
m.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(m.repas,gtk_combo_box_get_active_text(GTK_COMBO_BOX(repas)));
strcpy(m.entree,gtk_entry_get_text(GTK_ENTRY(entree)));
strcpy(m.plat_principal,gtk_entry_get_text(GTK_ENTRY(plat_principal)));
strcpy(m.dessert,gtk_entry_get_text(GTK_ENTRY(dessert)));
//RADIO
if (t==1)
strcpy(m.type,"HEALTHY");
else 
  {if (t==2)
    strcpy(m.type,"UNHEALTHY"); }

//CHECK

if (n[0]==1)
strcat (m.nature,"\t sans sel");
if (n[1]==1)
strcat (m.nature,"\t sans gluten");


//COMBO
if(strcmp("PETIT DEJEUNER",gtk_combo_box_get_active_text(GTK_COMBO_BOX(repas)))==0)
r=1;
else 
{if(strcmp("DEJEUNER",gtk_combo_box_get_active_text(GTK_COMBO_BOX(repas)))==0)
r=2;
else
{if(strcmp("DINER",gtk_combo_box_get_active_text(GTK_COMBO_BOX(repas)))==0)
r=3;}}
ajout_m(m,"Menu.txt");
}


void
on_afficher_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout_menu_;
GtkWidget *fenetre_affiche_menu;
GtkWidget *treeview1;

fenetre_ajout_menu_=lookup_widget(objet_graphique ,"fenetre_ajout_menu_");

gtk_widget_destroy(fenetre_ajout_menu_);
fenetre_affiche_menu=lookup_widget(objet_graphique,"fenetre_affiche_menu");
fenetre_affiche_menu=create_fenetre_affiche_menu();

gtk_widget_show(fenetre_affiche_menu);

treeview1=lookup_widget(fenetre_affiche_menu,"treeview1");
affiche_m(treeview1,"Menu.txt");

}


void
on_checkbutton1_SEL_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
n[0]=1;
}


void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

GtkTreeIter iter ; 
gchar* id;
gint* jour;
gint* mois;
gint* annee;
gchar* repas;
gchar* type;
gchar* nature;
gchar* entree;
gchar* plat_principal;
gchar* dessert;




me m;
GtkTreeModel *model = gtk_tree_view_get_model(treeview);
if (gtk_tree_model_get_iter(model, &iter , path)) 
{
gtk_tree_model_get (GTK_LIST_STORE(model),&iter ,0, &id,1 , &jour ,2, &mois,3 ,&annee ,4, &repas ,5, &type ,6, &nature ,7, &entree, 8,&plat_principal ,9, &dessert ,-1);


/*strcpy (m.id , id);
m.jour=jour;
m.mois=mois;
m.annee=annee ;
strcpy (m.repas , repas);
strcpy (m.type ,type );
strcpy (m.nature , nature);
strcpy (m.entree , entree);
strcpy (m.plat_principal , plat_principal);
strcpy (m.dessert ,dessert );*/

/*supprime_m(m);*/
affiche_m(treeview,"Menu.txt");

}

}

/********************************!!!!!!!!!!!!!!!!!!****************************************/
void
on_chercher__clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char id2[20];
GtkWidget *id1,*lab38;
FILE *f;
int x=0;
char id[20];
me m ;

id1 = lookup_widget (objet_graphique,"entry5_iden");
lab38 = lookup_widget(objet_graphique, "label38");
strcpy(id2,gtk_entry_get_text(GTK_ENTRY(id1)));

f = fopen ("Menu.txt", "r");
 if (f!=NULL)		
 {
  while (fscanf (f,"%s %d %d %d %s %s %s %s %s %s \n", m.id ,&m.jour ,&m.mois , &m.annee, m.repas , m.type , m.nature , m.entree , m.plat_principal , m.dessert) != EOF)
  {
  
    if (strcmp (id2,m.id) == 0)
      
      x=1;
  }
    
     fclose (f);
  }

if(x==1)
{
    gtk_label_set_text(GTK_LABEL(lab38),"L'IDENTIFIANT EXISTE ");

me b = recherche_m(id2 ,"Menu.txt");

}
else
{
gtk_label_set_text(GTK_LABEL(lab38),"L'IDENTIFIANT N'EXISTE PAS ");
}


}





/*void
on_SUPPRIMER_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}*/
/*****************************modifffff****************///////////////////////333333333333333333333333

void
on_MODIFIER_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *id, *jour, *lab43 , *mois, *annee, *repas, *type, *nature, *plat_principal, *entree, *dessert, *fenetre_modifier ;

me m;
fenetre_modifier=lookup_widget(objet_graphique , " fenetre_modifier"); 
 
id=lookup_widget(objet_graphique , "entry6_idm");
jour=lookup_widget(objet_graphique , "spinbutton1");
mois=lookup_widget(objet_graphique , "spinbutton2");
annee=lookup_widget(objet_graphique , "spinbutton3");
repas=lookup_widget(objet_graphique , "combobox1");
type=lookup_widget(objet_graphique , "type");
nature=lookup_widget(objet_graphique , "nature");
entree=lookup_widget(objet_graphique , "ENTREE_2");
plat_principal=lookup_widget(objet_graphique , "entry8_PP");
dessert=lookup_widget(objet_graphique , "entry9_DESSERT");
lab43 = lookup_widget(objet_graphique,"label43");


strcpy(m.id,gtk_entry_get_text(GTK_ENTRY(id)));
m.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
m.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
m.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(m.repas,gtk_combo_box_get_active_text(GTK_COMBO_BOX(repas)));
strcpy(m.entree,gtk_entry_get_text(GTK_ENTRY(entree)));
strcpy(m.plat_principal,gtk_entry_get_text(GTK_ENTRY(plat_principal)));
strcpy(m.dessert,gtk_entry_get_text(GTK_ENTRY(dessert)));
//RADIO
if (t==1)
strcpy(m.type,"HEALTHY");
else 
  {if (t==2)
    strcpy(m.type,"UNHEALTHY"); }

//CHECK

if (n[0]==1)
strcat (m.nature,"\t sans sel");
if (n[1]==1)
strcat (m.nature,"\t sans gluten");


//COMBO
if(strcmp("PETIT DEJEUNER",gtk_combo_box_get_active_text(GTK_COMBO_BOX(repas)))==0)
r=1;
else 
{if(strcmp("DEJEUNER",gtk_combo_box_get_active_text(GTK_COMBO_BOX(repas)))==0)
r=2;
else
{if(strcmp("DINER",gtk_combo_box_get_active_text(GTK_COMBO_BOX(repas)))==0)
r=3;}}



modifie_m(m,id,"Menu.txt");
gtk_label_set_text(GTK_LABEL(lab43),"MENU MODIFIÉ AVEC SUCCÉS");
}


/*void
on_checkbutton3_gluten_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}*/


/*void
on_checkbutton4_sel_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}*/


void
on_radiobutton5_HEALTHY_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
H=1;
}


void
on_radiobutton6_UNHEALTHY_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if (gtk_toggle_button_get_active(togglebutton))
H=2;

}
/****************suppp*********************/

void
on_SUPP_DORRA_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *entry5,*lab41;
char ID[20];
entry5=lookup_widget(objet_graphique,"entry5_iden");
strcpy(ID,gtk_entry_get_text(GTK_ENTRY(entry5)));
me m;
int x=0;
FILE *f;
lab41 = lookup_widget(objet_graphique, "label41");
f=fopen ("Menu.txt", "r");


  if (f!=NULL)
 {
  while (fscanf (f,"%s %d %d %d %s %s %s %s %s %s \n", m.id ,&m.jour ,&m.mois , &m.annee, m.repas , m.type , m.nature , m.entree , m.plat_principal , m.dessert) != EOF)
  
  {
    if (strcmp (ID,m.id) == 0)
      
     x=1;
  }
    
     fclose (f);}
  

if(x==1)
{
supprime_m(ID,"Menu.txt");
gtk_label_set_text(GTK_LABEL(lab41),"SUPPRESSION AVEC SUCCÉS ");
}
else 
gtk_label_set_text(GTK_LABEL(lab41),"SUPPRESSION IMPOSSIBLE ");
}

/***********************modofier***************/

void
on_button_modifier_dorra_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
char id2[20];
GtkWidget *id1 , *lab42 , *id3 , *Jour , *Mois , *Annee , *Repas , *Nature , *HE , *UNHE , *Entree , *Plat_principal , *Dessert;
FILE *f; 
int x=0;
char id[20];
char jour[20];
char mois[20];
char annee[20];	
me m ;


id1 = lookup_widget (objet_graphique,"entry5_iden");
lab42 = lookup_widget(objet_graphique, "label42");

strcpy(id2,gtk_entry_get_text(GTK_ENTRY(id1)));

f=fopen ("Menu.txt", "r");


  if (f!=NULL)
 {
  while (fscanf (f,"%s %d %d %d %s %s %s %s %s %s \n", m.id ,&m.jour ,&m.mois , &m.annee, m.repas , m.type , m.nature , m.entree , m.plat_principal , m.dessert) != EOF)
  
  {
    if (strcmp (id2,m.id) == 0)
      
     x=1;
  }
    
     fclose (f);}
  

if(x==1)
{
   
GtkWidget *fenetre_affiche_menu;
GtkWidget *fenetre_modifier;

fenetre_affiche_menu=lookup_widget(objet_graphique ,"fenetre_affiche_menu");

gtk_widget_destroy(fenetre_affiche_menu);
fenetre_modifier=lookup_widget(objet_graphique,"fenetre_modifier");
fenetre_modifier=create_fenetre_modifier();

gtk_widget_show(fenetre_modifier);

me m1 = recherche_m(id1,"Menu.txt");

Jour = lookup_widget(objet_graphique, "entry3");
Mois = lookup_widget(objet_graphique, "entry5");
Annee = lookup_widget(objet_graphique, "entry4");
Repas=lookup_widget(objet_graphique, "entry1_re");
Nature = lookup_widget(objet_graphique, "entry2");
HE = lookup_widget(objet_graphique, "radiobutton5_HEALTHY");
UNHE = lookup_widget(objet_graphique, "radiobutton6_UNHEALTHY");
Entree= lookup_widget(objet_graphique, "ENTREE_2");
Plat_principal = lookup_widget(objet_graphique, "entry8_PP");
Dessert = lookup_widget (objet_graphique,"entry9_DESSERT");


fflush(stdin);
sprintf(jour,"%d",m1.jour);
gtk_entry_set_text(GTK_ENTRY(Jour),jour);
sprintf(mois,"%d",m1.mois);
gtk_entry_set_text(GTK_ENTRY(Mois),mois);
sprintf(annee,"%d",m1.annee);
gtk_entry_set_text(GTK_ENTRY(Annee),annee);
fflush(stdin);
gtk_entry_set_text(GTK_ENTRY(Repas),m1.repas);
if(strcmp(m1.type,"HEALTHY")==0)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(HE),TRUE);}
if(strcmp(m1.type,"UNHEALTHY")==0)
{gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(UNHE),TRUE);}
gtk_entry_set_text(GTK_ENTRY(Nature),m1.nature);
gtk_entry_set_text(GTK_ENTRY(Entree),m1.entree);
gtk_entry_set_text(GTK_ENTRY(Plat_principal),m1.plat_principal);
gtk_entry_set_text(GTK_ENTRY(Dessert),m1.dessert);





}
else
{
gtk_label_set_text(GTK_LABEL(lab42),"L'IDENTIFIANT N'EXISTE  pas");
}

}






void
on_checkbutton_11_sel_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
n[0]=1;
}


void
on_checkbutton_22_GLUTEN_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton))
n[1]=1;
}


void
on_RETOOUR_1_AFFICHE_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

GtkWidget *fenetre_affiche_menu;
GtkWidget *fenetre_ajout_menu_;

fenetre_affiche_menu=lookup_widget(objet_graphique ,"fenetre_affiche_menu_");

gtk_widget_destroy(fenetre_affiche_menu);
fenetre_ajout_menu_ =lookup_widget(objet_graphique,"fenetre_ajout_menu_ ");
fenetre_ajout_menu_ =create_fenetre_ajout_menu_ ();

gtk_widget_show(fenetre_ajout_menu_ );


}

/******************************************************************************************************************/
void
on_button2_actualiiser_affiiche_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview1;
GtkWidget *fenetre_affiche_menu;
fenetre_affiche_menu=lookup_widget(objet_graphique,"fenetre_affiche_menu");
treeview1=lookup_widget(fenetre_affiche_menu,"treeview1");
affiche_m(treeview1,"Menu.txt");

}


void
on_button_3_retour_modif_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *fenetre_affiche_menu;
GtkWidget *fenetre_modifier;

fenetre_modifier=lookup_widget(objet_graphique ,"fenetre_modifier");

gtk_widget_destroy(fenetre_modifier);
fenetre_affiche_menu=lookup_widget(objet_graphique,"fenetre_affiche_menu");
fenetre_affiche_menu=create_fenetre_affiche_menu();

gtk_widget_show(fenetre_affiche_menu);

}

