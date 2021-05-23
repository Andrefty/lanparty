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
Daca doar prima cerinta este invocata, folosesc makeList pentru a crea lista cu informatiile date,
citind fiecare camp relevant, si calculand punctajul fiecarei echipe