#include "list.h"
#include "utils.h"
int main()
{
     FILE *f = fopen("/export/home/acs/stud/t/tudor.farcasanu/lan-party-02-checker/date/t1/d.in", READ_MODE);
     node *tet=makeList(f);
     // tet=removeDuplicates(tet);
     print(tet);
}
// int main(int argc, char **argv)
// {
//      FILE *f = fopen(argv[1], READ_MODE);
//      node *tet=makeList(f);
//      // tet=removeDuplicates(tet);
//      print(tet);
// }
