Am folosit structurile node si concurent pentru a memora datele din fisierul transmis ca parametru.
Parametrii sunt captati folosind argc si argv.
Structura node stocheaza:
Numarul de echipe (numar_echipe)
Numarul de jucatori (numar_jucatori)
Punctajul echipei (punctaj_echipa)
Numele echipei (nume_echipa)
Jucatorii ce apartin echipei (vectorul nume_jucatori)
Urmatorul nod (next)
Structura concurent stocheaza:
Numele si prenumele jucatorului (nume,prenume)
Nunarul sau de puncte (numar_puncte)
1. Daca doar prima cerinta este invocata, folosesc makeList pentru a crea lista cu informatiile date,
citind fiecare camp relevant, si calculand punctajul fiecarei echipe.
Pentru campurile ce contin caractere, folosesc vectori de buffer alocati static, alocati apoi dinamic folosind strdup.
Apoi folosesc functia print, ce scrie in fisierul dat.
2. Daca primele 2 cerinte sunt invocate, verific mai intai folosind operatii pe biti daca numarul
de echipe este putere a lui 2. Daca este, folosesc functia makeList si print, ca pentru prima cerinta.
Daca numarul de echipe nu este putere a lui 2, gasesc cea mai apropiata putere a lui 2 
fata de numarul de echipe, si il folosesc pentru a afla cate echipe vor fi sterse.
Pentru a sterge echipele, pasez lista si numarul de echipe de sters functiei removeLast,
in care determin cate o echipa de sters per parcurgere lista, determinand punctajul minim.
Eliberarea spatiului se face astfel incat daca capul listei trebuie sters, acesta se updateaza.
Dupa aceasta, folosesc iar functia print pentru a scrie in fisier.

