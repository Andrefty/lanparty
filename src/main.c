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
     // FILE *cer = fopen("/export/home/acs/stud/t/tudor.farcasanu/lan-party-02-checker/date/t4/c.in", READ_MODE);
     // FILE *f = fopen("/export/home/acs/stud/t/tudor.farcasanu/lan-party-02-checker/date/t4/d.in", READ_MODE);
     fscanf(cer, "%d%d%d%d%d", &vcer[0], &vcer[1], &vcer[2], &vcer[3], &vcer[4]);
     if (vcer[0] == 1 && vcer[1] == 0)
     {
          node *tet = makeList(f);
          print(tet, argv[3]);
          // print(tet, "/export/home/acs/stud/t/tudor.farcasanu/lan-party-02-checker/out/out3.out");
     }
     if (vcer[1] == 1 && vcer[0] == 1)
     {
          int tmp = 0;
          node *tet = makeList(f);
          if (((tet->numar_echipe) & (tet->numar_echipe - 1)) == 0)
               print(tet, argv[3]);
               // print(tet, "/export/home/acs/stud/t/tudor.farcasanu/lan-party-02-checker/out/out3.out");
          else
          {
               for (int i = tet->numar_echipe; i >= 1; i--)
               {
                    if ((i & (i - 1)) == 0)
                    {
                         tmp = i;
                         break;
                    }
               }
               tet = removeLast(tet, ((tet->numar_echipe) - tmp));
               tet->numar_echipe = (tet->numar_echipe) - tmp;
               print(tet, argv[3]);
               // print(tet, "/export/home/acs/stud/t/tudor.farcasanu/lan-party-02-checker/out/out4.out");
          }
     }
}
