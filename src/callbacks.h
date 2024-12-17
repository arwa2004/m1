#include <gtk/gtk.h>


void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_homme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_oui_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_non_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_ajouter_clicked              (GtkWidget      *button,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modnon_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modhomme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_rechmod_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void
on_radiobutton_modoui_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_modfemme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_mod_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_aff_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_supp_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_rech_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_reser_rech_clicked           (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button_actualiser_clicked           (GtkButton       *button,
                                        gpointer         user_data);
