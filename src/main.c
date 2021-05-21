#include "list.h"
#include "utils.h"
// int main()
// {
//      FILE *f = fopen("/export/home/acs/stud/t/tudor.farcasanu/lan-party-02-checker/date/t1/d.in", READ_MODE);
//      node *tet=makeList(f);
//      // tet=removeDuplicates(tet);
//      print(tet);
// }
int main(int argc, char **argv)
{
     int vcer[5];
     FILE *cer = fopen(argv[1], READ_MODE);
     FILE *f = fopen(argv[2], READ_MODE);
     fscanf(cer, "%d%d%d%d%d", &vcer[0], &vcer[1], &vcer[2], &vcer[3], &vcer[4]);
     if (vcer[0] == 1)
     {
          node *tet = makeList(f);
          // tet=removeDuplicates(tet);
          print(tet,argv[3]);
     }
}
