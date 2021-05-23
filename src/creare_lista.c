#include "list.h"
#include "utils.h"

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
            fscanf(file, "%d", &newnod->nume_jucatori[j].numar_puncte);
            newnod->punctaj_echipa += newnod->nume_jucatori[j].numar_puncte;
        }
        newnod->punctaj_echipa = (newnod->punctaj_echipa) / (newnod->numar_jucatori);
        newnod->next = head;
        head = newnod;
        head->numar_echipe = val;
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
void print(node *head, char *fisier)
{
    FILE *g = fopen(fisier, "w");
    node *n = head;
    while (n != NULL)
    {
        fprintf(g, "%s", n->nume_echipa);
        n = n->next;
    }

    // Nice to have - pentru testare locala in main
}
node *removeLast(node *list, int numar_echipe_s)
{
    node *aux = list, *final = list, *del = NULL, *aux1 = NULL, *del1 = NULL;
    double punctaj_min = INT_MAX - 10.0;
    for (int i = 0; i < numar_echipe_s; i++)
    {
        aux = list;
        aux1 = NULL;
        punctaj_min = INT_MAX - 10.0;
        while (aux != NULL)
        {
            if (aux->punctaj_echipa < punctaj_min)
            {
                punctaj_min = aux->punctaj_echipa;
                del = aux;
                del1 = aux1;
            }
            aux1 = aux;
            aux = aux->next;
        }
        if (del == list)
            list = list->next;
        else
            del1->next = del->next;
        free(del->nume_echipa);
        for (int j = 0; j < del->numar_jucatori; j++)
        {
            free(del->nume_jucatori[j].nume);
            free(del->nume_jucatori[j].prenume);
        }
        free(del->nume_jucatori);
        free(del);
    }
    return final;
}