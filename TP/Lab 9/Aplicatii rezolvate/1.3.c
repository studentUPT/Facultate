/*Se citeste valoarea unui numar natural nr. Sa se determine catul si restul impartirii lui nr la 8.
(Generalizare: sa se determine catul si restul impartirii lui nr la un numar care este putere a lui 2)
Spre a putea determina catul vom utiliza deplasarea la dreapta cu 3 biti(adica vom realiza echivalent o impartire prin 2^3)
Pentru rest vom folosi expresia nr & 7 (valoarea 7 a restului se obtine din 2^3-1)
Dar 7=111(2) deci toti bitii lui nr se vor anula, cu exceptia ultimilor 3 biti, cei mai din dreapta
Generalizarea se obtine imediat, inlocuind 2^3 cu 2^p
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{   int nr;
    printf("dati nr");
    scanf("%d",&nr);
    printf("\ncatul este %d",(nr>>3));
    printf("\nrestul este %d",(nr&7));
    return 0;
}