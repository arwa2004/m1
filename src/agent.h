#ifndef AGENT_H
#define AGENT_H
#include <gtk/gtk.h>
#include <stdio.h>

#define file_agent "agent.txt"



typedef struct {
    int id;
    char nom[30];
    char prenom[50];
    char cin[30];
    int jour;
    char mois[20];
    int annee;
    char permis[30];
    char sexe[30];
}agent;


int ajouter_agent(char *file, agent a);
void rechercher_agent(const char* file, int id);
int modifier_agent(char *file, int id,agent a1);
void vider(GtkWidget *liste);
void afficher_agent(GtkWidget *liste);
int supprimer_agent(const char* file, int id);
void afficher_agent(GtkWidget *liste);
int rechercher_agentmod(const char* file, int id, agent *a);
/*void afficher_reservation(GtkWidget *liste);*/





#endif

