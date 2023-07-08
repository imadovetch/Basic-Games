#include <stdio.h>
#include <stdlib.h>
#include <time.h>
      char table [][3]={{'1','2','3'},
                       {'4','5','6'},
                       {'7','8','9'}};
    int r1;    int r2; int safi;
    int x;     int y;
     char khtiyar;
    int c ;    int s;
     void cadre (){
            for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
           printf("%c", table[j][k]);
            if (k < 2) {
                printf("|");
            }
        }
        printf("\n");
    }}
    int ksksni (){
            if ((table[0][0] == 'X' && table[0][1] == 'X' && table[0][2] =='X' ) ||
        (table[1][0] == 'X' && table[1][1] ==  'X'&& table[1][2] == 'X') ||
        (table[2][0] =='X'  && table[2][1] ==  'X'&& table[2][2] == 'X') ||
        (table[0][0] ==  'X'&& table[1][0] == 'X' && table[2][0] == 'X') ||
        (table[0][1] == 'X' && table[1][1] == 'X' && table[2][1] == 'X') ||
        (table[0][2] =='X'  && table[1][2] =='X'  && table[2][2] == 'X') ||
        (table[0][0] == 'X'&& table[1][1] ==  'X'&& table[2][2] == 'X') ||
        (table[0][2] == 'X'&& table[1][1] =='X'  && table[2][0] == 'X')) {
            safi = 1;
    }else {  safi = 0;   }
          return safi ;
    }
    int main (){
            printf("**************************bomb game ********************************\n");
            printf ("THE rules are simple : complet a line of X without finding the bomb :\n");
       int  khdma = 1;
       srand (time(NULL));
        int   r1 = rand() % 3 ;
        srand (clock());
        int   r2 = rand()% 3 ;
           c=r1;
           s=r2;
       cadre();
        while(khdma){
                printf("khtar ra9em\n");
                        scanf("%s", &khtiyar  );

               for (x=0 ; x<3 ; x++   ){
                   for (y=0 ; y<3 ;y++ ){
                  if (table[x][y] == khtiyar) {
                          table[x][y] = 'X';
                        //  cadre();
                     if( c == x && s== y ){
                       table[c][s] = '*';
                       printf("***************BOOOOOOOOOOOOOM**************\n");
                      // cadre();
                          khdma = 0;
                     }
                 if(ksksni() ){
                 printf("\n*****Hay hay hay taa ki derti liha*** \n **********CONGRATULATIONS**********\n\n");
                   khdma =0;
                 }
                                              }
                                        }
                    }cadre();
        }
 return 0 ;             }
