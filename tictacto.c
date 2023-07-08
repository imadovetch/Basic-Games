#include <stdio.h>
#include <stdbool.h>
       char Case[][3]={
            {'1','2','3'},
            {'4','5','6'},
            {'7','8','9'}
};
        char x ;
       _Bool error ;

void  swa7() {
    for (int ligne = 0; ligne < 3; ligne++) {
        for (int col = 0; col < 3; col++) {
            printf("%c", Case[ligne][col]);
            if (col < 2) {
                printf("|");
             }}
        printf("\n");
        printf("________\n");
    }}
void mwa7() {
        printf("choose a case ");
        while (scanf("%s", &x) != 1) {
        while (getchar() != '\n');
        error = 0;
        break ;}}
int main ()
{
        swa7();
  while(1){
          int s ;
          printf("Player 1 or 2 : \n""Press 3  to exit : \n ");
         while (scanf("%d", &s) != 1) {
        printf("\nInvalid input.\n please select the player : ");

        while (getchar() != '\n');}
               error = 1;
               if( s == 1 ) { error = 1;
                while( s == 1){
                                 mwa7 () ;
        switch (x)
        {
                case '1':Case[0][0] ='X' ; swa7 () ; break;
                case '2':Case[0][1] ='X' ; swa7 () ; break;
                case '3':Case[0][2] ='X' ; swa7 () ; break;
                case '4':Case[1][0] ='X' ; swa7 () ; break;
                case '5':Case[1][1] ='X' ; swa7 () ; break;
                case '6':Case[1][2] ='X' ; swa7 () ; break;
                case '7':Case[2][0] ='X' ; swa7 () ; break;
                case '8':Case[2][1] ='X' ; swa7 () ; break;
                case '9':Case[2][2] ='X' ; swa7 () ; break;
                default : { error = 0 ; break ; }
                }break ; }
               }else if ( s == 2 ) {
                       while(1){
                                mwa7 ();
        switch (x)
        {
                case '1':Case[0][0] ='O' ; swa7 () ; break;
                case '2':Case[0][1] ='O' ; swa7 () ; break;
                case '3':Case[0][2] ='O' ; swa7 () ; break;
                case '4':Case[1][0] ='O' ; swa7 () ; break;
                case '5':Case[1][1] ='O' ; swa7 () ; break;
                case '6':Case[1][2] ='O' ; swa7 () ; break;
                case '7':Case[2][0] ='O' ; swa7 () ; break;
                case '8':Case[2][1] ='O' ; swa7 () ; break;
                case '9':Case[2][2] ='O' ; swa7 () ; break;
                default:{ error = 0; break ; }
                }break ; }
               } else if (s ==3){  printf("saving and exiting");  return 0 ;   } else{ error = 0 ; printf(" answer a valid number ");  }
  }
                       return 0 ; }
