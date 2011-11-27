#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Resultat { Incorrect, Correct, Robuste, Fiable } Resultat;
typedef enum bool { false, true } bool;

Resultat getDiagnostic(bool defaut, bool particulier, bool usuel);
void displayDiagnostic(Resultat res);

Resultat test_cree_tache();
bool cree_tache_cat1();
bool cree_tache_cat2();
bool cree_tache_cat3();

Resultat test_cree_liste();
bool cree_liste_cat1();
bool cree_liste_cat2();
bool cree_liste_cat3();

Resultat test_affiche_liste();
bool affiche_liste_cat1();
bool affiche_liste_cat2();
bool affiche_liste_cat3();

Resultat test_ajoute_tache();
bool ajoute_tache_cat1();
bool ajoute_tache_cat2();
bool ajoute_tache_cat3();

Resultat test_annule_tache();
bool annule_tache_cat1();
bool annule_tache_cat2();
bool annule_tache_cat3();

Resultat test_execute_tache_FIFO();
bool execute_tache_FIFO_cat1();
bool execute_tache_FIFO_cat2();
bool execute_tache_FIFO_cat3();

Resultat test_depile_tache();
bool depile_tache_cat1();
bool depile_tache_cat2();
bool depile_tache_cat3();

Resultat test_execute_tache_LIFO();
bool execute_tache_LIFO_cat1();
bool execute_tache_LIFO_cat2();
bool execute_tache_LIFO_cat3();

Resultat test_load_data();
bool load_data_cat1();
bool load_data_cat2();
bool load_data_cat3();

Resultat test_load_data2();
bool load_data2_cat1();
bool load_data2_cat2();
bool load_data2_cat3();

Resultat test_insere_tache();
bool insere_tache_cat1();
bool insere_tache_cat2();
bool insere_tache_cat3();

Resultat test_insere_tache_priorite();
bool insere_tache_priorite_cat1();
bool insere_tache_priorite_cat2();
bool insere_tache_priorite_cat3();

Resultat test_fusion_listes();
bool fusion_listes_cat1();
bool fusion_listes_cat2();
bool fusion_listes_cat3();

Resultat test_MAJ_priorite();
bool MAJ_priorite_cat1();
bool MAJ_priorite_cat2();
bool MAJ_priorite_cat3();

#endif // TEST_H_INCLUDED
