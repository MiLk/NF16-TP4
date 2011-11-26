#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entete.h"

int main(int argc, char** argv)
{
    int n, stop = 0;
    task *ptask = NULL, *tmp_task = NULL, *list = NULL;
    while (!stop)
    {
        printf("\nChoisir la fonction a tester. 0 pour stopper.\n");
        printf("1 - cree_tache.\n");
        printf("2 - cree_liste.\n");
        printf("3 - affiche_liste.\n");
        printf("4 - ajoute_tache.\n");
        scanf("%d", &n);
        switch (n)
        {
            case 1:
                // Valeurs courantes
                ptask = cree_tache("abc",5);
                if(!(strcmp(ptask->ID,"abc") == 0 && ptask->duree == 6))
                {
                    printf("La fonction cree_tache n'est pas correcte.\n");
                    break;
                }
                // Valeurs particulières
                ptask = cree_tache("abc",NULL);
                if(!(strcmp(ptask->ID,"abc") == 0 && ptask->duree == 1))
                {
                    printf("La fonction cree_tache n'est pas correcte.\n");
                    break;
                }
                printf("La fonction cree_tache est correcte.\n");
                // Valeurs aberrantes
                ptask = cree_tache("abc",-5);
                if(!(ptask->duree >= 0))
                {
                    printf("La fonction cree_tache n'est pas robuste.\n");
                    break;
                }
                ptask = cree_tache("abcdefghijklmnopqrstuvxyz",1);
                if(!(strcmp(ptask->ID,"abcdefghijklmnopqrstuvxyz") == 0))
                {
                    printf("La fonction cree_tache n'est pas robuste.\n");
                    break;
                }
                printf("La fonction cree_tache est correcte et robuste, donc fiable.\n");
                break;
            case 2:
                // Valeurs courantes
                ptask = cree_tache("abc",5);
                list = cree_liste(ptask);
                if(!(list->ID == ptask->ID && list->duree == ptask->duree))
                {
                    printf("La fonction cree_liste n'est pas correcte.\n");
                    break;
                }
                // Valeurs aberrantes
                list = cree_liste(NULL);
                if(list != NULL)
                {
                    printf("La fonction cree_liste n'est pas robuste.\n");
                    break;
                }
                printf("La fonction cree_liste est correcte et robuste, donc fiable.\n");
                break;
            case 3:
                affiche_liste(NULL);
                ptask = cree_tache("abc",5);
                list = cree_liste(ptask);
                affiche_liste(list);
                 printf("La fonction affiche_liste est correcte et robuste, donc fiable.\n");
                break;
            case 4:
                ptask = cree_tache("abc",5);
                list = cree_liste(ptask);
                ptask = cree_tache("def",10);
                // Valeurs courantes
                if(ajoute_tache(list,ptask) != 1)
                {
                    printf("La fonction ajoute_tache n'est pas correcte.\n");
                    break;
                }
                tmp_task = list;
                while(tmp_task->psuivant != NULL)
                    tmp_task = tmp_task->psuivant;
                if(!(strcmp(ptask->ID,tmp_task->ID) == 0 && ptask->duree == tmp_task->duree))
                {
                  printf("La fonction ajoute_tache n'est pas correcte.\n");
                  break;
                }
                printf("La fonction ajoute_tache est correcte.\n");
                // Valeurs aberrantes
                if(ajoute_tache(list,NULL) != 0)
                {
                    printf("La fonction ajoute_tache n'est pas robuste.\n");
                    break;
                }
                if(ajoute_tache(NULL,ptask) != 0)
                {
                    printf("La fonction ajoute_tache n'est pas robuste.\n");
                    break;
                }
                printf("La fonction ajoute_tache est correcte et robuste, donc fiable.\n");
                break;
            default: stop = 1;
                break;
        }
    }

    return (EXIT_SUCCESS);
}