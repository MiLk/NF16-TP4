#include "entete.h"
#include "test.h"

int main(int argc, char** argv)
{
    int n, stop = 0;
    while (!stop)
    {
        printf("\nChoisir la fonction a tester. 0 pour stopper.\n");
        printf("1 - cree_tache.\n");
        printf("2 - cree_liste.\n");
        printf("3 - affiche_liste.\n");
        printf("4 - ajoute_tache.\n");
        printf("5 - annule_tache.\n");
        printf("6 - execute_tache_FIFO.\n");
        printf("7 - depile_tache.\n");
        printf("8 - execute_tache_LIFO.\n");
        printf("9 - load_date.\n");
        printf("10 - load_data2.\n");
        printf("11 - insere_tache.\n");
        printf("12 - insere_tache_priorite.\n");
        printf("13 - fusion_listes.\n");
        printf("14 - MAJ_priorite.\n");
        scanf("%d", &n);
        switch (n)
        {
            case 1:
                displayDiagnostic(test_cree_tache());
                break;
            case 2:
                displayDiagnostic(test_cree_liste());
                break;
            case 3:
                displayDiagnostic(test_affiche_liste());
                break;
            case 4:
                displayDiagnostic(test_ajoute_tache());
                break;
            case 5:
                displayDiagnostic(test_annule_tache());
                break;
            case 6:
                displayDiagnostic(test_execute_tache_FIFO());
                break;
            case 7:
                displayDiagnostic(test_depile_tache());
                break;
            case 8:
                displayDiagnostic(test_execute_tache_LIFO());
                break;
            case 9:
                displayDiagnostic(test_load_data());
                break;
            case 10:
                displayDiagnostic(test_load_data2());
                break;
            case 11:
                displayDiagnostic(test_insere_tache());
                break;
            case 12:
                displayDiagnostic(test_insere_tache_priorite());
                break;
            case 13:
                displayDiagnostic(test_fusion_listes());
                break;
            case 14:
                displayDiagnostic(test_MAJ_priorite());
                break;
            default: stop = 1;
                break;
        }
    }

    return (EXIT_SUCCESS);
}

task* cree_liste_test()
{
    task *list = NULL, *prev, *ptask = (task*) malloc(sizeof (task));
    strcpy(ptask->ID,"abc");
    ptask->duree = 3;
    ptask->priorite = 1;
    ptask->psuivant = NULL;
    list = ptask;
    prev = ptask;
    ptask = (task*) malloc(sizeof (task));
    strcpy(ptask->ID,"def");
    ptask->duree = 15;
    ptask->priorite = 2;
    ptask->psuivant = NULL;
    prev->psuivant = ptask;
    prev = ptask;
    ptask = (task*) malloc(sizeof (task));
    strcpy(ptask->ID,"ghi");
    ptask->duree = 28;
    ptask->priorite = 3;
    ptask->psuivant = NULL;
    prev->psuivant = ptask;
    return list;
}

task* cree_liste_test2()
{
    task *list = NULL, *prev, *ptask = (task*) malloc(sizeof (task));
    strcpy(ptask->ID,"aze");
    ptask->duree = 6;
    ptask->priorite = 1;
    ptask->psuivant = NULL;
    list = ptask;
    prev = ptask;
    ptask = (task*) malloc(sizeof (task));
    strcpy(ptask->ID,"qsd");
    ptask->duree = 18;
    ptask->priorite = 2;
    ptask->psuivant = NULL;
    prev->psuivant = ptask;
    prev = ptask;
    ptask = (task*) malloc(sizeof (task));
    strcpy(ptask->ID,"wxc");
    ptask->duree = 33;
    ptask->priorite = 3;
    ptask->psuivant = NULL;
    prev->psuivant = ptask;
    return list;
}

Resultat getDiagnostic(bool defaut, bool particulier, bool usuel)
{
    Resultat R;
    if ((usuel == false) || (particulier == false)) R = Incorrect;
    else R = Correct;
    if (defaut == true)
    {
        if (R == Correct) R = Fiable;
        else R = Robuste;
    }
    return R;
}

void displayDiagnostic(Resultat res)
{
    char msg[] = "\n-> Cette fonction est %s.\n";
    switch(res)
    {
        case Incorrect:
            printf(msg, "incorrecte");
            break;
        case Correct:
            printf(msg, "correcte");
            break;
        case Robuste:
            printf(msg, "robuste");
            break;
        case Fiable:
            printf(msg, "fiable");
            break;
        default:
            printf("\n\tImpossible d'établir une analyse.\n");
    }
    printf("\n_________________________________________\n");
}

Resultat test_cree_tache()
{
    printf("\n_________________________________________\n");
    return getDiagnostic(cree_tache_cat3(),cree_tache_cat2(),cree_tache_cat1());
}

bool cree_tache_cat1()
{
    printf("\nparametres :\n");
    printf("caract : abc\n");
    printf("duree : 5\n");
    printf("Debut du test\n");
    cree_tache("abc",5);
    printf("Fin du test\n");
    return false;
}

bool cree_tache_cat2()
{
    printf("\nparametres :\n");
    printf("caract : abc\n");
    printf("duree : NULL\n");
    printf("Debut du test\n");
    cree_tache("abc",NULL);
    printf("Fin du test\n");
    return true;
}

bool cree_tache_cat3()
{
    printf("\nparametres :\n");
    printf("caract : abcdefghijklmnopqrstuvxyz\n");
    printf("duree : 1\n");
    printf("Debut du test\n");
    cree_tache("abcdefghijklmnopqrstuvxyz",1);
    printf("Fin du test\n");
    printf("\nparametres :\n");
    printf("caract : abc\n");
    printf("duree : -5\n");
    printf("Debut du test\n");
    cree_tache("abc",-5);
    printf("Fin du test\n");
    printf("\nparametres :\n");
    printf("caract : NULL\n");
    printf("duree : 1\n");
    printf("Debut du test\n");
    printf("L'execution arrete le programme\n");
    printf("Fin du test\n");
    return false;
}

Resultat test_cree_liste()
{
    printf("\n_________________________________________\n");
    return getDiagnostic(cree_liste_cat3(),cree_liste_cat2(),cree_liste_cat1());
}

bool cree_liste_cat1()
{
    task* ptask = (task*) malloc(sizeof (task));
    strcpy(ptask->ID,"abc");
    ptask->duree = 5;
    ptask->priorite = 1;
    ptask->psuivant = NULL;
    printf("\nparametres :\n");
    printf("tache : pointeur de tache non nul\n");
    printf("Debut du test\n");
    cree_liste(ptask);
    printf("Fin du test\n");
    return true;
}

bool cree_liste_cat2()
{
    task* ptask = NULL;
    printf("\nparametres :\n");
    printf("tache : pointeur de tache nul\n");
    printf("Debut du test\n");
    cree_liste(ptask);
    printf("Fin du test\n");
    return true;
}

bool cree_liste_cat3()
{
    printf("\nparametres :\n");
    printf("tache : NULL\n");
    printf("Debut du test\n");
    cree_liste(NULL);
    printf("Fin du test\n");
    return true;
}

Resultat test_affiche_liste()
{
    printf("\n_________________________________________\n");
    return getDiagnostic(affiche_liste_cat3(),affiche_liste_cat2(),affiche_liste_cat1());
}

bool affiche_liste_cat1()
{
    task* list = cree_liste_test();
    printf("\nparametres :\n");
    printf("list_task : liste de plusieurs elements\n");
    printf("Debut du test\n");
    affiche_liste(list);
    printf("Fin du test\n");
    return true;
}

bool affiche_liste_cat2()
{
    task* list = NULL;
    task* ptask = (task*) malloc(sizeof (task));
    strcpy(ptask->ID,"abc");
    ptask->duree = 5;
    ptask->priorite = 1;
    ptask->psuivant = NULL;
    list = ptask;
    printf("\nparametres :\n");
    printf("list_task : liste d'un seul element\n");
    printf("Debut du test\n");
    affiche_liste(list);
    printf("Fin du test\n");
    return true;
}

bool affiche_liste_cat3()
{
    printf("\nparametres :\n");
    printf("list_task : liste vide\n");
    printf("Debut du test\n");
    affiche_liste(NULL);
    printf("Fin du test\n");
    return true;
}

Resultat test_ajoute_tache()
{
    printf("\n_________________________________________\n");
    return getDiagnostic(ajoute_tache_cat3(),ajoute_tache_cat2(),ajoute_tache_cat1());
}

bool ajoute_tache_cat1()
{
    task* list = cree_liste_test();
    task* ptask = (task*) malloc(sizeof (task));
    strcpy(ptask->ID,"xfu");
    ptask->duree = 4;
    ptask->priorite = 1;
    ptask->psuivant = NULL;
    printf("\nparametres :\n");
    printf("list_task : liste non vide\n");
    printf("ptache : tache non nulle\n");
    printf("Debut du test\n");
    ajoute_tache(list,ptask);
    affiche_liste(list);
    printf("Fin du test\n");
    return true;
}

bool ajoute_tache_cat2()
{
    task* list = cree_liste_test();
    printf("\nparametres :\n");
    printf("list_task : liste non vide\n");
    printf("ptache : tache_nulle\n");
    printf("Debut du test\n");
    ajoute_tache(list,NULL);
    affiche_liste(list);
    printf("Fin du test\n");
    return true;
}

bool ajoute_tache_cat3()
{
    task* ptask = (task*) malloc(sizeof (task));
    strcpy(ptask->ID,"abc");
    ptask->duree = 5;
    ptask->priorite = 1;
    ptask->psuivant = NULL;
    printf("\nparametres :\n");
    printf("list_task :\n");
    printf("ptache :\n");
    printf("Debut du test\n");
    ajoute_tache(NULL,ptask);
    printf("Fin du test\n");
    return true;
}

Resultat test_annule_tache()
{
    printf("\n_________________________________________\n");
    return getDiagnostic(annule_tache_cat3(),annule_tache_cat2(),annule_tache_cat1());
}

bool annule_tache_cat1()
{
    task* list = cree_liste_test();
    printf("\nparametres :\n");
    printf("list_task : liste non vide\n");
    printf("caract : identifiant existe dans la liste\n");
    printf("Debut du test\n");
    affiche_liste(list);
    annule_tache(list,"def");
    printf("Il n'est plus possible d'utiliser ou d'afficher la liste\n");
    printf("Fin du test\n");
    return false;
}

bool annule_tache_cat2()
{
    task *list = NULL;
    printf("\nparametres :\n");
    printf("list_task : liste vide\n");
    printf("caract : identifiant n'existe pas dans la liste\n");
    printf("Debut du test\n");
    annule_tache(list,"ghi");
    printf("Fin du test\n");
    return true;
}

bool annule_tache_cat3()
{
    task* list = cree_liste_test();

    printf("\nparametres :\n");
    printf("list_task : pointeur nul\n");
    printf("caract : identifiant non nul\n");
    printf("Debut du test\n");
    annule_tache(NULL,"abc");
    printf("Fin du test\n");

    printf("\nparametres :\n");
    printf("list_task : liste non vide\n");
    printf("caract : identifiant n'existe pas dans la liste\n");
    printf("Debut du test\n");
    annule_tache(list,"ghi");
    printf("Fin du test\n");
    return true;
}

Resultat test_execute_tache_FIFO()
{
    printf("\n_________________________________________\n");
    return getDiagnostic(execute_tache_FIFO_cat3(),execute_tache_FIFO_cat2(),execute_tache_FIFO_cat1());
}

bool execute_tache_FIFO_cat1()
{
    task* list = cree_liste_test();
    printf("\nparametres :\n");
    printf("list_task :\n");
    printf("Debut du test\n");
    affiche_liste(list);
    execute_tache_FIFO(list);
    affiche_liste(list);
    execute_tache_FIFO(list);
    affiche_liste(list);
    printf("Fonctionne en mode LIFO au lieu de FIFO\n");
    printf("Fin du test\n");
    return false;
}

bool execute_tache_FIFO_cat2()
{
    task* list = NULL;
    printf("\nparametres :\n");
    printf("list_task : liste vide\n");
    printf("Debut du test\n");
    execute_tache_FIFO(list);
    printf("Fin du test\n");
    return true;
}

bool execute_tache_FIFO_cat3()
{
    printf("\nparametres :\n");
    printf("list_task : pointeur nul\n");
    printf("Debut du test\n");
    execute_tache_FIFO(NULL);
    printf("Fin du test\n");
    return true;
}

Resultat test_depile_tache()
{
    printf("\n_________________________________________\n");
    return getDiagnostic(depile_tache_cat3(),depile_tache_cat2(),depile_tache_cat1());
}

bool depile_tache_cat1()
{
    task* list = cree_liste_test();
    printf("\nparametres :\n");
    printf("list_task :\n");
    printf("Debut du test\n");
    depile_tache(list);
    printf("Fin du test\n");
    return true;
}

bool depile_tache_cat2()
{
    task* list = NULL;
    printf("\nparametres :\n");
    printf("list_task : liste vide\n");
    printf("Debut du test\n");
    depile_tache(list);
    printf("Fin du test\n");
    return true;
}

bool depile_tache_cat3()
{
    printf("\nparametres :\n");
    printf("list_task : pointeur nul\n");
    printf("Debut du test\n");
    depile_tache(NULL);
    printf("Fin du test\n");
    return true;
}

Resultat test_execute_tache_LIFO()
{
    printf("\n_________________________________________\n");
    return getDiagnostic(execute_tache_LIFO_cat3(),execute_tache_LIFO_cat2(),execute_tache_LIFO_cat1());
}

bool execute_tache_LIFO_cat1()
{
    task* list = cree_liste_test();
    printf("\nparametres :\n");
    printf("list_task :\n");
    printf("Debut du test\n");
    execute_tache_LIFO(list);
    printf("Fonctionne en mode FIFO\n");
    printf("Fin du test\n");
    return false;
}

bool execute_tache_LIFO_cat2()
{
    task* list = NULL;
    printf("\nparametres :\n");
    printf("list_task : liste vide\n");
    printf("Debut du test\n");
    execute_tache_LIFO(list);
    printf("Fin du test\n");
    return true;
}

bool execute_tache_LIFO_cat3()
{
    printf("\nparametres :\n");
    printf("list_task : pointeur nul\n");
    printf("Debut du test\n");
    execute_tache_LIFO(NULL);
    printf("Fin du test\n");
    return true;
}

Resultat test_load_data()
{
    printf("\n_________________________________________\n");
    return getDiagnostic(load_data_cat3(),load_data_cat2(),load_data_cat1());
}

bool load_data_cat1()
{
    printf("\nparametres :\n");
    printf("nom_fichier : fichier présent\n");
    printf("Debut du test\n");
    load_data("tasks.dat");
    printf("Fin du test\n");
    return true;
}

bool load_data_cat2()
{
    printf("\nparametres :\n");
    printf("nom_fichier : fichier inexistant\n");
    printf("Debut du test\n");
    load_data("test.dat");
    printf("Fin du test\n");
    return true;
}

bool load_data_cat3()
{
    printf("\nparametres :\n");
    printf("nom_fichier : valeur nulle\n");
    printf("Debut du test\n");
    printf("Le programme s'arrête\n");
    printf("Fin du test\n");
    return false;
}

Resultat test_load_data2()
{
    printf("\n_________________________________________\n");
    return getDiagnostic(load_data2_cat3(),load_data2_cat2(),load_data2_cat1());
}

bool load_data2_cat1()
{
    printf("\nparametres :\n");
    printf("nom_fichier : fichier existant\n");
    printf("Debut du test\n");
    load_data2("tasksf.dat");
    printf("Fin du test\n");
    return true;
}

bool load_data2_cat2()
{
    printf("\nparametres :\n");
    printf("nom_fichier : fichier inexistant\n");
    printf("Debut du test\n");
    load_data2("test.dat");
    printf("Fin du test\n");
    return true;
}

bool load_data2_cat3()
{
    printf("\nparametres :\n");
    printf("nom_fichier : valeur nulle\n");
    printf("Debut du test\n");
    printf("Le programme s'arrête\n");
    printf("Fin du test\n");
    return false;
}

Resultat test_insere_tache()
{
    printf("\n_________________________________________\n");
    return getDiagnostic(insere_tache_cat3(),insere_tache_cat2(),insere_tache_cat1());
}

bool insere_tache_cat1()
{
    task* list = cree_liste_test();
    task* ptask = (task*) malloc(sizeof (task));
    strcpy(ptask->ID,"xfu");
    ptask->duree = 22;
    ptask->priorite = 2;
    ptask->psuivant = NULL;
    printf("\nparametres :\n");
    printf("list_task : liste non vide\n");
    printf("ptache : tache non nulle\n");
    printf("Debut du test\n");
    list = insere_tache(list,ptask);
    affiche_liste(list);
    printf("Fin du test\n");
    return true;
}

bool insere_tache_cat2()
{
    task* list = cree_liste_test();
    printf("\nparametres :\n");
    printf("list_task : liste non vide\n");
    printf("ptache : tache nulle\n");
    printf("Debut du test\n");
    printf("L'execution arrete le programme\n");
    printf("Fin du test\n");
    return false;
}

bool insere_tache_cat3()
{
    task* ptask = (task*) malloc(sizeof (task));
    strcpy(ptask->ID,"xfu");
    ptask->duree = 22;
    ptask->priorite = 2;
    ptask->psuivant = NULL;
    printf("\nparametres :\n");
    printf("list_task : liste vide\n");
    printf("ptache : tache non nulle\n");
    printf("Debut du test\n");
    printf("L'execution arrete le programme\n");
    printf("Fin du test\n");
    return false;
}

Resultat test_insere_tache_priorite()
{
    printf("\n_________________________________________\n");
    return getDiagnostic(insere_tache_priorite_cat3(),insere_tache_priorite_cat2(),insere_tache_priorite_cat1());
}

bool insere_tache_priorite_cat1()
{
    task* list = cree_liste_test();
    task* ptask = (task*) malloc(sizeof (task));
    strcpy(ptask->ID,"xfu");
    ptask->duree = 22;
    ptask->priorite = 2;
    ptask->psuivant = NULL;
    printf("\nparametres :\n");
    printf("list_task : liste non vide\n");
    printf("ptache : tache non nulle\n");
    printf("Debut du test\n");
    list = insere_tache_priorite(list,ptask);
    affiche_liste(list);
    printf("Fin du test\n");
    return true;
}

bool insere_tache_priorite_cat2()
{
    task* list = cree_liste_test();
    printf("\nparametres :\n");
    printf("list_task : liste non vide\n");
    printf("ptache : tache nulle\n");
    printf("Debut du test\n");
    printf("L'execution arrete le programme\n");
    printf("Fin du test\n");
    return false;
}

bool insere_tache_priorite_cat3()
{
    task* ptask = (task*) malloc(sizeof (task));
    strcpy(ptask->ID,"xfu");
    ptask->duree = 22;
    ptask->priorite = 2;
    ptask->psuivant = NULL;
    printf("\nparametres :\n");
    printf("list_task : liste vide\n");
    printf("ptache : tache non nulle\n");
    printf("Debut du test\n");
    printf("L'execution arrete le programme\n");
    printf("Fin du test\n");
    return false;
}

Resultat test_fusion_listes()
{
    printf("\n_________________________________________\n");
    return getDiagnostic(fusion_listes_cat3(),fusion_listes_cat2(),fusion_listes_cat1());

}

bool fusion_listes_cat1()
{
    task* list1 = cree_liste_test();
    task* list2 = cree_liste_test2();
    printf("\nparametres :\n");
    printf("list_task1 : liste non vide\n");
    printf("list_task2 : liste_non vide\n");
    printf("Debut du test\n");
    list1 = fusion_listes(list1,list2);
    affiche_liste(list1);
    printf("Fin du test\n");
    return true;
}

bool fusion_listes_cat2()
{
    task* list1 = cree_liste_test();
    printf("\nparametres :\n");
    printf("list_task1 : liste non vide\n");
    printf("list_task2 : liste vide \n");
    printf("Debut du test\n");
    fusion_listes(list1,NULL);
    printf("Fin du test\n");
    return true;
}

bool fusion_listes_cat3()
{
    printf("\nparametres :\n");
    printf("list_task1 : liste vide\n");
    printf("list_task2 : liste vide\n");
    printf("Debut du test\n");
    fusion_listes(NULL,NULL);
    printf("Fin du test\n");
    return true;
}

Resultat test_MAJ_priorite()
{
    printf("\n_________________________________________\n");
    return getDiagnostic(MAJ_priorite_cat3(),MAJ_priorite_cat2(),MAJ_priorite_cat1());
}

bool MAJ_priorite_cat1()
{
    task* list = cree_liste_test();
    printf("\nparametres :\n");
    printf("list_task : liste non vide\n");
    printf("Debut du test\n");
    affiche_liste(list);
    printf("%d",MAJ_priorite(list));
    affiche_liste(list);
    printf("Fin du test\n");
    return true;
}

bool MAJ_priorite_cat2()
{
    task* list = NULL;
    printf("\nparametres :\n");
    printf("list_task : liste vide\n");
    printf("Debut du test\n");
    MAJ_priorite(list);
    printf("Fin du test\n");
    return true;
}

bool MAJ_priorite_cat3()
{
    printf("\nparametres :\n");
    printf("list_task : pointeur nul\n");
    printf("Debut du test\n");
    MAJ_priorite(NULL);
    printf("Fin du test\n");
    return true;
}
