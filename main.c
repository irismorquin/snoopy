#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "mesFonctions.h"
#define LONGUEUR 20
#define LARGEUR 10

char matrice[10][20] = {'6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6','6', '6',
                        '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', ' ', '6',
                        '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', '6',
                        '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', '6',
                        '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', '6',
                        '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', '6',
                        '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', '6',
                        '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', '6',
                        '6', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',' ', '6',
                        '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6', '6','6', '6',};
//char blockSymbols[] = {'\0', '♠', '→', '♣', '☼', '◙', '▬', '☺', '♂', '♫'};
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
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void vieSnoopy(int vies) {   // SOUS PROGRAMME VIES DE SNOOPY

    Color(5,0);
    printf ("\n\t *** Vies: %d ***", vies);
}
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
void scoreSnoopy() {                        // SOUS PRO SCORE D UN NIVEAU

    int score,sec;
    score = sec * 100;


    Color(5,0);
    printf("\n\t *** Score : %d points *** \n", score);
}
struct Element* initBlock(int x, int y, char uni, enum BlockType type) {
    struct Element* block = (struct Element*)malloc(sizeof(struct Element));
    if (block == NULL) {
        // Handle memory allocation failure
        exit(EXIT_FAILURE);
    }
    block->x = x;
    block->y = y;
    block->uni = uni;
    block->type = type;

    return block;
}
void updateMatrix(char matrice[10][20], struct Element** allBlocks, int numBlocks) {
    for (int i = 0; i < numBlocks; ++i) {
        if (allBlocks[i]->type != EMPTY)
            matrice[allBlocks[i]->x][allBlocks[i]->y] = allBlocks[i]->uni;
    }
}
int moveSnoop(char matrix[10][20], struct Element **allBlocks, int input) {
    if (input != 75 && input != 77 && input != 72 && input != 80) {
        return -1;
    }

    int oldX = allBlocks[0]->x;
    int oldY = allBlocks[0]->y;

    // Move the block based on input
    switch (input) {
        case 75: // Left
            allBlocks[0]->y--;
            break;
        case 77: // Right
            allBlocks[0]->y++;
            break;
        case 72: // Up
            allBlocks[0]->x--;
            break;
        case 80: // Down
            allBlocks[0]->x++;
            break;
    }

    if ( allBlocks[0]->x <= 0 ||  allBlocks[0]->x >= 9 ||  allBlocks[0]->y <= 0 ||  allBlocks[0]->y >= 19) {
        allBlocks[0]->x = oldX;
        allBlocks[0]->y = oldY;
        return -1;
    }

    for (int i = 1; i < NUM_BLOCKS; i++) {
        if (allBlocks[0]->x == allBlocks[i]->x && allBlocks[0]->y == allBlocks[i]->y) {
            switch (allBlocks[i]->type) {
                case BREAKABLE:
                    allBlocks[i]->type = EMPTY;
                    break;
                case INVINCIBLE:
                    allBlocks[0]->x = oldX;
                    allBlocks[0]->y = oldY;
                    return -1;
                case BIRD:
                    allBlocks[i]->type = EMPTY;
                    break;

            }
        }
    }
    matrix[oldX][oldY] = ' ';
    return 0;
}


void printMatrix(char matrice[10][20]) {
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 20; ++j) {
            printf("%c", matrice[i][j]);
        }
        printf("\n");
    }
}
struct  Element** initBlocks() {
    const int numBlocks = NUM_BLOCKS;

    // Dynamically allocate an array to hold all the blocks
    struct Element** allBlocks = (struct Element**)malloc(numBlocks * sizeof(struct Element));
    if (allBlocks == NULL) {
        // Handle memory allocation failure
        exit(EXIT_FAILURE);
    }

    // Initialize each block and store it in the array
    allBlocks[0] = initBlock(4, 10, 'S', SNOOPY);
    allBlocks[1] = initBlock(3, 9, 'C', BREAKABLE);
    allBlocks[2] = initBlock(3, 11, 'C', BREAKABLE);
    allBlocks[3] = initBlock(5, 9, 'C', BREAKABLE);
    allBlocks[4] = initBlock(5, 11, 'C', BREAKABLE);
    allBlocks[5] = initBlock(1, 1, 'O', BIRD);
    allBlocks[6] = initBlock(1, 18, 'O', BIRD);
    allBlocks[7] = initBlock(8, 1, 'O', BIRD);
    allBlocks[8] = initBlock(8, 18, 'O', BIRD);
    allBlocks[9] = initBlock(4, 8, 'I', INVINCIBLE);
    allBlocks[10] = initBlock(4, 12, 'I', INVINCIBLE);
    allBlocks[11] = initBlock(3, 10, 'I', INVINCIBLE);
    allBlocks[12] = initBlock(5, 10, 'I', INVINCIBLE);
    allBlocks[13] = initBlock(3, 8, 'I', INVINCIBLE);
    allBlocks[14] = initBlock(5, 8, 'I', INVINCIBLE);
    allBlocks[15] = initBlock(3, 12, 'I', INVINCIBLE);
    allBlocks[16] = initBlock(5, 12, 'I', INVINCIBLE);
    allBlocks[17] = initBlock(2, 1, 'B', PUSHABLE);
    return allBlocks;
}

int init() {
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
    return numero;
}
void GAMEOVER(){
    Color(4,0);
    printf("\t \t *** GAME OVER ***\n");
    Color(15,0);
    printf("***  VOUS ALLEZ ETRE REDIRIGER VERS LE MENU  ***");

}

int conditionGagne(int oiseau1, int oiseau2, int oiseau3,int oiseau4,int gameover){
    gameover = 0;
    if (oiseau1 == EMPTY && oiseau2 == EMPTY && oiseau3 == EMPTY && oiseau4 == EMPTY){
        gameover = 1;
        printf("Vous avez gagne !!\n");
    }
    return gameover;
}

void logicSnoopy() {
    int s;
    int vies = 3;
    int score = 0;
    int sec = 120;

    for (int i = 0; i < 3; i++) {
        matriceSnoopy();
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
void *SnoopyTimerThread(void *args) {
    int *seconds = (int *)args;

    while (*seconds > 0) {
        system("cls");
        gotoxy(0, 0);
        printMatrix(matrice);
        printf("Timer: %d seconds\n", *seconds / 10);
        Sleep(100);
        (*seconds) -= 1;
    }
    printf("Timer reached 0. You're very bad at this game.\n");
    pthread_exit(NULL);
}

int main() {
   int numero = init();
    switch(numero)
    {
        case 1:
        {
            printf("* But du jeu: Le but de la revanche\nde Snoopy est de recuperer 4 oiseaux\nsitues aux 4 coins du niveau.\nMais attention, diverses obstacles se\nmettent a travers de son chemin\n");
            while(getchar()!= '\n') {}
            break;
        }
        case 2: {
            pthread_t timerTid;
            int timerValue = 200;

            if (pthread_create(&timerTid, NULL, SnoopyTimerThread, &timerValue) != 0) {
                fprintf(stderr, "Error creating timer thread.\n");
                exit(EXIT_FAILURE);
            }
            struct Element **elements = initBlocks();

            // Blocs Poussables :
            int gameover = 0;

            while (gameover!=1) {

                updateMatrix(matrice, elements, NUM_BLOCKS);
                gameover = conditionGagne(elements[5]->type,elements[6]->type,elements[7]->type,elements[8]->type,gameover);
                if (gameover == 1){
                    break;
                }
                int input = getch();


                if (input == 113){//q
                    exit(1);
                }
                moveSnoop(matrice, elements, input);
            }
            if (pthread_join(timerTid, NULL) != 0) {
                fprintf(stderr, "Error joining timer thread.\n");
                exit(EXIT_FAILURE);
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

