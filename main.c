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


//methode de creation de l'automate
AutomateType createAutomateExemple() {

    AutomateType automate;
    automate.nombreAlphabet = 3;
    automate.nombreEtats = 4;

    ///////////////////////////////////////////////// Q0

    automate.etatQ[0].init = true;
    automate.etatQ[0].final = false;
    automate.etatQ[0].numEtat = 0;

    automate.etatQ[0].transition[0].symbole = 'a';
    automate.etatQ[0].transition[0].numEtatNext = 1;


///////////////////////////////////////////////// Q1

    automate.etatQ[1].init = false;
    automate.etatQ[1].final = true;
    automate.etatQ[1].numEtat = 1;

    automate.etatQ[1].transition[0].symbole = 'a';
    automate.etatQ[1].transition[0].numEtatNext = 1;

    automate.etatQ[1].transition[1].symbole = 'b';
    automate.etatQ[1].transition[1].numEtatNext = 2;


    ///////////////////////////////////////////////// Q2

    automate.etatQ[2].init = false;
    automate.etatQ[2].final = false;
    automate.etatQ[2].numEtat = 2;

    automate.etatQ[2].transition[0].symbole = 'c';
    automate.etatQ[2].transition[0].numEtatNext = 3;



    ///////////////////////////////////////////////// Q3

    automate.etatQ[3].init = false;
    automate.etatQ[3].final = true;
    automate.etatQ[3].numEtat = 3;

    automate.etatQ[3].transition[0].symbole = 'a';
    automate.etatQ[3].transition[0].numEtatNext = 1;


    return automate;
}


//methode de creation de l'automate reconnaisant les nombres
AutomateType createAutomateNombre() {


    AutomateType automate;
    automate.nombreAlphabet = 12;
    automate.nombreEtats = 3;

    char chiffre[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    char signe[2] = {'+', '-'};


    ///////////////////////////////////////////////// Q0

    automate.etatQ[0].init = true;
    automate.etatQ[0].final = false;
    automate.etatQ[0].numEtat = 0;

    for (int i = 0; i < 10; ++i) {
        automate.etatQ[0].transition[i].symbole = chiffre[i];
        automate.etatQ[0].transition[i].numEtatNext = 1;
    }

    automate.etatQ[0].transition[10].symbole = '-';
    automate.etatQ[0].transition[11].symbole = '+';

    automate.etatQ[0].transition[10].numEtatNext = 2;
    automate.etatQ[0].transition[11].numEtatNext = 2;

///////////////////////////////////////////////// Q1

    automate.etatQ[1].init = false;
    automate.etatQ[1].final = true;
    automate.etatQ[1].numEtat = 1;

    for (int i = 0; i < 10; ++i) {
        automate.etatQ[1].transition[i].symbole = chiffre[i];
        automate.etatQ[1].transition[i].numEtatNext = 1;
    }


    ///////////////////////////////////////////////// Q2

    automate.etatQ[2].init = false;
    automate.etatQ[2].final = false;
    automate.etatQ[2].numEtat = 2;


    for (int i = 0; i < 10; ++i) {
        automate.etatQ[2].transition[i].symbole = chiffre[i];
        automate.etatQ[2].transition[i].numEtatNext = 1;
    }


    return automate;
}


//methode de creation de l'automate reconnaisant les chaine en lettre
AutomateType createAutomateLettre() {


    AutomateType automate;
    automate.nombreAlphabet = 26 + 26;
    automate.nombreEtats = 2;

    char lettreMin[52] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
                          't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                          'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                          'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


    ///////////////////////////////////////////////// Q0

    automate.etatQ[0].init = true;
    automate.etatQ[0].final = false;
    automate.etatQ[0].numEtat = 0;

    for (int i = 0; i < automate.nombreAlphabet; ++i) {
        automate.etatQ[0].transition[i].symbole = lettreMin[i];
        automate.etatQ[0].transition[i].numEtatNext = 1;
    }



///////////////////////////////////////////////// Q1

    automate.etatQ[1].init = false;
    automate.etatQ[1].final = true;
    automate.etatQ[1].numEtat = 1;

    for (int i = 0; i < automate.nombreAlphabet; ++i) {
        automate.etatQ[1].transition[i].symbole = lettreMin[i];
        automate.etatQ[1].transition[i].numEtatNext = 1;
    }


    return automate;
}


/** Main **/

int main() {

    AutomateType automate1 = createAutomateNombre(); //Nombre
    AutomateType automate2 = createAutomateExemple(); //abc exemple TP
    AutomateType automate3 = createAutomateLettre();  // chaine en lettre

    char mot[] = "+1209";

    executeAutomate(automate1, mot);


    return 0;
}
