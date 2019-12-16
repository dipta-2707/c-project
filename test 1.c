#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
int score = 0;
int life = 3;
int x = 0;
int GameMenu();
void StartMenu();
void randomly(int key);
void randword(char word[]);

void lifefun();
void Exit();
void Mode();

void multiplayerMode();
void main()
{
    system("cls");

    if(x == 0)
    {
        ++x;
         StartMenu();
    }
    Mode();


    char check;
   int choice = GameMenu();
    score = 0;
    life = 3;
   switch (choice)
   {
   case 1:
    {
        int key = 6;
        randomly(key);
         break;
    }
   case 2:
    {
        int key = 8;
        randomly( key);
        break;
    }
   case 3:
    {
        int key = 10;
        randomly(key);
        break;
    }
   case 4:
    {
        Exit();
        break;
    }
   }
   system("cls");
   printf("\n\n\n\n\t\t\t-------------------\n");
           printf("\t\t\t|score:     %d    |\n",score);
           printf("\t\t\t-------------------\n");
   fflush(stdin);
   printf("\n\n\t\tDo You Want To Play Again(y/n): ");
   scanf("%c",&check);
   if(check == 'y')
   {
       main();
   }
   else
   {
       Exit();
   }




}
void Mode()
{
    system("cls");
    int mode;
    printf("\n\n\n\n\t\t\t!!!select Game mode!!!\n");
    printf("\t\t\t-------------------\n");
    printf("\t\t\t| 1.Single Player |\n");
    printf("\t\t\t| 2.Multiplayer   |\n");
    printf("\t\t\t-------------------\n");
    printf("\n\t\t\tEnter your choice : ");
    scanf("%d",&mode);
    if(mode == 2)
    {
        multiplayerMode();
    }

}
void Exit()
{
    system("cls");
    printf("\n\n\n\n\n\t\t\tThanks For Playing The Game\n");
    getch();
    exit(0);

}
void lifefun()
{
    char check;

        system("cls");
        fflush(stdin);
        printf("\n\n\n\t\t\t ...GAME OVER...\n");
           printf("\t\t\t-------------------\n");
           printf("\t\t\t|score:     %d    |\n",score);
           printf("\t\t\t-------------------\n");

        printf("\n\t\t\tDo You Want To Play Again(y/n): ");
        scanf("%c",&check);
        system("cls");

        if(check == 'y')
        {
            main();
        }
        else
        {
           Exit();
        }

}

void randomly(int key)
{

    system("cls");
    char path[5];
    int wait;
    if(key == 8)
    {
        strcat(path,"8");
         wait = 7000;
    }
    else if(key == 6)
    {
        strcat(path,"6");
         wait = 5000;
    }
    else if(key == 10)
    {
        strcat(path,"10");
         wait =9000;
    }


    char x[20],y[20];
    strcat(path,".txt");

    FILE *ptr;

    ptr = fopen(path,"r");
    int i=0;
    key+=1;
    while(fscanf(ptr,"%s",&x))
    {

        randword(x);
        Sleep(wait);
        system("cls");
        printf("\n\n\n\n\t\t\t\tEnter your guess word: ");
        scanf("%s",y);
        if(strcmp(x,y)==0)
        {
            ++score;
        }
        else
        {
            --life;
            if(life == -1)
            {
                lifefun();
            }
        }
        i++;
        if(i==10)
            break;
        system("cls");
        fflush(stdin);


    }
}
void randword(char word[])
{

   srand(time(NULL));

    int i=0,j,length,temp;
    length = strlen(word);
    char tempWord[length];
    strcpy(tempWord,word);


    i = length;
    while(--i>0)
    {
        j = (rand()%length);
        temp= tempWord[j];
        tempWord[j]= tempWord[i];
        tempWord[i]= temp;
    }
    printf("\n\t\t\t\t\t\t\t|Life :  %d|\t|Score : %d|\n",life,score);
     printf("\n\n\n\n\n\t\t\t\t.....Your Letters....\n\n\n\t\t\t\t     ");
    for(i=0; i<=length; i++)
    {
        printf("%c ", tempWord[i]);
    }
    fflush(stdin);

    return;

}
int GameMenu()
{
    int choice;

    system("cls");
    printf("\n\n\n\t\t\t-------- Game Menu -------\n");
   printf("\n\t\t\t___________________________\n");
   printf("\t\t\t|1. Six Words Game          |\n");
   printf("\t\t\t|2. Eight Words Game        |\n");
   printf("\t\t\t|3. Ten Words Game          |\n");
   printf("\t\t\t|4.Exit.                    |\n");
   printf("\t\t\t___________________________\n");
   printf("\n\t\t\tEnter choice: ");
   scanf("%d",&choice);
   return choice;
}
void StartMenu()
{
    system("cls");
    char a[]="\n\t\t\t\t1.SINGLE PLAYER-> I will show you some magical letters.\n\t\t\t\tYou have to guess the word using that magical letters.\n\t\t\t\tPlease wait for input untill game request for it.\n\n\t\t\t\t2.MUILTIPLAYER-> player 1 will give a word,then the word's letter will be shuffled.\n\t\t\t\t then 2nd player has to guess what the word was.\n\t\t\t\tThank You...\n\n\n\n\n\t\t\t\t\tpress any key to continue...";
    int i;

    printf("\n\n\n\n\n\n\n\n\t\t\t\t-------- LETS GUESS -------\n");

    printf("\n\n\t\t\t\t'''' Instruction ''''\n");
    printf("\t\t\t\t");
    for(i=0;i<strlen(a);i++)
    {
        printf("%c",a[i]);
        Sleep(30);
    }
    getch();

}
void multiplayerMode()
{
    char mword[15],mword2[15],check;
    system("cls");
    printf("\t\t\t\t\tWelcome to multiplayer mode\n ");
    printf("\n\n\t\tplayer 1 enter a meaningful word: ");
    fflush(stdin);

    int p=0;
    do{
        mword[p]=getch();
        if(mword[p]!='\r'){
            printf("*");
        }
        p++;
    }while(mword[p-1]!='\r');
    mword[p-1]='\0';


    srand(time(NULL));

    int i=0,j,length,temp;
    length = strlen(mword);
    char tempWord[length];
    strcpy(tempWord,mword);


    i = length;
    while(--i>0)
    {
        j = (rand()%length);
        temp= tempWord[j];
        tempWord[j]= tempWord[i];
        tempWord[i]= temp;
    }
    system("cls");
    printf("\t\t\t\t\tWelcome to multiplayer mode\n ");
    printf("\n\t\t\t---Now guess the word if you can---\n");

    printf("\n\n\t\t     ");

    for(i=0; i<=length; i++)
    {
        printf("%c ", tempWord[i]);
    }

    Sleep(7000);

    fflush(stdin);
    system("cls");
    printf("\t\t\t\t\tWelcome to multiplayer mode\n ");

    printf("\n\n\n\t\tplayer 2  write the word: ");

    fgets(mword2,15,stdin);
    mword2[strlen(mword2)-1] = NULL;
     fflush(stdin);
     system("cls");
     printf("\t\t\t\t\tWelcome to multiplayer mode\n ");
     printf("\n\n\t\t---------------\n");
    if(strcmp(mword,mword2)==NULL)
    {

        printf("\t\t  right guess\n");
    }
    else
    {
        printf("\t\t  wrong guess\n");
    }
     printf("t\t\t---------------\n");

    printf("\t\t\twant to play again?(y/n): ");
    scanf("%c",&check);
    if(check == 'y')
    {
        multiplayerMode();
    }
    else
    {
        Exit();
    }

}

