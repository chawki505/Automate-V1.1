//
// Created by chawki chouib on 17/10/2017.
//


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

/** Variable Constante **/

const int tailleTabTransition = 100;
const int tailleTabEtats = 100;

/** Structure de données **/

typedef struct {
    char symbole; // le symbole pour la transition de Q
    int numEtatNext; // l'etat suivant pour le symbole de la transition
} TransitionType;

typedef struct {
    int numEtat; // le num de l'etat Q
    bool init; // si etat Q initial
    bool final; // si etat Q final
    TransitionType transition[tailleTabTransition];
} EtatQType;


typedef struct {
    int nombreEtats; //nombre d'etats dans l'automate
    int nombreAlphabet; //nombre d'alphabet
    EtatQType etatQ[tailleTabEtats]; // tab des etats Q
} AutomateType;

/** Fonction / procedure **/

// retoune la taille d'une chaine de caractere
int tailleChaine(char chaine[]) {
    return (int) strlen(chaine);
}


// retourne un caractere d'une chaine
char caractereChaine(char chaine[], int indice) {
    if (indice >= tailleChaine(chaine)) {
        return -1;
    }
    return chaine[indice];
}


//test si etatQ est un etat final
bool isFinal(EtatQType q) {
    return q.final;
}

//test si etatQ et un etat initial
bool isInit(EtatQType q) {
    return q.init;
}

//retourne next transition sinon -1
 int testSymbole(AutomateType automate, TransitionType tab[tailleTabTransition], char symbole) {

    int var = -1;
    for (int i = 0; i < automate.nombreAlphabet; ++i) {
        if (tab[i].symbole == symbole) {
            var = tab[i].numEtatNext;
            break;
        }
    }
    return var;
}


//methode d'execution de l'automate
void executeAutomate(AutomateType automate, char mot[]) {

    bool status = true;
    int etatChaine = 0;
    int etatQ = 0;
    int tailleMot = tailleChaine(mot);

    printf("debut d'analyse du mot ");
    for (int i = 0; i < tailleMot; ++i) {
        printf("%c", mot[i]);
    }

    printf("\n\n");

    while (status) {

        etatQ = testSymbole(automate, automate.etatQ[etatQ].transition, mot[etatChaine]);

        if (etatQ != -1 && etatChaine < tailleMot) {

            printf("analyse alphabet %c num %d dans Q%d \n", mot[etatChaine], etatChaine, etatQ);
            etatChaine++;

            if (etatChaine == tailleMot && isFinal(automate.etatQ[etatQ])) {
                printf("\ntrue , reconnue par l'automate");
                status = false;
            }
        } else {
            printf("\nfalse , n'est pas reconnue pas l'automate");
            status = false;
        }
    }
}


