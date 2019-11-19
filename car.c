#include "car.h"
//==========================================================
// Iniciando a Matriz
void startMtrx(char matrix[ROWS][COLUMNS]){
    int i, j;

    /* Criando a Matrix principal do jogo e atribuindo
       valor nulo a cada espaço da matrix */
    for(i=0;i<ROWS;i++){
        for(j=0;j<COLUMNS;j++){
            matrix[i][j] = ' ';
        }
    }
}
//==========================================================
// Visual e animações
void printMtx(char matrix[ROWS][COLUMNS], int detect){
    int i, j, resto;

    printf("\n\t\t\t");
    for(j=0;j<COLUMNS+4;j++){ /* linha de cima */
        printf("\xB1");
    }
    printf("\n");

    for(i=0;i<ROWS;i++){ /* Linhas da matriz */
        resto = i%2;
        if(detect==1){
            if(resto==0){
                printf("\t\t\t\xB1\xDB");
            } else {
                printf("\t\t\t\xB1 ");
            }
        } else {
            if(resto==0){
                printf("\t\t\t\xB1 ");
            } else {
                printf("\t\t\t\xB1\xDB");
            }
        }

        for(j=0;j<COLUMNS;j++){
            printf("%c", matrix[i][j]);
        }

        if(detect==1){
            if(resto==0){
                printf("\xDB\xB1\n");
            } else {
                printf(" \xB1\n");
            }
        } else {
            if(resto==0){
                printf(" \xB1\n");
            } else {
                printf("\xDB\xB1\n");
            }
        }
    }

    printf("\t\t\t");
    for(j=0;j<COLUMNS+4;j++){ /* linha de baixo */
        printf("\xB1");
    }
    printf("\n");
}
//==========================================================
// Inverção de animação de Parede
int orderWall(int order){
    if(order==1){
        order=0;
    } else {
        order=1;
    }
    return order;
}
//==========================================================
// Posicionando carro player e inimigo
void CarPlayerLeft(car *block){
    block->i = 23;
    block->j = 3;
    block->position = LEFT;
    block->width = 5;
    block->height = 4;
}
void CarEnemyLeft(car *block){
    block->i = 0;
    block->j = 3;
    block->position = LEFT;
    block->width = 5;
    block->height = 4;
}
//------
void CarPlayerRight(car *block){
    block->i = 23;
    block->j = 11;
    block->position = RIGHT;
    block->width = 5;
    block->height = 4;
}
void CarEnemyRight(car *block){
    block->i = 0;
    block->j = 11;
    block->position = RIGHT;
    block->width = 5;
    block->height = 4;
}
//==========================================================
// Construindo carro Player
void CarPlayer(char matrix[ROWS][COLUMNS], car block, char symbol){
    matrix[block.i][block.j+1] = symbol;
    matrix[block.i][block.j+2] = symbol;
    matrix[block.i][block.j-1] = symbol;
    matrix[block.i][block.j-2] = symbol;
    matrix[block.i-1][block.j] = symbol;
    matrix[block.i-2][block.j] = symbol;
    matrix[block.i-2][block.j+1] = symbol;
    matrix[block.i-2][block.j+2] = symbol;
    matrix[block.i-2][block.j-1] = symbol;
    matrix[block.i-2][block.j-2] = symbol;
    matrix[block.i-3][block.j] = symbol;
}
//==========================================================
// Construindo carro Enemy
void CarEnemy(char matrix[ROWS][COLUMNS], car block, char symbol){
    matrix[block.i][block.j+1] = symbol;
    matrix[block.i][block.j+2] = symbol;
    matrix[block.i][block.j-1] = symbol;
    matrix[block.i][block.j-2] = symbol;
    if(block.i-1 >= 0)matrix[block.i-1][block.j] = symbol;
    if(block.i-2 >= 0)matrix[block.i-2][block.j] = symbol;
    if(block.i-2 >= 0)matrix[block.i-2][block.j+1] = symbol;
    if(block.i-2 >= 0)matrix[block.i-2][block.j+2] = symbol;
    if(block.i-2 >= 0)matrix[block.i-2][block.j-1] = symbol;
    if(block.i-2 >= 0)matrix[block.i-2][block.j-2] = symbol;
    if(block.i-3 >= 0)matrix[block.i-3][block.j] = symbol;
}
//==========================================================
// 