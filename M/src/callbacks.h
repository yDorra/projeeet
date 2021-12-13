#include <gtk/gtk.h>


void
on_radiobutton1_HEALTHY_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_UNHEALTHY_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_GLUTEN_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ajouter_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_afficher_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_checkbutton1_SEL_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_chercher__clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_SUPPRIMER_clicked                   (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_MODIFIER_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_checkbutton3_gluten_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton4_sel_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton5_HEALTHY_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton6_UNHEALTHY_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_SUPP_DORRA_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_modifier_dorra_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_checkbutton_11_sel_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_22_GLUTEN_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_RETOOUR_1_AFFICHE_clicked           (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button2_actualiiser_affiiche_clicked
                                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_button_3_retour_modif_clicked       (GtkWidget       *objet_graphique,
                                        gpointer         user_data);
