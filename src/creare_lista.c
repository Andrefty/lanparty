#include "list.h"
#include "utils.h"

/**
 * @brief Functie ce creaza un nod prin alocare dinamica 
 * si returneaza pointerul nodului creat. 
 * 
 * @param data - informatia nodului respectiv
 * @param next - adresa urmatorului nod
 * @return node* nou nod creat
 */
node *makeNode(int data, char *nume_echipa, concurent *nume_jucatori, node *next)
{
    node *newnod = (node *)malloc(sizeof(node));
    newnod->nume_echipa = strdup(nume_echipa);
    newnod->nume_jucatori = nume_jucatori;
    newnod->next = next;
    return newnod;
}

/**
 * @brief Functie ce returneaza o lista nou creata cu ajutorul
 * datelor citite din fisier-ul file primit ca parametru
 * 
 * Hint:
 *      * folositi-va de metoda makeNode pentru a crea lista
 *      * fscanf returneaza EOF in cazul in care se ajunge la
 *        sfarsitul fisierului => while(fscanf(...)!=EOF) va va 
 *        ajuta sa parcurgeti fisierul
 * 
 * @param file - fisierul ce trebuie citit
 * @return node* 
 */
node *makeList(FILE *file)
{

    int val = 0;
    node *head = NULL;
    fscanf(file, "%d", &val);
    for (int i = 0; i < val; i++)
    {
        char *numeechsta = (char *)calloc(100, sizeof(char));
        char *numememsta = (char *)calloc(50, sizeof(char));
        char *prenumememsta = (char *)calloc(50, sizeof(char));
        node *newnod = (node *)calloc(1, sizeof(node));
        fscanf(file, "%d ", &newnod->numar_jucatori);
        fgets(numeechsta, 100, file);
        newnod->nume_echipa = strdup(numeechsta);
        newnod->nume_jucatori = (concurent *)calloc(newnod->numar_jucatori, sizeof(concurent));
        for (int j = 0; j < newnod->numar_jucatori; j++)
        {
            fscanf(file, "%s", numememsta);
            newnod->nume_jucatori[j].nume = strdup(numememsta);
            fscanf(file, "%s", prenumememsta);
            newnod->nume_jucatori[j].prenume = strdup(prenumememsta);
            fscanf(file, "%d", &newnod->nume_jucatori[j].points);
        }
        newnod->next = head;
        head = newnod;
        free(numeechsta);
        free(numememsta);
        free(prenumememsta);
    }
    return head;
}

/**
 * @brief Functie ce afiseaza toate elementele unei liste
 *  
 * @param head - capul listei de afisat
 */
void print(node *head)
{
    FILE *g = fopen("/export/home/acs/stud/t/tudor.farcasanu/lan-party-02-checker/out/r.out", "w");
    node *n = head;
    while (n != NULL)
    {
        fprintf(g,"%s",n->nume_echipa);
        n = n->next;
    }

    // Nice to have - pentru testare locala in main
}