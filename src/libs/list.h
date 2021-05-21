#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct concurent
{
	char *nume;
	char *prenume;
	int points;
} concurent;

typedef struct node
{
	int numar_jucatori;
	char *nume_echipa;
	concurent *nume_jucatori;
	struct node *next;
} node;


/**
 * @brief Functie ce afiseaza toate elementele unei liste
 *  
 * @param head - capul listei de afisat
 */
void print(node *head, char *fisier);

/**
 * @brief Functie ce returneaza o lista nou creata cu ajutorul
 * datelor citite din fisier-ul file primit ca parametru
 * 
 * Hint:
 *      * folositi-va de metoda makeNode pentru a crea lista
 * 
 * @param file - fisierul ce trebuie citit
 * @return node* 
 */
node *makeList(FILE *file);

/**
 * @brief 
 * 
 * @param list 
 * @return node* the head of the list
 */
node *removeDuplicates(node *list);