#include <stdbool.h>
#include "Automate.h"


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

    char chiffre[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    char signe[] = {'+', '-'};


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

    char lettreMinMaj[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                           's',
                           't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
                           'L',
                           'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                           'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};


    ///////////////////////////////////////////////// Q0

    automate.etatQ[0].init = true;
    automate.etatQ[0].final = false;
    automate.etatQ[0].numEtat = 0;

    for (int i = 0; i < automate.nombreAlphabet; ++i) {
        automate.etatQ[0].transition[i].symbole = lettreMinMaj[i];
        automate.etatQ[0].transition[i].numEtatNext = 1;
    }



///////////////////////////////////////////////// Q1

    automate.etatQ[1].init = false;
    automate.etatQ[1].final = true;
    automate.etatQ[1].numEtat = 1;

    for (int i = 0; i < automate.nombreAlphabet; ++i) {
        automate.etatQ[1].transition[i].symbole = lettreMinMaj[i];
        automate.etatQ[1].transition[i].numEtatNext = 1;
    }


    return automate;
}


//automate reconnaisant les commentaire
AutomateType creatAutomateCommentaire() {


    AutomateType automate;
    automate.nombreAlphabet = 65;
    automate.nombreEtats = 7;

    char chiffre[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

    char lettreMinMaj[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                           's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
                           'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                           'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    char caractere[] = {'/', '*', ' '};

    ///////////////////////////////////////////////// Q0

    automate.etatQ[0].init = true;
    automate.etatQ[0].final = false;
    automate.etatQ[0].numEtat = 0;

    automate.etatQ[0].transition[0].symbole = '/';
    automate.etatQ[0].transition[0].numEtatNext = 1;

    automate.etatQ[0].transition[1].symbole = ' ';
    automate.etatQ[0].transition[1].numEtatNext = 0;


    ///////////////////////////////////////////////// Q1

    automate.etatQ[1].init = false;
    automate.etatQ[1].final = false;
    automate.etatQ[1].numEtat = 1;

    automate.etatQ[1].transition[0].symbole = '/';
    automate.etatQ[1].transition[0].numEtatNext = 2;

    automate.etatQ[1].transition[1].symbole = '*';
    automate.etatQ[1].transition[1].numEtatNext = 3;


    ///////////////////////////////////////////////// Q2

    automate.etatQ[2].init = false;
    automate.etatQ[2].final = true;
    automate.etatQ[2].numEtat = 2;


    for (int i = 0; i < 52; ++i) {
        automate.etatQ[2].transition[i].symbole = lettreMinMaj[i];
        automate.etatQ[2].transition[i].numEtatNext = 2;
    }

    for (int j = 52; j < 52 + 10; ++j) {
        automate.etatQ[2].transition[j].symbole = chiffre[j - 52];
        automate.etatQ[2].transition[j].numEtatNext = 2;
    }
    automate.etatQ[2].transition[62].symbole = '/';
    automate.etatQ[2].transition[62].numEtatNext = 2;

    automate.etatQ[2].transition[63].symbole = '*';
    automate.etatQ[2].transition[63].numEtatNext = 2;

    automate.etatQ[2].transition[64].symbole = ' ';
    automate.etatQ[2].transition[64].numEtatNext = 2;






    ///////////////////////////////////////////////// Q3

    automate.etatQ[3].init = false;
    automate.etatQ[3].final = false;
    automate.etatQ[3].numEtat = 3;

    for (int i = 0; i < 52; ++i) {
        automate.etatQ[3].transition[i].symbole = lettreMinMaj[i];
        automate.etatQ[3].transition[i].numEtatNext = 3;
    }

    for (int j = 52; j < 62; ++j) {
        automate.etatQ[3].transition[j].symbole = chiffre[j - 52];
        automate.etatQ[3].transition[j].numEtatNext = 3;
    }

    automate.etatQ[3].transition[62].symbole = ' ';
    automate.etatQ[3].transition[62].numEtatNext = 3;

    automate.etatQ[3].transition[63].symbole = '/';
    automate.etatQ[3].transition[63].numEtatNext = 3;


    automate.etatQ[3].transition[64].symbole = '*';
    automate.etatQ[3].transition[64].numEtatNext = 4;




    ///////////////////////////////////////////////// Q4



    automate.etatQ[4].init = false;
    automate.etatQ[4].final = false;
    automate.etatQ[4].numEtat = 4;


    for (int i = 0; i < 52; ++i) {
        automate.etatQ[4].transition[i].symbole = lettreMinMaj[i];
        automate.etatQ[4].transition[i].numEtatNext = 3;
    }

    for (int j = 52; j < 52 + 10; ++j) {
        automate.etatQ[4].transition[j].symbole = chiffre[j - 52];
        automate.etatQ[4].transition[j].numEtatNext = 3;
    }
    automate.etatQ[4].transition[62].symbole = ' ';
    automate.etatQ[4].transition[62].numEtatNext = 3;

    automate.etatQ[4].transition[63].symbole = '*';
    automate.etatQ[4].transition[63].numEtatNext = 6;


    automate.etatQ[4].transition[64].symbole = '/';
    automate.etatQ[4].transition[64].numEtatNext = 5;



    ///////////////////////////////////////////////// Q5

    automate.etatQ[5].init = false;
    automate.etatQ[5].final = true;
    automate.etatQ[5].numEtat = 5;

    ///////////////////////////////////////////////// Q6

    automate.etatQ[6].init = false;
    automate.etatQ[6].final = false;
    automate.etatQ[6].numEtat = 6;

    for (int i = 0; i < 52; ++i) {
        automate.etatQ[6].transition[i].symbole = lettreMinMaj[i];
        automate.etatQ[6].transition[i].numEtatNext = 3;
    }

    for (int j = 52; j < 52 + 10; ++j) {
        automate.etatQ[6].transition[j].symbole = chiffre[j - 52];
        automate.etatQ[6].transition[j].numEtatNext = 3;
    }
    automate.etatQ[6].transition[62].symbole = ' ';
    automate.etatQ[6].transition[62].numEtatNext = 3;

    automate.etatQ[6].transition[63].symbole = '*';
    automate.etatQ[6].transition[63].numEtatNext = 3;


    automate.etatQ[6].transition[64].symbole = '/';
    automate.etatQ[6].transition[64].numEtatNext = 5;


    return automate;


}


/** Main **/

int main() {

    AutomateType automate1 = createAutomateNombre(); //Nombre
    AutomateType automate2 = createAutomateExemple(); //abc exemple TP
    AutomateType automate3 = createAutomateLettre();  // chaine en lettre


    AutomateType automate4 = creatAutomateCommentaire();

    char mot[] = "/* ceci est un commentaire */";

    // ceci est un commentaire

    /* ceci est un commentaire *//**/

    /** ceci est un commentaire **/

    executeAutomate(automate4, mot);


    return 0;
}
