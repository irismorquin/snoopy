#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#define LONGUEUR 20
#define LARGEUR 10

void gotoxy(int x, int y) {
    COORD S;
    S.X = x;
    S.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), S);
}

struct Element {
    int x;
    int y; // coordonnees de Snoopy
};

int bc1 = 'C';
int bc2 = 'C';
int bc3 = 'C';
int bc4 = 'C';
int bi1 = 'I';
int oiseau1 = 'O';
int oiseau2 = 'O';
int oiseau3 = 'O';
int oiseau4 = 'O';
int compteuroiseaux = 0;



void afficherMatrice(struct Element *S, struct Element *C1, struct Element *C2, struct Element *C3, struct Element *C4,
                     struct Element *O1, struct Element *O2, struct Element *O3, struct Element *O4,
                     struct Element *I1, struct Element *I2, struct Element *I3, struct Element *I4,struct Element *I5,struct Element *I6,struct Element *I7,struct Element *I8,struct Element *BPH) {
    system("cls");


    for (int i = 0; i < LARGEUR; i++) {
        for (int j = 0; j < LONGUEUR; j++) {
            if(i==0|| i==9){ // contour pour les lignes 0 et 9
                printf("-");
            }
            else if (j==0 || j==19){ // contour pour les colonnes 0 et 19
                printf("|");
            }
            else if (i==3 && j==9){
                printf("%c",bc1);
            }
            else if (i==3 && j==11 ){
                printf("%c",bc2);
            }
            else if (i==5 && j==9){
                printf("%c",bc3);
            }
            else if (i==5 && j==11){
                printf("%c",bc4);
            }
            else if (i==4 && j==8 || i==4 && j==12 || i==3 && j==10 || i==5 && j==10 || i==3 && j==8 || i==5 && j==8 || i==3 && j==12 || i==5 && j==12) {
                printf("%c",bi1);
            }
            else if (i==1 && j==1){
                printf("%c",oiseau1);
            }
            else if (i==1 && j==18){
                printf("%c",oiseau2);
            }
            else if (i==8 && j==1){
                printf("%c",oiseau3);
            }
            else if (i==8 && j==18){
                printf("%c",oiseau4);
            }
            /*else if (i==7 && j==1){
                printf("%c",bph);
            }*/
            else if (S->x == C1->x && S->y == C1->y) {
                bc1 = ' ';
            }
            else if (S->x == C2->x && S->y == C2->y){
                bc2 = ' ';
            }
            else if (S->x == C3->x && S->y == C3->y){
                bc3 = ' ';
            }
            else if (S->x == C4->x && S->y == C4->y){
                bc4 = ' ';
            }
            else if (S->x == O1->x && S->y == O1->y){


                oiseau1 = ' ';
            }
            else if (S->x == O2->x && S->y == O2->y){


                oiseau2 = ' ';
            }
            else if (S->x == O3->x && S->y == O3->y){


                oiseau3 = ' ';
            }
            else if (S->x == O4->x && S->y == O4->y){


                oiseau4 = ' ';
            }
            else if (S->x == I1->x && S->y == I1->y || S->x == I5->x && S->y == I5->y || S->x == I6->x && S->y == I6->y ){
                S->y++ || S->x++ || S->x-- ;


            }
            else if( S->x == I2->x && S->y == I2->y  || S->x == I7->x && S->y == I7->y || S->x == I8->x && S->y == I8->y){
                S->x-- || S->x++;
            }
            else if(S->x == I3->x && S->y == I3->y || S->x == I4->x && S->y == I4->y){
                S->y-- || S->x++ ;
            }


            else if (S->x == BPH->x && S->y == BPH->y){
                BPH->y++;
            }
            else {
                if(i==S->x && j==S->y){ // emplacement initial de Snoopy
                    printf("S");


                }
                else
                    printf(" ");
            }
        }
        printf("\n");
    }
}


int conditionGagne(int oiseau1, int oiseau2, int oiseau3,int oiseau4,int gameover){
    gameover = 0;
    if (oiseau1 == ' ' && oiseau2 == ' ' && oiseau3 == ' ' && oiseau4 == ' '){
        gameover = 1;
        printf("Vous avez gagne !!\n");
    }
}



void Color(int couleurDuTexte,int couleurDeFond)                        // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}



void timerSnoopy(int s) {                                            //SOUS PROGRAMME DU TIMER

    while (getchar() != '\n') {}

    int sec;


    for (sec = 1200; sec >= 0; sec--)                                 // pour compter en dixième de seconde de 1200 à 0
    {
        float secondes = sec / 10.0;                              // puis convertir ces dixièmes en secondes


        Color(13, 7);
        printf(" \t *** Timer : %.1f s *** \r", secondes);
        usleep(1);     //usleep(100000) 1s     // attendre 100 000 micro secondes (0.1 secondes)




    }
}


void vieSnoopy(int vies) {   // SOUS PROGRAMME VIES DE SNOOPY

    Color(5,0);
    printf ("\n\t *** Vies: %d ***", vies);
}


void scoreSnoopy() {                        // SOUS PRO SCORE D UN NIVEAU

    int score,sec;
    score = sec * 100;


    Color(5,0);
    printf("\n\t *** Score : %d points *** \n", score);
}



void GAMEOVER(){

    Color(4,0);
    printf("\t \t *** GAME OVER ***\n");
    Color(15,0);
    printf("***  VOUS ALLEZ ETRE REDIRIGER VERS LE MENU  ***");

}



/*void deplacerSnoopy(){
    int x=10;
    int y=5;
    char ch;
    gotoxy(x,y);
    printf("S");

    while(1){
        ch = getch();
        if(ch==77 && x<18){
            gotoxy(x,y);
            printf(" ");
            ++x;
            gotoxy(x,y);
            printf("S");
        }
        else if (ch==75 && x>1){
            gotoxy(x,y);
            printf(" ");
            --x;
            gotoxy(x,y);
            printf("S");
        }
        else if (ch==72 && y>2){
            gotoxy(x,y);
            printf(" ");
            --y;
            gotoxy(x,y);
            printf("S");
        }
        else if (ch==80 && y<9){
            gotoxy(x,y);
            printf(" ");
            ++y;
            gotoxy(x,y);
            printf("S");
        }
        else (ch == 'x');
        break;
    }

}*/



void matriceSnoopy () {                                        // SOUS PROGRAMME DE LA MATRICE GENERALE




    int sec;




    char matrice[10][20] = {'6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6','6', '6',
                            '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', '6',
                            '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', '6',
                            '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', '6',
                            '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', '6',
                            '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', '6',
                            '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', '6',
                            '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', '6',
                            '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', '6',
                            '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6','6', '6',};




    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            Color(13,15);
            printf(" %c", matrice[i][j]);
        }
        printf("\n");
    }
}





void logicSnoopy() {


    int s;
    int vies = 3;
    int score = 0;
    int sec = 120;








    for (int i = 0; i < 3; i++) {


        matriceSnoopy();


        //while (getchar() != '\n') {}
        Color(13,1);
        timerSnoopy(120);
        vieSnoopy(3);
        scoreSnoopy();




        if (s == 0) {
            Color(4, 0);
            printf("\n  TIME'S UP! TU AS UNE VIE EN MOINS :( \n");
            vieSnoopy(2 - i);


            Color(15,0);
            printf("  \n Cliquer ENTER \n ");
            while (getchar() != '\n') {}// Attendre jusqu'à ce que l'utilisateur appuie sur Enter
        }
        system("cls");
    }




    GAMEOVER();
    sleep(3);
    system("cls");
}




int main ()
{
    char menu[10][20] = {
            "\t\t\t*MENU*","","1. Regle du jeu","2. Recommencer jeu ","3. Charger partie ","4. Mot de passe","5. Scores","6. Quitter","",
    };

    for (int i = 0; i < 10; i++) {
        printf("%s\n", menu[i]);
    }

    int numero;
    do {
        printf("Saisir 1,2,3,4,5 ou 6:\n");
        scanf("%d", &numero);
        system("cls");
        while (getchar() != '\n') {}
        if(numero!=1 && numero!=2 && numero!=3 && numero!=4 && numero!=5 && numero!=6) {
            printf("\nVotre reponse n'a pas ete comprise,\nveuillez reessayer. \n");
        }
    }while(numero!=1 && numero!=2 && numero!=3 && numero!=4 && numero!=5 && numero!=6);

    switch(numero)
    {
        case 1:
        {
            printf("* But du jeu: Le but de la revanche\nde Snoopy est de recuperer 4 oiseaux\nsitues aux 4 coins du niveau.\nMais attention, diverses obstacles se\nmettent a travers de son chemin\n");
            while(getchar()!= '\n') {}
            break;
        }
        case 2: {
            struct Element S = {4, 10};
             //Blocs cassables :
            struct Element C1 = {3, 9};
            struct Element C2 = {3, 11};
            struct Element C3 = {5, 9};
            struct Element C4 = {5, 11};
            // Oiseaux :
            struct Element O1 = {1, 1};
            struct Element O2 = {1, 18};
            struct Element O3 = {8, 1};
            struct Element O4 = {8, 18};
            // Blocs incassables :
            struct Element I1 = {4, 8};
            struct Element I2 = {4, 12};
            struct Element I3 = {3, 10};
            struct Element I4 = {5, 10};
            struct Element I5 = {3,8};
            struct Element I6 = {5,8};
            struct Element I7 = {3,12};
            struct Element I8 = {5,12};
            // Blocs Poussables :
            struct Element BPH = {2,1};
            int gameover = 0;


            while (gameover!=1) {
                afficherMatrice(&S, &C1, &C2, &C3, &C4, &O1, &O2, &O3, &O4, &I1, &I2, &I3, &I4,&I5,&I6,&I7,&I8,&BPH);
                conditionGagne(oiseau1,oiseau2,oiseau3,oiseau4,gameover);



                switch (getch()) {
                    case 75:  // fleche vers la gauche
                        if (S.y > 1)
                            S.y--;
                        break;
                    case 77:  // fleche vers la droite
                        if (S.y < 18)
                            S.y++;
                        break;
                    case 72:  // fleche vers le haut
                        if (S.x > 1)
                            S.x--;
                        break;
                    case 80:  // fleche vers le bas
                        if (S.x < 8)
                            S.x++;
                        break;
                }






            }

                     while (getchar() != '\n') {}
                     break;
                 }

                 case 3:
                 {
                     logicSnoopy();
                     while(getchar()!= '\n') {}
                     break;
                 }
                 case 4:
                 {
                     printf("* Vous avez choisi mot de passe");
                     while(getchar()!= '\n') {}
                     break;
                 }
                 case 5:
                 {
                     printf("* Vous avez choisi de regarder vos scores");
                     while(getchar()!= '\n') {}
                     break;
                 }
                 case 6:
                 {
                     printf("* Vous avez choisi de quitter le jeu");
                     while(getchar()!= '\n') {}
                     break;
                 }
             }
             return 0;
         }
