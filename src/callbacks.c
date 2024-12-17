#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "agent.h" 

int x,y,n,l;


void
on_radiobutton_femme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))
y=2;
}


void
on_radiobutton_homme_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))
y=1;
}


void
on_radiobutton_oui_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))
x=1;
}


void
on_radiobutton_non_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))
x=2;
}



void
on_button_ajouter_clicked              (GtkWidget       *button,
                                        gpointer         user_data)
{
agent a;
    int t,id,all_empty = 1;
    char idc[20];
    GtkWidget *id1 ,*nom, *prenom, *cin, *jour, *annee, *combobox_ajout;
    GtkWidget *label_ajoutresult, *label_echecajout;
    id1 = lookup_widget(button, "entry30");
    nom = lookup_widget(button, "entry24");
    prenom = lookup_widget(button, "entry25");
    cin = lookup_widget(button, "entry26");
    jour = lookup_widget(button, "spin_jour");
    annee = lookup_widget(button, "spin_annee");
    combobox_ajout = lookup_widget(button, "combobox_ajout");
    label_ajoutresult = lookup_widget(button, "label_ajoutresult"); 

    strcpy(idc,gtk_entry_get_text(GTK_ENTRY(id1)));
    strcpy(a.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
    strcpy(a.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
    strcpy(a.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
    a.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
    a.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));


   if (strlen(idc) > 0 || strlen(a.nom) > 0 || strlen(a.prenom) > 0 || strlen(a.cin) > 0) {
        all_empty = 0;
    }

    if (all_empty) {
        gtk_label_set_text(GTK_LABEL(label_ajoutresult), "Échec : Tous les champs sont vides !");
        return;
    }

    // Validation de l'ID
    if (strlen(idc) == 0 || sscanf(idc, "%d", &id) != 1 || id <= 0) {
        gtk_label_set_text(GTK_LABEL(label_ajoutresult), "Erreur : ID invalide ! Entrez un entier positif.");
        return;
    }


    id=atoi(idc);
    a.id=id;

    const gchar *selected_text = gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox_ajout));
    if (selected_text != NULL) {
        strcpy(a.mois, selected_text);
    } else {
        strcpy(a.mois, "Inconnu");
    }
    a.permis[0] = '\0';
    a.sexe[0] = '\0';
    if (x == 1) strcpy(a.permis, "Oui");
    if (x == 2) strcpy(a.permis, "Non");
    if (y == 1) strcpy(a.sexe, "Homme");
    if (y == 2) strcpy(a.sexe, "Femme");

    t=ajouter_agent(file_agent,a);
    if (t)
    	gtk_label_set_text(GTK_LABEL(label_ajoutresult), "Ajout réussi !");
    else     
	gtk_label_set_text(GTK_LABEL(label_ajoutresult), "echec !");
}


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton_modoui_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))
n=2;
}


void
on_radiobutton_modnon_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))
n=1;
}


void
on_radiobutton_modfemme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))
l=2;
}


void
on_radiobutton_modhomme_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (togglebutton)))
l=1;
}




void
on_button_mod_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{

    GtkWidget *id1 ,*nom1, *prenom, *cin, *jour, *annee, *combobox_mod;
    GtkWidget *label_modresult;
    agent a1;

    int id;
    char idc[20];

    id1 = lookup_widget(button, "entry31");
    nom1 = lookup_widget(button, "entry27");
    prenom = lookup_widget(button, "entry28");
    cin = lookup_widget(button, "entry29");
    jour = lookup_widget(button, "spin_jourmod");
    annee = lookup_widget(button, "spin_anneemod");
    combobox_mod = lookup_widget(button, "combobox_mod");
    label_modresult = lookup_widget(button, "label_modresult");

    strcpy(idc, gtk_entry_get_text(GTK_ENTRY(id1)));
    strcpy(a1.nom, gtk_entry_get_text(GTK_ENTRY(nom1)));
    strcpy(a1.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
    strcpy(a1.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
    a1.jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
    a1.annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

        if (strlen(idc) == 0 || sscanf(idc, "%d", &id) != 1 || id <= 0) {
        gtk_label_set_text(GTK_LABEL(label_modresult), "Erreur: ID invalide! Entrez un entier positif.");
        return;
    }



    id = atoi(idc);
    a1.id = id;

    a1.permis[0] = '\0';
    a1.sexe[0] = '\0';
    if (n == 1) strcpy(a1.permis, "Oui");
    if (n == 2) strcpy(a1.permis, "Non");
    if (l == 1) strcpy(a1.sexe, "Homme");
    if (l == 2) strcpy(a1.sexe, "Femme");




    if (modifier_agent(file_agent,id,a1))
    	gtk_label_set_text(GTK_LABEL(label_modresult), "Agent modification réussite !");
    else     
	gtk_label_set_text(GTK_LABEL(label_modresult), "echec de modification !");

}

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void on_treeview1_row_activated(GtkTreeView *treeview, GtkTreePath *path,
                                GtkTreeViewColumn *column, gpointer user_data)
{
    GtkTreeIter iter;
    gint *id;
    gchar *nom;
    gchar *prenom;
    gchar *cin;
    gint *jour;
    gchar *mois;
    gint *annee;
    gchar *permis;
    gchar *sexe;
    agent a;
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);

    // Vérifier si on peut récupérer la ligne activée
    if (gtk_tree_model_get_iter(model, &iter, path)) {
        // Extraire les données de la ligne activée
        gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0, &id,1, &nom,2, &prenom,3, &cin,4, &jour,5, &mois,6, &annee,7, &permis,8, &sexe,-1);

	a.id=id;
	strcpy(a.nom,nom);
	strcpy(a.prenom,prenom);
	strcpy(a.cin,cin);
	a.jour=jour;
	strcpy(a.mois,mois);
	a.annee=annee;
	strcpy(a.permis,permis);
	strcpy(a.sexe,sexe);
	afficher_agent(treeview);


    }
}



void
on_button_supp_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
    GtkWidget *entry_id, *label_suppresult;
    char id_str[20];
    int id;
    int found = 0;

    entry_id = lookup_widget(GTK_WIDGET(button), "entry_spp");
    label_suppresult = lookup_widget(GTK_WIDGET(button), "label_suppresult");

    // Retrieve the ID from the input field
    strcpy(id_str, gtk_entry_get_text(GTK_ENTRY(entry_id)));

    // Validate the input
    if (strlen(id_str) == 0 || sscanf(id_str, "%d", &id) != 1 || id <= 0) {
        gtk_label_set_text(GTK_LABEL(label_suppresult), "Erreur : ID invalide! Entrez un entier positif.");
        return;
    }

    FILE *f = fopen("agent.txt", "r");
    FILE *temp = fopen("temp_agent.txt", "w");
    if (f == NULL || temp == NULL) {
        gtk_label_set_text(GTK_LABEL(label_suppresult), "Erreur : Impossible d'ouvrir le fichier.");
        if (f != NULL) fclose(f);
        if (temp != NULL) fclose(temp);
        return;
    }

    agent a;

    while (fscanf(f,"%d %s %s %s %d %s %d %s %s \n ",&a.id,a.nom,a.prenom,a.cin,&a.jour,a.mois,&a.annee,a.permis,a.sexe)!=EOF) {
        if (a.id == id) {
            found = 1; // Mark as found but skip writing it to the temp file
        } else {
            // Write all other services to the temporary file
            fprintf(temp, "%d %s %s %s %d %s %d %s %s \n ",a.id,a.nom,a.prenom,a.cin,a.jour,a.mois,a.annee,a.permis,a.sexe);
        }
    }

    fclose(f);
    fclose(temp);

    if (found) {
        // Replace the original file with the temporary file
        remove("agent.txt");
        rename("temp_agent.txt", "agent.txt");
        gtk_label_set_text(GTK_LABEL(label_suppresult), "agent supprimé avec succès.");
    } else {
        // No changes made, delete the temp file
        remove("temp_agent.txt");
        gtk_label_set_text(GTK_LABEL(label_suppresult), "Erreur : ID introuvable.");
    }
}


void
on_button_aff_clicked                  (GtkWidget       *button,
                                        gpointer         user_data)
{

    	GtkWidget *treeview1;
    	treeview1 = lookup_widget(button, "treeview1");
	afficher_agent(treeview1);
}



void
on_button_rech_clicked                 (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *entry_id, *label_rechresult;

    char id_str[20];
    int id;
    int found = 0;

    // Get the ID entry widget and label result widget
    entry_id = lookup_widget(GTK_WIDGET(button), "entry_rech");
    label_rechresult = lookup_widget(GTK_WIDGET(button), "label_rechresult");

    // Retrieve the ID from the input field
    strcpy(id_str, gtk_entry_get_text(GTK_ENTRY(entry_id)));

    // Validate the input
    if (strlen(id_str) == 0 || sscanf(id_str, "%d", &id) != 1 || id <= 0) {
        gtk_label_set_text(GTK_LABEL(label_rechresult), "Erreur : ID invalide! Entrez un entier positif.");
        return;
    }

    FILE *f = fopen("agent.txt", "r");
    if (f == NULL) {
        gtk_label_set_text(GTK_LABEL(label_rechresult), "Erreur : Impossible d'ouvrir le fichier.");
        return;
    }

    agent a;
    char result[256];

    // Traverse the file to find the service with the given ID
    while (fscanf(f, "%d %s %s %s %d %s %d %s %s",&a.id, a.nom, a.prenom, a.cin, &a.jour, a.mois, &a.annee, a.permis, a.sexe)!=EOF) {
        if (a.id == id) {
            snprintf(result, sizeof(result), 
    "Agent trouvé:\nID: %d\nNom: %s\nPrenom: %s\nCIN: %s\nJour: %d\nMois: %s\nAnnee: %d\nPermis: %s\nSexe: %s",
    a.id, a.nom, a.prenom, a.cin, a.jour, a.mois, a.annee, a.permis, a.sexe);

            gtk_label_set_text(GTK_LABEL(label_rechresult), result);
            found = 1;
            break;
        }
    }

    fclose(f);

    // Display message if the service is not found
    if (!found) {
        snprintf(result, sizeof(result), "Erreur : Agent avec ID %d non trouvé.", id);
        gtk_label_set_text(GTK_LABEL(label_rechresult), result);
    }
}


void
on_button_rechmod_clicked(GtkWidget *button, gpointer user_data) {
    GtkWidget *id1, *nom1, *prenom, *cin, *jour, *annee, *combobox_mod, *label_modresult, *radio_homme, *radio_femme, *check_permis_oui, *check_permis_non;
    agent a1;
    char idc[20];
    int id;

    // Récupération des widgets
    id1 = lookup_widget(button, "entry32");
    nom1 = lookup_widget(button, "entry27");
    prenom = lookup_widget(button, "entry28");
    cin = lookup_widget(button, "entry29");
    jour = lookup_widget(button, "spin_jourmod");
    annee = lookup_widget(button, "spin_anneemod");
    combobox_mod = lookup_widget(button, "combobox_mod");
    label_modresult = lookup_widget(button, "label_modresult");
    radio_homme = lookup_widget(button, "radiobutton_modhomme");
    radio_femme = lookup_widget(button, "radiobutton_modfemme");
    check_permis_oui = lookup_widget(button, "radiobutton_modoui");
    check_permis_non = lookup_widget(button, "radiobutton_modnon");

    // Récupération de l'ID depuis l'entry
    strcpy(idc, gtk_entry_get_text(GTK_ENTRY(id1)));
    if (strlen(idc) == 0 || sscanf(idc, "%d", &id) != 1 || id <= 0) {
        gtk_label_set_text(GTK_LABEL(label_modresult), "Erreur : ID invalide ! Entrez un entier positif.");
        return;
    }

    // Recherche de l'agent par ID
    if (rechercher_agentmod(file_agent, id, &a1)) {
        // Remplissage des champs avec les données de l'agent trouvé
        gtk_entry_set_text(GTK_ENTRY(nom1), a1.nom);
        gtk_entry_set_text(GTK_ENTRY(prenom), a1.prenom);
        gtk_entry_set_text(GTK_ENTRY(cin), a1.cin);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(jour), a1.jour);
        gtk_spin_button_set_value(GTK_SPIN_BUTTON(annee), a1.annee);

	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio_homme), strcmp(a1.sexe, "Homme") == 0);
    	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(radio_femme), strcmp(a1.sexe, "Femme") == 0);

    	// Définir le permis
    	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check_permis_oui), strcmp(a1.permis, "Oui") == 0);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(check_permis_non), strcmp(a1.permis, "Non") == 0);

        // Définir le mois dans la combobox
        GtkTreeModel *model = gtk_combo_box_get_model(GTK_COMBO_BOX(combobox_mod));
        GtkTreeIter iter;
        gboolean valid = gtk_tree_model_get_iter_first(model, &iter);
        while (valid) {
            gchar *mois;
            gtk_tree_model_get(model, &iter, 0, &mois, -1);
            if (strcmp(mois, a1.mois) == 0) {
                gtk_combo_box_set_active_iter(GTK_COMBO_BOX(combobox_mod), &iter);
                g_free(mois);
                break;
            }
            g_free(mois);
            valid = gtk_tree_model_iter_next(model, &iter);
        }

        gtk_label_set_text(GTK_LABEL(label_modresult), "Agent trouvé.");
    } else {
        gtk_label_set_text(GTK_LABEL(label_modresult), "Erreur : ID introuvable.");
    }
}



void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
   /* GtkTreeIter iter;
    gint *id, *jour, *mois, *annee;
    gchar *nom, *prenom, *cin, *nom_parking;
    reservation r; 
    GtkTreeModel *model = gtk_tree_view_get_model(treeview);


    if (gtk_tree_model_get_iter(model, &iter, path)) {

        gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0, &nom,1, &prenom,2, &cin,3, &nom_parking,4, &id,5, &jour,6, &mois,7, &annee,-1);


        r.id = *id;
        strcpy(r.client_info.nom, nom);
        strcpy(r.client_info.prenom, prenom);
        strcpy(r.client_info.cin, cin);
        strcpy(r.nom_parking, nom_parking);
        r.date_reservation.jour = *jour;
        r.date_reservation.mois = *mois;
        r.date_reservation.annee = *annee;

        }*/
}

void
on_button_reser_rech_clicked           (GtkWidget       *button,
                                        gpointer         user_data)
{
    /*GtkWidget *spinbutton_reserjour = GTK_WIDGET(gtk_builder_get_object(GTK_BUILDER(user_data), "spinbutton_reserjour"));
    GtkWidget *combobox_reser = GTK_WIDGET(gtk_builder_get_object(GTK_BUILDER(user_data), "combobox_reser"));
    GtkWidget *spinbutton_reserannee = GTK_WIDGET(gtk_builder_get_object(GTK_BUILDER(user_data), "spinbutton_reserannee"));
    GtkWidget *treeview2 = GTK_WIDGET(gtk_builder_get_object(GTK_BUILDER(user_data), "treeview2"));
    GtkWidget *label_reser_rech = GTK_WIDGET(gtk_builder_get_object(GTK_BUILDER(user_data), "label_reser_rech"));

    int jour = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_reserjour));
    int mois = gtk_combo_box_get_active(GTK_COMBO_BOX(combobox_reser)) + 1;
    int annee = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton_reserannee));

    FILE *file = fopen(FILE_RESERVATION, "r");
    if (!file)
    {
        gtk_label_set_text(GTK_LABEL(label_reser_rech), "Error: Unable to open reservation file.");
        return;
    }

    reservation r;
    gboolean found = FALSE;

    GtkListStore *store = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(treeview2)));
    gtk_list_store_clear(store);

    while (fscanf(file, "%s %s %s %s %d %d %d %d",r.client_info.nom,r.client_info.prenom,r.client_info.cin,r.nom_parking,&r.client_info.num_telephone,&r.id,&r.date_reservation.jour,&r.date_reservation.mois,&r.date_reservation.annee) == 9)
    {
        if (r.date_reservation.jour == jour &&r.date_reservation.mois == mois &&r.date_reservation.annee == annee)
        {
            found = TRUE;

            GtkTreeIter iter;
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter,0, r.client_info.nom,1, r.client_info.prenom,2, r.client_info.cin,3, r.nom_parking,4, r.id, 5, r.date_reservation.jour,6, r.date_reservation.mois,7, r.date_reservation.annee,-1);
        }
    }

    fclose(file);

    if (!found)
    {
        gtk_label_set_text(GTK_LABEL(label_mod_reser), "No reservations found for the specified date.");
    }
    else
    {
        gtk_label_set_text(GTK_LABEL(label_reser_rech), "");
    }*/

} 








void
on_button_actualiser_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *treeview1;
    	treeview1 = lookup_widget(button, "treeview1");
	vider(treeview1);
	afficher_agent(treeview1);
}


