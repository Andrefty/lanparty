#include "list.h"
#include "utils.h"

int main(int argc, char **argv)
{
     int vcer[5];
     FILE *cer = fopen(argv[1], READ_MODE);
     FILE *f = fopen(argv[2], READ_MODE);
     fscanf(cer, "%d%d%d%d%d", &vcer[0], &vcer[1], &vcer[2], &vcer[3], &vcer[4]);
     if (vcer[0] == 1 && vcer[1] == 0)
     {
          node *tet = makeList(f);
          print(tet, argv[3]);
     }
     if (vcer[1] == 1 && vcer[0] == 1)
     {
          int tmp = 0, tmp1 = 0;
          node *tet = makeList(f);
          if (((tet->numar_echipe) & (tet->numar_echipe - 1)) == 0)
               print(tet, argv[3]);
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
               tmp1 =(tet->numar_echipe) - tmp;
               tet = removeLast(tet, tmp1);
               tet->numar_echipe = tmp1;
               print(tet, argv[3]);
          }
     }
}
