#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool decision(char *x,char *o, unsigned char u1[]);
int findWinner(char* array);
void results(int score, int player, char* name1,char* name2);
void printResults(char* array);

void printResults(char* array){
    int ind;
       system("cls");

   printf("     |    |    \n");
   printf("  %c  |  %c | %c \n",array[0],array[1],array[2]);
   printf("-----|----|----\n");
   printf("  %c  |  %c | %c \n",array[3],array[4],array[5]);
   printf("-----|----|----\n");
   printf("  %c  |  %c | %c \n",array[6],array[7],array[8]);
   printf("     |    |    \n");



}

bool decision(char *x,char *o,unsigned char u1[]){
    char dec;
  printf("\n\n");
   do{
     printf("player %s choose X or O:", u1);
     //dec = getchar();
      scanf("%c",&dec); // To receive enter key, so that string will be printed once
       scanf("%c",&dec);
    }while(dec != 'X' && dec != 'x'&& dec != 'O' &&dec != 'o');
   // printf("ok");

    if(dec =='x'||dec =='X'){
         *x = 'x';
         *o= 'o';

    }
    else{
        *x='o';
        *o='x';
    }
    return 1;
}
int findWinner(char* array){

   int checker;
   for(checker = 0 ; checker<9;checker+=3){
    if(array[checker]==array[checker+1] && array[checker+1]==array[checker+2])
        return 1;
   }
   for(checker =0;checker<9;checker+=1){
    if(array[checker]==array[checker+3]&&array[checker+3]==array[checker+6])
        return 1;
   }
   if(array[0]==array[4]&&array[4]==array[8])
    return 1;
   else if(array[2]==array[4]&&array[4]==array[6])
    return 1;
   else if(array[0] != '1' && array[1] != '2'&& array[2]!='3'&&array[3]!='4'&& array[4]!= '5'&& array[5]!='6'&& array[6]!='7' && array[7]!='8'&& array[8] !='9' )
    return 0;
   else
    return -1;
}
void results(int score,int player,char* name1,char* name2){
     if(score== 1)
        if(player==2)
              printf("Congratulations!! %s You Won!",name1);
        else
              printf("Congratulations!! %s You Won!",name2);
    else
         printf("Match Tied\n");
}


int main(){
      char x,o;
      char u1[50],u2[50];
      char dec;
      char positions[]={'1','2','3','4','5','6','7','8','9'};
      int player=1;//initializing player variable for easy calculation.
      int choice; // choice of the position where x or o to be placed.
      int score =-1; //  To determine the winner.
      char symbol ; // to use x or o at the appropriate positions.
     do{
      printf("Enter Player1 name:\n");
      scanf("%s",u1);
      printf("Enter Player2 name:\n");
      scanf("%s",u2);
      ! strcmp(u1,u2)?printf("Please Enter Unique player Names\n\n"): printf("All the best %s and %s\n",u1,u2);
      } while(! strcmp(u1,u2));
       decision(&x,&o,u1);

      do{
       player= ((player%2)?1:2);
       ((player ==1)?printf("%s Enter the position (0-9) of %c to be placed :\n",u1,x):printf("%s Enter the position (0-9) of %c to be placed :\n",u2,o));
       symbol=((player==1)?x:o);
        scanf("%d", &choice);
                if(choice==1 && positions[0]=='1')
                    positions[0]=symbol;
                else if(choice==2 && positions[1]=='2')
                    positions[1]=symbol;
                else if(choice==3 && positions[2]=='3')
                    positions[2]=symbol;
                else if(choice==4 && positions[3]=='4')
                    positions[3]=symbol;
                else if(choice==5 && positions[4]=='5')
                    positions[4]=symbol;
                else if(choice==6 && positions[5]=='6')
                    positions[5]=symbol;
                else if(choice==7 && positions[6]=='7')
                    positions[6]=symbol;
                else if(choice==8 && positions[7]=='8')
                    positions[7]=symbol;
                else if(choice==9 && positions[8]=='9')
                    positions[8]=symbol;
                else {
                        printf("Wrong Selection\n");
                        player--;
                }
                score = findWinner(positions);
               // printf("\n%d\n",score);// to check score.

               printResults(positions);

                player++;
       }while(score == -1);
       results(score,player,u1,u2);

  return EXIT_SUCCESS;
}
