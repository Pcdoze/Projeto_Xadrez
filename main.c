#include <stdio.h>
#include <stdlib.h>


int xeque = 0;


char xadrez [8][8];

int criartabuleiro(char tabuleiro[8][8]){
    char modelo[8][8] = {
     { 'T', 'C', 'B', 'Q', 'R', 'B', 'C', 'T'},
     { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
     { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
     { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
     { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},   //tabuleiro
     { 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
     { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
     { 't', 'c', 'b', 'q', 'r', 'b', 'c', 't'}
    };

    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++){
            tabuleiro[x][y] = modelo[x][y];
        } 
    }
}

char p1 [6] = { 'T', 'C', 'B', 'Q', 'R', 'P'};
char p2 [6] = { 't', 'c', 'b', 'q', 'r', 'p'};

int pintartabuleiro() {
    system("cls");

    int linha, coluna, r;
    for (linha=0; linha < 8 ; linha++){
        for (r = 0; r < 3; r++) {
            for(coluna=0; coluna < 8 ; coluna++){
                char peca = xadrez[linha][coluna];

                if(peca == 'x' || peca == 'X' || peca == 'W'){
                    peca = ' ';
                }
                
                char letra = ((linha + coluna) % 2 == 0) ? '\xB2':' ';
                letra = (r == 1 && peca != ' ') ? peca: letra ;

                if( (linha + coluna) % 2 == 0){           //pinta o local preto e branco
                    printf("\xB2\xB2%c\xB2\xB2", letra); //local onde fica a pe�a
                }else{
                    printf("  %c  ", letra);

                }
            }
            printf("\n");
        }
    }
}
      
int pecasatacadas(){
    //limpa todos os x e X do tabuleiro e cria novos
    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++){
            char peca = xadrez[x][y];

            if(peca == 'X' || peca == 'x' || peca == 'W'){
                xadrez[x][y] = ' ';
            }
        }
    }
    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++){
            char peca = xadrez[x][y];

            if(peca == 'P'){
                if(x < 7 && y > 0){
                    if(xadrez[x+1][y-1] == 'x'){
                        xadrez[x+1][y-1] = 'W';
                    }
                    else if(xadrez[x+1][y-1] == 'r'){
                        xeque = 1;
                    }
                    else if(xadrez[x+1][y-1] == ' '){
                        xadrez[x+1][y-1] = 'X';
                    }
                }
                if(x < 7 && y < 7){
                    if(xadrez[x+1][y+1] == 'x'){
                        xadrez[x+1][y+1] = 'W';
                    }
                    else if(xadrez[x+1][y+1] == 'r'){
                        xeque = 1;
                    }
                    else if(xadrez[x+1][y+1] == ' '){
                        xadrez[x+1][y+1] = 'X';
                    }
                }
            }
            else if(peca == 'p'){
                if(x > 0 && y > 0){
                    if(xadrez[x-1][y-1] == 'X'){
                        xadrez[x-1][y-1] = 'W';
                    }
                    else if(xadrez[x-1][y-1] == 'R'){
                        xadrez[x-1][y-1] = 'x';
                    }
                    else if(xadrez[x-1][y-1] == ' '){
                        xadrez[x-1][y-1] = 'x';
                    }
                }
                if(x > 0 && y < 7){
                    if(xadrez[x-1][y+1] == 'X'){
                        xadrez[x-1][y+1] = 'W';
                    }
                    else if(xadrez[x-1][y+1] == 'R'){
                        xeque = 1;
                    }
                    else if(xadrez[x-1][y+1] == ' '){
                        xadrez[x-1][y+1] = 'x';
                    }
                }
            }
            else if(peca == 'C' || peca == 'c'){
                if(x >= 2 && y >= 1){
                    if(xadrez[x-2][y-1] == 'X'){
                        xadrez[x-2][y-1] = peca == 'C' ? 'X':'W';
                    }
                    else if(xadrez[x-2][y-1] == 'x'){
                        xadrez[x-2][y-1] = peca == 'C' ? 'W':'x';
                    }
                    else if(xadrez[x-2][y-1] == ' '){
                        xadrez[x-2][y-1] = peca == 'C' ? 'X':'x';
                    }
                    else if(xadrez[x-2][y-1] == 'R'){
                        xeque = peca == 'C' ? xeque:1;
                    }
                    else if(xadrez[x-2][y-1] == 'r'){
                        xeque = peca == 'C' ? 1:xeque;
                    }
                }
                if(x >= 2 && y < 7){
                    if(xadrez[x-2][y+1] == 'X'){
                        xadrez[x-2][y+1] = peca == 'C' ? 'X':'W';
                    }
                    else if(xadrez[x-2][y+1] == 'x'){
                        xadrez[x-2][y+1] = peca == 'C' ? 'W':'x';
                    }
                    else if(xadrez[x-2][y+1] == ' '){
                        xadrez[x-2][y+1] = peca == 'C' ? 'X':'x';
                    }
                    else if(xadrez[x-2][y+1] == 'R'){
                        xeque = peca == 'C' ? xeque:1;
                    }
                    else if(xadrez[x-2][y+1] == 'r'){
                        xeque = peca == 'C' ? 1:xeque;
                    }
                }
                if(x >= 1 && y < 6){
                    if(xadrez[x-1][y+2] == 'X'){
                        xadrez[x-1][y+2] = peca == 'C' ? 'X':'W';
                    }
                    else if(xadrez[x-1][y+2] == 'x'){
                        xadrez[x-1][y+2] = peca == 'C' ? 'W':'x';
                    }
                    else if(xadrez[x-1][y+2] == ' '){
                        xadrez[x-1][y+2] = peca == 'C' ? 'X':'x';
                    }
                    else if(xadrez[x-1][y+2] == 'R'){
                        xeque = peca == 'C' ? xeque:1;
                    }
                    else if(xadrez[x-1][y+2] == 'r'){
                        xeque = peca == 'C' ? 1:xeque;
                    }
                }
                if(x < 7 && y < 6){
                    if(xadrez[x+1][y+2] == 'X'){
                        xadrez[x+1][y+2] = peca == 'C' ? 'X':'W';
                    }
                    else if(xadrez[x+1][y+2] == 'x'){
                        xadrez[x+1][y+2] = peca == 'C' ? 'W':'x';
                    }
                    else if(xadrez[x+1][y+2] == ' '){
                        xadrez[x+1][y+2] = peca == 'C' ? 'X':'x';
                    }
                    else if(xadrez[x+1][y+2] == ' '){
                        xeque = peca == 'C' ? xeque:1;
                    }
                    else if(xadrez[x+1][y+2] == ' '){
                        xeque = peca == 'C' ? 1:xeque;
                    }
                }
                if(x < 6 && y >= 1){
                    if(xadrez[x+2][y+1] == 'X'){
                        xadrez[x+2][y+1] = peca == 'C' ? 'X':'W';
                    }
                    else if(xadrez[x+2][y+1] == 'x'){
                        xadrez[x+2][y+1] = peca == 'C' ? 'W':'x';
                    }
                    else if(xadrez[x+2][y+1] == ' '){
                        xadrez[x+2][y+1] = peca == 'C' ? 'X':'x';
                    }
                    else if(xadrez[x+2][y+1] == 'R'){
                        xadrez[x+2][y+1] = peca == 'C' ? xeque:1;
                    }
                    else if(xadrez[x+2][y+1] == 'r'){
                        xadrez[x+2][y+1] = peca == 'C' ? 1:xeque;
                    }
                }
                if(x < 6 && y >= 1){
                    if(xadrez[x+2][y-1] == 'X'){
                        xadrez[x+2][y-1] = peca == 'C' ? 'X':'W';
                    }
                    else if(xadrez[x+2][y-1] == 'x'){
                        xadrez[x+2][y-1] = peca == 'C' ? 'W':'x';
                    }
                    else if(xadrez[x+2][y-1] == ' '){
                        xadrez[x+2][y-1] = peca == 'C' ? 'X':'x';
                    }
                    else if(xadrez[x+2][y-1] == 'R'){
                        xeque = peca == 'C' ? xeque:1;
                    }
                    else if(xadrez[x+2][y-1] == 'r'){
                        xeque = peca == 'C' ? 1:xeque;
                    }
                }
                if(x < 7 && y >= 2){
                    if(xadrez[x+1][y-2] == 'X'){
                        xadrez[x+1][y-2] = peca == 'C' ? 'X':'W';
                    }
                    else if(xadrez[x+1][y-2] == 'x'){
                        xadrez[x+1][y-2] = peca == 'C' ? 'W':'x';
                    }
                    else if(xadrez[x+1][y-2] == ' '){
                        xadrez[x+1][y-2] = peca == 'C' ? 'X':'x';
                    }
                    else if(xadrez[x+1][y-2] == 'R'){
                        xeque = peca == 'C' ? xeque:1;
                    }
                    else if(xadrez[x+1][y-2] == 'r'){
                        xeque = peca == 'C' ? 1:xeque;
                    }
                }
                if(x >= 1 && y >= 2){
                    if(xadrez[x-1][y-2] == 'X'){
                        xadrez[x-1][y-2] = peca == 'C' ? 'X':'W';
                    }
                    else if(xadrez[x-1][y-2] == 'x'){
                        xadrez[x-1][y-2] = peca == 'C' ? 'W':'x';
                    }
                    else if(xadrez[x-1][y-2] == ' '){
                        xadrez[x-1][y-2] = peca == 'C' ? 'X':'x';
                    }
                    else if(xadrez[x-1][y-2] == 'R'){
                        xeque = peca == 'C' ? xeque:1;
                    }
                    else if(xadrez[x-1][y-2] == 'r'){
                        xeque = peca == 'C' ? 1:xeque;
                    }
                }
            }
            else if(peca == 'B' || peca == 'b'){
                int barreira[4] = {0, 0, 0, 0};

                for(int i = 1; i <= 8; i++){
                    if(x+i >= 8 || y+i >= 8){
                        barreira[0] = 1;
                    }
                    if(!barreira[0]){
                        if(xadrez[x+i][y+i] == ' '){
                            xadrez[x+i][y+i] = peca=='B' ? 'X':'x';
                        }
                        else if(xadrez[x+i][y+i] == 'X'){
                            xadrez[x+i][y+i] = peca=='B' ? 'X':'W';
                        }
                        else if(xadrez[x+i][y+i] == 'x'){
                            xadrez[x+i][y+i] = peca=='B' ? 'W':'x';
                        }
                        else if(xadrez[x+i][y+i] == 'W'){
                            xadrez[x+i][y+i] = 'W';
                        }
                        else if(xadrez[x+i][y+i] == 'R'){
                            xeque = (peca=='B' ? xeque:1);
                        }
                        else if(xadrez[x+i][y+i] == 'r'){
                            xeque = (peca=='B' ? 1:xeque);
                        }
                        else{
                            barreira[0] = 1;
                        }
                    }


                    if(x-i < 0 || y+i >= 8){
                        barreira[1] = 1;
                    }
                    if(!barreira[1]){
                        if(xadrez[x-i][y+i] == ' '){
                            xadrez[x-i][y+i] = peca=='B' ? 'X':'x';
                        }
                        else if(xadrez[x-i][y+i] == 'X'){
                            xadrez[x-i][y+i] = peca=='B' ? 'X':'W';
                        }
                        else if(xadrez[x-i][y+i] == 'x'){
                            xadrez[x-i][y+i] = peca=='B' ? 'W':'x';
                        }
                        else if(xadrez[x-i][y+i] == 'W'){
                            xadrez[x-i][y+i] = 'W';
                        }
                        else if(xadrez[x-i][y+i] == 'R'){
                            xeque = peca=='B' ? xeque:1;
                        }
                        else if(xadrez[x-i][y+i] == 'r'){
                            xeque = peca=='B' ? 1:xeque;
                        }
                        else{
                            barreira[1] = 1;
                        }
                    }


                    if(x-i < 0 || y+i < 0){
                        barreira[2] = 1;
                    }
                    if(!barreira[2]){
                        if(xadrez[x-i][y-i] == ' '){
                            xadrez[x-i][y-i] = peca=='B' ? 'X':'x';
                        }
                        else if(xadrez[x-i][y-i] == 'X'){
                            xadrez[x-i][y-i] = peca=='B' ? 'X':'W';
                        }
                        else if(xadrez[x-i][y-i] == 'x'){
                            xadrez[x-i][y-i] = peca=='B' ? 'W':'x';
                        }
                        else if(xadrez[x-i][y-i] == 'W'){
                            xadrez[x-i][y-i] = 'W';
                        }
                        else if(xadrez[x-i][y-i] == 'R'){
                            xeque = peca=='B' ? xeque:1;
                        }
                        else if(xadrez[x-i][y-i] == 'r'){
                            xeque = peca=='B' ? 1:xeque;
                        }
                        else{
                            barreira[2] = 1;
                        }
                    }

                    
                    if(x+i >= 8 || y+i < 0){
                        barreira[3] = 1;
                    }
                    if(!barreira[3]){
                        if(xadrez[x+i][y-i] == ' '){
                            xadrez[x+i][y-i] = peca=='B' ? 'X':'x';
                        }
                        else if(xadrez[x+i][y-i] == 'X'){
                            xadrez[x+i][y-i] = peca=='B' ? 'X':'W';
                        }
                        else if(xadrez[x+i][y-i] == 'x'){
                            xadrez[x+i][y-i] = peca=='B' ? 'W':'x';
                        }
                        else if(xadrez[x+i][y-i] == 'W'){
                            xadrez[x+i][y-i] = 'W';
                        }
                        else if(xadrez[x+i][y-i] == 'R'){
                            xeque = peca=='B' ? xeque:1;
                        }
                        else if(xadrez[x+i][y-i] == 'r'){
                            xeque = peca=='B' ? 1:xeque;
                        }
                        else{
                            barreira[3] = 1;
                        }
                    }
                }
            }
            else if(peca == 'T' || peca == 't'){

                int barreira[4] = {0, 0, 0, 0};

                for(int i = 1; i <= 8; i++){
                    if(x+i >= 8){
                        barreira[0] = 1;
                    }
                    if(!barreira[0]){
                        if(xadrez[x+i][y] == ' '){
                            xadrez[x+i][y] = peca=='T' ? 'X':'x';
                        }
                        else if(xadrez[x+i][y] == 'X'){
                            xadrez[x+i][y] = peca=='T' ? 'X':'W';
                        }
                        else if(xadrez[x+i][y] == 'x'){
                            xadrez[x+i][y] = peca=='T' ? 'W':'X';
                        }
                        else if(xadrez[x+i][y] == 'W'){
                            xadrez[x+i][y] = 'W';
                        }
                        else if(xadrez[x+i][y] == 'R'){
                            xeque = peca=='T' ? xeque:1;
                        }
                        else if(xadrez[x+i][y] == 'r'){
                            xeque = peca=='T' ? 1:xeque;
                        }
                        else{
                            barreira[0] = 1;
                        }
                    }


                    if(y+i >= 8){
                        barreira[1] = 1;
                    }
                    if(!barreira[1]){
                        if(xadrez[x][y+i] == ' '){
                            xadrez[x][y+i] = peca=='T' ? 'X':'x';
                        }
                        else if(xadrez[x][y+i] == 'X'){
                            xadrez[x][y+i] = peca=='T' ? 'X':'W';
                        }
                        else if(xadrez[x][y+i] == 'x'){
                            xadrez[x][y+i] = peca=='T' ? 'W':'X';
                        }
                        else if(xadrez[x][y+i] == 'W'){
                            xadrez[x][y+i] = 'W';
                        }
                        else if(xadrez[x][y+i] == 'R'){
                            xeque = peca=='T' ? xeque:1;
                        }
                        else if(xadrez[x][y+i] == 'r'){
                            xeque = peca=='T' ? 1:xeque;
                        }
                        else{
                            barreira[1] = 1;
                        }
                    }


                    if(x-i < 0){
                        barreira[2] = 1;
                    }
                    if(!barreira[2]){
                        if(xadrez[x-i][y] == ' '){
                            xadrez[x-i][y] = peca=='T' ? 'X':'x';
                        }
                        else if(xadrez[x-i][y] == 'X'){
                            xadrez[x-i][y] = peca=='T' ? 'X':'W';
                        }
                        else if(xadrez[x-i][y] == 'x'){
                            xadrez[x-i][y] = peca=='T' ? 'W':'X';
                        }
                        else if(xadrez[x-i][y] == 'W'){
                            xadrez[x-i][y] = 'W';
                        }
                        else if(xadrez[x-i][y] == 'R'){
                            xeque = peca=='T' ? xeque:1;
                        }
                        else if(xadrez[x-i][y] == 'r'){
                            xeque = peca=='T' ? 1:xeque;
                        }
                        else{
                            barreira[2] = 1;
                        }
                    }


                    if(y+i < 0){
                        barreira[3] = 1;
                    }
                    if(!barreira[3]){
                        if(xadrez[x][y-i] == ' '){
                            xadrez[x][y-i] = peca=='T' ? 'X':'x';
                        }
                        else if(xadrez[x][y-i] == 'X'){
                            xadrez[x][y-i] = peca=='T' ? 'X':'W';
                        }
                        else if(xadrez[x][y-i] == 'x'){
                            xadrez[x][y-i] = peca=='T' ? 'W':'X';
                        }
                        else if(xadrez[x][y-i] == 'W'){
                            xadrez[x][y-i] = 'W';
                        }
                        else if(xadrez[x][y-i] == 'R'){
                            xeque = peca=='T' ? xeque:1;
                        }
                        else if(xadrez[x][y-i] == 'r'){
                            xeque = peca=='T' ? 1:xeque;
                        }
                        else{
                            barreira[3] = 1;
                        }
                    }
                }
            }
            else if(peca == 'Q' || peca == 'q'){

                int barreira[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}};

                for(int i = 1; i <= 8; i++){
                    if(x+i >= 8 || y+i >= 8){
                        barreira[0][0] = 1;
                    }
                    if(!barreira[0][0]){
                        if(xadrez[x+i][y+i] == ' '){
                            xadrez[x+i][y+i] = peca=='Q' ? 'X':'x';
                        }
                        else if(xadrez[x+i][y+i] == 'X'){
                            xadrez[x+i][y+i] = peca=='Q' ? 'X':'W';
                        }
                        else if(xadrez[x+i][y+i] == 'x'){
                            xadrez[x+i][y+i] = peca=='Q' ? 'W':'X';
                        }
                        else if(xadrez[x+i][y+i] == 'W'){
                            xadrez[x+i][y+i] = 'W';
                        }
                        else if(xadrez[x+i][y+i] == 'R'){
                            xeque = peca=='Q' ? xeque:1;
                        }
                        else if(xadrez[x+i][y+i] == 'r'){
                            xeque = peca=='Q' ? 1:xeque;
                        }
                        else{
                            barreira[0][0] = 1;
                        }
                    }


                    if(x-i < 0 || y+i >= 8){
                        barreira[0][1] = 1;
                    }
                    if(!barreira[0][1]){
                        if(xadrez[x-i][y+i] == ' '){
                            xadrez[x-i][y+i] = peca=='Q' ? 'X':'x';
                        }
                        else if(xadrez[x-i][y+i] == 'X'){
                            xadrez[x-i][y+i] = peca=='Q' ? 'X':'W';
                        }
                        else if(xadrez[x-i][y+i] == 'x'){
                            xadrez[x-i][y+i] = peca=='Q' ? 'W':'X';
                        }
                        else if(xadrez[x-i][y+i] == 'W'){
                            xadrez[x-i][y+i] = 'W';
                        }
                        else if(xadrez[x-i][y+i] == 'R'){
                            xeque = peca=='Q' ? xeque:1;
                        }
                        else if(xadrez[x-i][y+i] == 'r'){
                            xeque = peca=='Q' ? 1:xeque;
                        }
                        else{
                            barreira[0][1] = 1;
                        }
                    }


                    if(x-i < 0 || y+i < 0){
                        barreira[0][2] = 1;
                    }
                    if(!barreira[0][2]){
                        if(xadrez[x-i][y-i] == ' '){
                            xadrez[x-i][y-i] = peca=='Q' ? 'X':'x';
                        }
                        else if(xadrez[x-i][y-i] == 'X'){
                            xadrez[x-i][y-i] = peca=='Q' ? 'X':'W';
                        }
                        else if(xadrez[x-i][y-i] == 'x'){
                            xadrez[x-i][y-i] = peca=='Q' ? 'W':'X';
                        }
                        else if(xadrez[x-i][y-i] == 'W'){
                            xadrez[x-i][y-i] = 'W';
                        }
                        else if(xadrez[x-i][y-i] == 'R'){
                            xeque = peca=='Q' ? xeque:1;
                        }
                        else if(xadrez[x-i][y-i] == 'r'){
                            xeque = peca=='Q' ? 1:xeque;
                        }
                        else{
                            barreira[0][2] = 1;
                        }
                    }


                    if(x+i >= 8 || y+i < 0){
                        barreira[0][3] = 1;
                    }
                    if(!barreira[0][3]){
                        if(xadrez[x+i][y-i] == ' '){
                            xadrez[x+i][y-i] = peca=='Q' ? 'X':'x';
                        }
                        else if(xadrez[x+i][y-i] == 'X'){
                            xadrez[x+i][y-i] = peca=='Q' ? 'X':'W';
                        }
                        else if(xadrez[x+i][y-i] == 'x'){
                            xadrez[x+i][y-i] = peca=='Q' ? 'W':'X';
                        }
                        else if(xadrez[x+i][y-i] == 'W'){
                            xadrez[x+i][y-i] = 'W';
                        }
                        else if(xadrez[x+i][y-i] == 'R'){
                            xeque = peca=='Q' ? xeque:1;
                        }
                        else if(xadrez[x+i][y-i] == 'r'){
                            xeque = peca=='Q' ? 1:xeque;
                        }
                        else{
                            barreira[0][3] = 1;
                        }
                    }
                }


                for(int i = 1; i <= 8; i++){
                    if(x+i >= 8){
                        barreira[1][0] = 1;
                    }
                    if(!barreira[1][0]){
                        if(xadrez[x+i][y] == ' '){
                            xadrez[x+i][y] = peca=='Q' ? 'X':'x';
                        }
                        else if(xadrez[x+i][y] == 'X'){
                            xadrez[x+i][y] = peca=='Q' ? 'X':'W';
                        }
                        else if(xadrez[x+i][y] == 'x'){
                            xadrez[x+i][y] = peca=='Q' ? 'W':'X';
                        }
                        else if(xadrez[x+i][y] == 'W'){
                            xadrez[x+i][y] = 'W';
                        }
                        else if(xadrez[x+i][y] == 'R'){
                            xeque = peca=='Q' ? xeque:1;
                        }
                        else if(xadrez[x+i][y] == 'r'){
                            xeque = peca=='Q' ? 1:xeque;
                        }
                        else{
                            barreira[1][0] = 1;
                        }
                    }


                    if(y+i >= 8){
                        barreira[1][1] = 1;
                    }
                    if(!barreira[1][1]){
                        if(xadrez[x][y+i] == ' '){
                            xadrez[x][y+i] = peca=='Q' ? 'X':'x';
                        }
                        else if(xadrez[x][y+i] == 'X'){
                            xadrez[x][y+i] = peca=='Q' ? 'X':'W';
                        }
                        else if(xadrez[x][y+i] == 'x'){
                            xadrez[x][y+i] = peca=='Q' ? 'W':'X';
                        }
                        else if(xadrez[x][y+i] == 'W'){
                            xadrez[x][y+i] = 'W';
                        }
                        else if(xadrez[x][y+i] == 'R'){
                            xeque = peca=='Q' ? xeque:1;
                        }
                        else if(xadrez[x][y+i] == 'r'){
                            xeque = peca=='Q' ? 1:xeque;
                        }
                        else{
                            barreira[1][1] = 1;
                        }
                    }


                    if(x-i < 0){
                        barreira[1][2] = 1;
                    }
                    if(!barreira[1][2]){
                        if(xadrez[x-i][y] == ' '){
                            xadrez[x-i][y] = peca=='Q' ? 'X':'x';
                        }
                        else if(xadrez[x-i][y] == 'X'){
                            xadrez[x-i][y] = peca=='Q' ? 'X':'W';
                        }
                        else if(xadrez[x-i][y] == 'x'){
                            xadrez[x-i][y] = peca=='Q' ? 'W':'X';
                        }
                        else if(xadrez[x-i][y] == 'W'){
                            xadrez[x-i][y] = 'W';
                        }
                        else if(xadrez[x-i][y] == 'R'){
                            xeque = peca=='Q' ? xeque:1;
                        }
                        else if(xadrez[x-i][y] == 'r'){
                            xeque = peca=='Q' ? 1:xeque;
                        }
                        else{
                            barreira[1][2] = 1;
                        }
                    }


                    if(y+i < 0){
                        barreira[1][3] = 1;
                    }
                    if(!barreira[1][3]){
                        if(xadrez[x][y-i] == ' '){
                            xadrez[x][y-i] = peca=='Q' ? 'X':'x';
                        }
                        else if(xadrez[x][y-i] == 'X'){
                            xadrez[x][y-i] = peca=='Q' ? 'X':'W';
                        }
                        else if(xadrez[x][y-i] == 'x'){
                            xadrez[x][y-i] = peca=='Q' ? 'W':'X';
                        }
                        else if(xadrez[x][y-i] == 'W'){
                            xadrez[x][y-i] = 'W';
                        }
                        else if(xadrez[x][y-i] == 'R'){
                            xeque = peca=='Q' ? xeque:1;
                        }
                        else if(xadrez[x][y-i] == 'r'){
                            xeque = peca=='Q' ? 1:xeque;
                        }
                        else{
                            barreira[1][3] = 1;
                        }
                    }
                }
            }
            else if(peca == 'R' || peca == 'r'){
                if(xadrez[x-1][y-1] == ' '){
                    xadrez[x-1][y-1] = peca=='R' ? 'X':'x';
                }
                else if(xadrez[x-1][y-1] == 'X'){
                    xadrez[x-1][y-1] = peca=='R' ? 'X':'W';
                }
                else if(xadrez[x-1][y-1] == 'x'){
                    xadrez[x-1][y-1] = peca=='R' ? 'W':'x';
                }

                if(xadrez[x-1][y] == ' '){
                    xadrez[x-1][y] = peca=='R' ? 'X':'x';
                }
                else if(xadrez[x-1][y] == 'X'){
                    xadrez[x-1][y] = peca=='R' ? 'X':'W';
                }
                else if(xadrez[x-1][y] == 'x'){
                    xadrez[x-1][y] = peca=='R' ? 'W':'x';
                }

                if(xadrez[x-1][y+1] == ' '){
                    xadrez[x-1][y+1] = peca=='R' ? 'X':'x';
                }
                else if(xadrez[x-1][y+1] == 'X'){
                    xadrez[x-1][y+1] = peca=='R' ? 'X':'W';
                }
                else if(xadrez[x-1][y+1] == 'x'){
                    xadrez[x-1][y+1] = peca=='R' ? 'W':'x';
                }

                if(xadrez[x][y+1] == ' '){
                    xadrez[x][y+1] = peca=='R' ? 'X':'x';
                }
                else if(xadrez[x][y+1] == 'X'){
                    xadrez[x][y+1] = peca=='R' ? 'X':'W';
                }
                else if(xadrez[x][y+1] == 'x'){
                    xadrez[x][y+1] = peca=='R' ? 'W':'x';
                }

                if(xadrez[x+1][y+1] == ' '){
                    xadrez[x+1][y+1] = peca=='R' ? 'X':'x';
                }
                else if(xadrez[x+1][y+1] == 'X'){
                    xadrez[x+1][y+1] = peca=='R' ? 'X':'W';
                }
                else if(xadrez[x+1][y+1] == 'x'){
                    xadrez[x+1][y+1] = peca=='R' ? 'W':'x';
                }

                if(xadrez[x+1][y] == ' '){
                    xadrez[x+1][y] = peca=='R' ? 'X':'x';
                }
                else if(xadrez[x+1][y] == 'X'){
                    xadrez[x+1][y] = peca=='R' ? 'X':'W';
                }
                else if(xadrez[x+1][y] == 'x'){
                    xadrez[x+1][y] = peca=='R' ? 'W':'x';
                }

                if(xadrez[x+1][y-1] == ' '){
                    xadrez[x+1][y-1] = peca=='R' ? 'X':'x';
                }
                else if(xadrez[x+1][y-1] == 'X'){
                    xadrez[x+1][y-1] = peca=='R' ? 'X':'W';
                }
                else if(xadrez[x+1][y-1] == 'x'){
                    xadrez[x+1][y-1] = peca=='R' ? 'W':'x';
                }

                if(xadrez[x][y-1] == ' '){
                    xadrez[x][y-1] = peca=='R' ? 'X':'x';
                }
                else if(xadrez[x][y-1] == 'X'){
                    xadrez[x][y-1] = peca=='R' ? 'X':'W';
                }
                else if(xadrez[x][y-1] == 'x'){
                    xadrez[x][y-1] = peca=='R' ? 'W':'x';
                }
            }
        }
    }
}


int peao(char peca, int linhaorigem, int colunaorigem, int linhadestino, int colunadestino){
    int x = linhaorigem;
    int y = colunaorigem;
    int deslvertical = abs(linhadestino - linhaorigem);
    int deslhorizontal = abs(colunadestino - colunaorigem);
    char tempxadrez[8][8];

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tempxadrez[i][j] = xadrez[i][j];
            char temppeca = tempxadrez[i][j];

            if(temppeca == 'X' || temppeca == 'x' || temppeca == 'W'){
                tempxadrez[i][j] = ' ';
            }
        }
    }

    if(peca == 'P'){
        for(int i = 0; i < 6; i++){
            if(x < 7 && y > 0){
                if(tempxadrez[x+1][y-1] == p2[i]){
                        tempxadrez[x+1][y-1] = 'X';
                }
            }
            if(x < 7 && y < 7){
                if(tempxadrez[x+1][y+1] == p2[i]){
                    tempxadrez[x+1][y+1] = 'X';
                }
            }
        }

        if(linhadestino-linhaorigem == 1 && deslhorizontal == 1){
            if(tempxadrez[linhadestino][colunadestino] == 'X'){
                return 1;
            }
        }
        else if(linhadestino-linhaorigem == 1 && deslhorizontal == 0){
            if(tempxadrez[linhadestino][colunadestino] == ' '){
                return 1;
            }
        }
    }
    else if(peca == 'p'){
        for(int i = 0; i < 6; i++){
            if(x > 0 && y > 0){
                if(tempxadrez[x+1][y-1] == p1[i]){
                    tempxadrez[x+1][y-1] = 'x';
                }
            }
            if(x > 0 && y < 7){
                if(tempxadrez[x-1][y+1] == p1[i]){
                    tempxadrez[x-1][y+1] = 'x';
                }
            }
        }

        if(linhadestino-linhaorigem == -1 && deslhorizontal == 1){
            if(tempxadrez[linhadestino][colunadestino] == 'x'){
                return 1;
            }
        }
        else if(linhadestino-linhaorigem == -1 && deslhorizontal == 0){
            if(tempxadrez[linhadestino][colunadestino] == ' '){
                return 1;
            }
        }
    }
    return 0;
}
int cavalo(char peca, int linhaorigem, int colunaorigem, int linhadestino, int colunadestino){
    int x = linhaorigem;
    int y = colunaorigem;
    char tempxadrez[8][8];

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tempxadrez[i][j] = xadrez[i][j];
            char temppeca = tempxadrez[i][j];


            for(int i = 0; i < 6; i++){
                if(peca == 'C'){
                    if(temppeca == p2[i]){
                        tempxadrez[i][j] = ' ';
                    }
                }
                else if(peca == 'c'){
                    if(temppeca == p1[i]){
                        tempxadrez[i][j] = ' ';
                    }
                }
            }
            if(temppeca == 'X' || temppeca == 'x' || temppeca == 'W'){
                tempxadrez[i][j] = ' ';
            }
        }
    }

    if(x >= 2 && y >= 1){
        if(tempxadrez[x-2][y-1] == 'X'){
            tempxadrez[x-2][y-1] = peca == 'C' ? 'X':'W';
        }
        else if(tempxadrez[x-2][y-1] == 'x'){
            tempxadrez[x-2][y-1] = peca == 'C' ? 'W':'x';
        }
        else if(tempxadrez[x-2][y-1] == ' '){
            tempxadrez[x-2][y-1] = peca == 'C' ? 'X':'x';
        }
    }
    if(x >= 2 && y < 7){
        if(tempxadrez[x-2][y+1] == 'X'){
            tempxadrez[x-2][y+1] = peca == 'C' ? 'X':'W';
        }
        else if(tempxadrez[x-2][y+1] == 'x'){
            tempxadrez[x-2][y+1] = peca == 'C' ? 'W':'x';
        }
        else if(tempxadrez[x-2][y+1] == ' '){
            tempxadrez[x-2][y+1] = peca == 'C' ? 'X':'x';
        }
    }
    if(x >= 1 && y < 6){
        if(tempxadrez[x-1][y+2] == 'X'){
            tempxadrez[x-1][y+2] = peca == 'C' ? 'X':'W';
        }
        else if(tempxadrez[x-1][y+2] == 'x'){
            tempxadrez[x-1][y+2] = peca == 'C' ? 'W':'x';
        }
        else if(tempxadrez[x-1][y+2] == ' '){
            tempxadrez[x-1][y+2] = peca == 'C' ? 'X':'x';
        }
    }
    if(x < 7 && y < 6){
        if(tempxadrez[x+1][y+2] == 'X'){
            tempxadrez[x+1][y+2] = peca == 'C' ? 'X':'W';
        }
        else if(tempxadrez[x+1][y+2] == 'x'){
            tempxadrez[x+1][y+2] = peca == 'C' ? 'W':'x';
        }
        else if(tempxadrez[x+1][y+2] == ' '){
            tempxadrez[x+1][y+2] = peca == 'C' ? 'X':'x';
        }
    }
    if(x < 6 && y >= 1){
        if(tempxadrez[x+2][y+1] == 'X'){
            tempxadrez[x+2][y+1] = peca == 'C' ? 'X':'W';
        }
        else if(tempxadrez[x+2][y+1] == 'x'){
            tempxadrez[x+2][y+1] = peca == 'C' ? 'W':'x';
        }
        else if(tempxadrez[x+2][y+1] == ' '){
            tempxadrez[x+2][y+1] = peca == 'C' ? 'X':'x';
        }
    }
    if(x < 6 && y >= 1){
        if(tempxadrez[x+2][y-1] == 'X'){
            tempxadrez[x+2][y-1] = peca == 'C' ? 'X':'W';
        }
        else if(tempxadrez[x+2][y-1] == 'x'){
            tempxadrez[x+2][y-1] = peca == 'C' ? 'W':'x';
        }
        else if(tempxadrez[x+2][y-1] == ' '){
            tempxadrez[x+2][y-1] = peca == 'C' ? 'X':'x';
        }
    }
    if(x < 7 && y >= 2){
        if(tempxadrez[x+1][y-2] == 'X'){
            tempxadrez[x+1][y-2] = peca == 'C' ? 'X':'W';
        }
        else if(tempxadrez[x+1][y-2] == 'x'){
            tempxadrez[x+1][y-2] = peca == 'C' ? 'W':'x';
        }
        else if(tempxadrez[x+1][y-2] == ' '){
            tempxadrez[x+1][y-2] = peca == 'C' ? 'X':'x';
        }
    }
    if(x >= 1 && y >= 2){
        if(tempxadrez[x-1][y-2] == 'X'){
            tempxadrez[x-1][y-2] = peca == 'C' ? 'X':'W';
        }
        else if(tempxadrez[x-1][y-2] == 'x'){
            tempxadrez[x-1][y-2] = peca == 'C' ? 'W':'x';
        }
        else if(tempxadrez[x-1][y-2] == ' '){
            tempxadrez[x-1][y-2] = peca == 'C' ? 'X':'x';
        }
    }

    tempxadrez[linhadestino, colunadestino];
    if(peca == 'C'){
        if(tempxadrez[linhadestino][colunadestino] == 'X'){
            return 1;
        }
    }
    else if(peca == 'c'){
        if(tempxadrez[linhadestino][colunadestino] == 'x'){
            return 1;
        }
    }
    return 0;
}
int bispo(char peca, int linhaorigem, int colunaorigem, int linhadestino, int colunadestino){
    int x = linhaorigem;
    int y = colunaorigem;
    int barreira[4] = {0, 0, 0, 0};
    char tempxadrez[8][8];

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tempxadrez[i][j] = xadrez[i][j];
            char temppeca = tempxadrez[i][j];


            for(int i = 0; i < 6; i++){
                if(peca == 'B'){
                    if(temppeca == p2[i]){
                        tempxadrez[i][j] = 'A';
                    }
                }
                else if(peca == 'b'){
                    if(temppeca == p1[i]){
                        tempxadrez[i][j] = 'a';
                    }
                }
            }
            if(temppeca == 'X' || temppeca == 'x' || temppeca == 'W'){
                tempxadrez[i][j] = ' ';
            }
        }
    }

    for(int i = 1; i <= 8; i++){
        if(x+i >= 8 || y+i >= 8){
            barreira[0] = 1;
        }
        if(!barreira[0]){
            if(tempxadrez[x+i][y+i] == ' '){
                tempxadrez[x+i][y+i] = peca=='B' ? 'X':'x';
            }
            else if(tempxadrez[x+i][y+i] == 'A'){
                tempxadrez[x+i][y+i] = peca=='B' ? 'X':'A';
                barreira[0] = 1;
            }
            else if(tempxadrez[x+i][y+i] == 'a'){
                tempxadrez[x+i][y+i] = peca=='B' ? 'a':'x';
                barreira[0] = 1;
            }
            else{
                barreira[0] = 1;
            }
        }


        if(x-i < 0 || y+i >= 8){
            barreira[1] = 1;
        }
        if(!barreira[1]){
            if(tempxadrez[x-i][y+i] == ' '){
                tempxadrez[x-i][y+i] = peca=='B' ? 'X':'x';
            }
            else if(tempxadrez[x-i][y+i] == 'A'){
                tempxadrez[x-i][y+i] = peca=='B' ? 'X':'A';
                barreira[1] = 1;
            }
            else if(tempxadrez[x-i][y+i] == 'a'){
                tempxadrez[x-i][y+i] = peca=='B' ? 'a':'x';
                barreira[1] = 1;
            }
            else{
                barreira[1] = 1;
            }
        }


        if(x-i < 0 || y-i < 0){
            barreira[2] = 1;
        }
        if(!barreira[2]){
            if(tempxadrez[x-i][y-i] == ' '){
                tempxadrez[x-i][y-i] = peca=='B' ? 'X':'x';
            }
            else if(tempxadrez[x-i][y-i] == 'A'){
                tempxadrez[x-i][y-i] = peca=='B' ? 'X':'A';
                barreira[2] = 1;
            }
            else if(tempxadrez[x-i][y-i] == 'a'){
                tempxadrez[x-i][y-i] = peca=='B' ? 'a':'x';
                barreira[2] = 1;
            }
            else{
                barreira[2] = 1;
            }
        }

        
        if(x+i >= 8 || y-i < 0){
            barreira[3] = 1;
        }
        if(!barreira[3]){
            if(tempxadrez[x+i][y-i] == ' '){
                tempxadrez[x+i][y-i] = peca=='B' ? 'X':'x';
            }
            else if(tempxadrez[x+i][y-i] == 'A'){
                tempxadrez[x+i][y-i] = peca=='B' ? 'X':'A';
                barreira[3] = 1;
            }
            else if(tempxadrez[x+i][y-i] == 'a'){
                tempxadrez[x+i][y-i] = peca=='B' ? 'a':'x';
                barreira[3] = 1;
            }
            else{
                barreira[3] = 1;
            }
        }
    }

    if(peca == 'B'){
        if(tempxadrez[linhadestino][colunadestino] == 'X'){
            return 1;
        }
    }
    else if(peca == 'b'){
        if(tempxadrez[linhadestino][colunadestino] == 'x'){
            return 1;
        }
    }
    return 0;
}
int torre(char peca, int linhaorigem, int colunaorigem, int linhadestino, int colunadestino){
    int x = linhaorigem;
    int y = colunaorigem;
    int barreira[4] = {0, 0, 0, 0};
    char tempxadrez[8][8];

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tempxadrez[i][j] = xadrez[i][j];
            char temppeca = tempxadrez[i][j];

            for(int i = 0; i < 6; i++){
                if(peca == 'T'){
                    if(temppeca == p2[i]){
                        tempxadrez[i][j] = 'A';
                    }
                }
                else if(peca == 't'){
                    if(temppeca == p1[i]){
                        tempxadrez[i][j] = 'a';
                    }
                }
            }
            if(temppeca == 'X' || temppeca == 'x' || temppeca == 'W'){
                tempxadrez[i][j] = ' ';
            }
        }
    }

    if(peca == 'T' || peca == 't'){

        for(int i = 1; i <= 8; i++){
            if(x+i >= 8){
                barreira[0] = 1;
            }
            if(!barreira[0]){
                if(tempxadrez[x+i][y] == ' '){
                    tempxadrez[x+i][y] = peca=='T' ? 'X':'x';
                }
                else if(tempxadrez[x+i][y] == 'A'){
                    tempxadrez[x+i][y] = peca=='T' ? 'X':'A';
                }
                else if(tempxadrez[x+i][y] == 'a'){
                    tempxadrez[x+i][y] = peca=='T' ? 'a':'x';
                }
                else{
                    barreira[0] = 1;
                }
            }


            if(y+i >= 8){
                barreira[1] = 1;
            }
            if(!barreira[1]){
                if(tempxadrez[x][y+i] == ' '){
                    tempxadrez[x][y+i] = peca=='T' ? 'X':'x';
                }
                else if(tempxadrez[x][y+i] == 'A'){
                    tempxadrez[x][y+i] = peca=='T' ? 'X':'A';
                }
                else if(tempxadrez[x][y+i] == 'a'){
                    tempxadrez[x][y+i] = peca=='T' ? 'a':'x';
                }
                else{
                    barreira[1] = 1;
                }
            }


            if(x-i < 0){
                barreira[2] = 1;
            }
            if(!barreira[2]){
                if(tempxadrez[x-i][y] == ' '){
                    tempxadrez[x-i][y] = peca=='T' ? 'X':'x';
                }
                else if(tempxadrez[x-i][y] == 'A'){
                    tempxadrez[x-i][y] = peca=='T' ? 'X':'A';
                }
                else if(tempxadrez[x-i][y] == 'a'){
                    tempxadrez[x-i][y] = peca=='T' ? 'a':'x';
                }
                else{
                    barreira[2] = 1;
                }
            }


            if(y+i < 0){
                barreira[3] = 1;
            }
            if(!barreira[3]){
                if(tempxadrez[x][y-i] == ' '){
                    tempxadrez[x][y-i] = peca=='T' ? 'X':'x';
                }
                else if(tempxadrez[x][y-i] == 'A'){
                    tempxadrez[x][y-i] = peca=='T' ? 'X':'A';
                }
                else if(tempxadrez[x][y-i] == 'a'){
                    tempxadrez[x][y-i] = peca=='T' ? 'a':'x';
                }
                else{
                    barreira[3] = 1;
                }
            }
        }

        if(peca == 'T'){
            if(tempxadrez[linhadestino][colunadestino] == 'X'){
                return 1;
            }
        }
        else if(peca == 't'){
            if(tempxadrez[linhadestino][colunadestino] == 'x'){
                return 1;
            }
        }
    }
    return 0;
}
int rainha(char peca, int linhaorigem, int colunaorigem, int linhadestino, int colunadestino){
    int x = linhaorigem;
    int y = colunaorigem;
    int barreira[4] = {0, 0, 0, 0};
    char tempxadrez[8][8];

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tempxadrez[i][j] = xadrez[i][j];
            char temppeca = tempxadrez[i][j];

            for(int i = 0; i < 6; i++){
                if(peca == 'Q'){
                    if(temppeca == p2[i]){
                        tempxadrez[i][j] = 'A';
                    }
                }
                else if(peca == 'q'){
                    if(temppeca == p1[i]){
                        tempxadrez[i][j] = 'a';
                    }
                }
            }
            if(temppeca == 'X' || temppeca == 'x' || temppeca == 'W'){
                tempxadrez[i][j] = ' ';
            }
        }
    }
//_____________________________________________

    if(peca == 'Q' || peca == 'q'){
        int barreira[2][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}};

        for(int i = 1; i <= 8; i++){
            if(x+i >= 8 || y+i >= 8){
                barreira[0][0] = 1;
            }
            if(!barreira[0][0]){
                if(tempxadrez[x+i][y+i] == ' '){
                    tempxadrez[x+i][y+i] = peca=='Q' ? 'X':'x';
                }
                else if(tempxadrez[x+i][y+i] == 'A'){
                    tempxadrez[x+i][y+i] = peca=='Q' ? 'X':'A';
                }
                else if(tempxadrez[x+i][y+i] == 'a'){
                    tempxadrez[x+i][y+i] = peca=='Q' ? 'a':'x';
                }
                else{
                    barreira[0][0] = 1;
                }
            }


            if(x-i < 0 || y+i >= 8){
                barreira[0][1] = 1;
            }
            if(!barreira[0][1]){
                if(tempxadrez[x-i][y+i] == ' '){
                    tempxadrez[x-i][y+i] = peca=='Q' ? 'X':'x';
                }
                else if(tempxadrez[x-i][y+i] == 'A'){
                    tempxadrez[x-i][y+i] = peca=='Q' ? 'X':'A';
                }
                else if(tempxadrez[x-i][y+i] == 'a'){
                    tempxadrez[x-i][y+i] = peca=='Q' ? 'a':'x';
                }
                else{
                    barreira[0][1] = 1;
                }
            }


            if(x-i < 0 || y-i < 0){
                barreira[0][2] = 1;
            }
            if(!barreira[0][2]){
                if(tempxadrez[x-i][y-i] == ' '){
                    tempxadrez[x-i][y-i] = peca=='Q' ? 'X':'x';
                }
                else if(tempxadrez[x-i][y-i] == 'A'){
                    tempxadrez[x-i][y-i] = peca=='Q' ? 'X':'A';
                }
                else if(tempxadrez[x-i][y-i] == 'a'){
                    tempxadrez[x-i][y-i] = peca=='Q' ? 'a':'x';
                }
                else{
                    barreira[0][2] = 1;
                }
            }


            if(x+i >= 8 || y-i < 0){
                barreira[0][3] = 1;
            }
            if(!barreira[0][3]){
                if(tempxadrez[x+i][y-i] == ' '){
                    tempxadrez[x+i][y-i] = peca=='Q' ? 'X':'x';
                }
                else if(tempxadrez[x+i][y-i] == 'A'){
                    tempxadrez[x+i][y-i] = peca=='Q' ? 'X':'A';
                }
                else if(tempxadrez[x+i][y-i] == 'a'){
                    tempxadrez[x+i][y-i] = peca=='Q' ? 'a':'x';
                }
                else{
                    barreira[0][3] = 1;
                }
            }
        }


        for(int i = 1; i <= 8; i++){
            if(x+i >= 8){
                barreira[1][0] = 1;
            }
            if(!barreira[1][0]){
                if(tempxadrez[x+i][y] == ' '){
                    tempxadrez[x+i][y] = peca=='Q' ? 'X':'x';
                }
                else if(tempxadrez[x+i][y] == 'A'){
                    tempxadrez[x+i][y] = peca=='Q' ? 'X':'A';
                }
                else if(tempxadrez[x+i][y] == 'a'){
                    tempxadrez[x+i][y] = peca=='Q' ? 'a':'x';
                }
                else{
                    barreira[1][0] = 1;
                }
            }


            if(y+i >= 8){
                barreira[1][1] = 1;
            }
            if(!barreira[1][1]){
                if(tempxadrez[x][y+i] == ' '){
                    tempxadrez[x][y+i] = peca=='Q' ? 'X':'x';
                }
                else if(tempxadrez[x][y+i] == 'A'){
                    tempxadrez[x][y+i] = peca=='Q' ? 'X':'A';
                }
                else if(tempxadrez[x][y+i] == 'a'){
                    tempxadrez[x][y+i] = peca=='Q' ? 'a':'x';
                }
                else{
                    barreira[1][1] = 1;
                }
            }


            if(x-i < 0){
                barreira[1][2] = 1;
            }
            if(!barreira[1][2]){
                if(tempxadrez[x-i][y] == ' '){
                    tempxadrez[x-i][y] = peca=='Q' ? 'X':'x';
                }
                else if(tempxadrez[x-i][y] == 'A'){
                    tempxadrez[x-i][y] = peca=='Q' ? 'X':'A';
                }
                else if(tempxadrez[x-i][y] == 'a'){
                    tempxadrez[x-i][y] = peca=='Q' ? 'a':'x';
                }
                else{
                    barreira[1][2] = 1;
                }
            }


            if(y+i < 0){
                barreira[1][3] = 1;
            }
            if(!barreira[1][3]){
                if(tempxadrez[x][y-i] == ' '){
                    tempxadrez[x][y-i] = peca=='Q' ? 'X':'x';
                }
                else if(tempxadrez[x][y-i] == 'A'){
                    tempxadrez[x][y-i] = peca=='Q' ? 'X':'A';
                }
                else if(tempxadrez[x][y-i] == 'a'){
                    tempxadrez[x][y-i] = peca=='Q' ? 'a':'x';
                }
                else{
                    barreira[1][3] = 1;
                }
            }
        }
    }

//________________________________________
    if(peca == 'Q'){
        if(tempxadrez[linhadestino][colunadestino] == 'X'){
            return 1;
        }
    }
    else if(peca == 'q'){
        if(tempxadrez[linhadestino][colunadestino] == 'x'){
            return 1;
        }
    }
    return 0;
}
int rei(char peca, int linhaorigem, int colunaorigem, int linhadestino, int colunadestino){
    int x = linhaorigem;
    int y = colunaorigem;
    int barreira[4] = {0, 0, 0, 0};
    char tempxadrez[8][8];

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            tempxadrez[i][j] = xadrez[i][j];
            char temppeca = tempxadrez[i][j];

            for(int i = 0; i < 6; i++){
                if(peca == 'R'){
                    if(temppeca == p2[i]){
                        tempxadrez[i][j] = 'A';
                    }
                }
                else if(peca == 'r'){
                    if(temppeca == p1[i]){
                        tempxadrez[i][j] = 'a';
                    }
                }
            }
            if(peca == 'R'){
                if(temppeca == 'X'){
                    tempxadrez[i][j] = ' ';
                }
            }
            if(peca == 'r'){
                if(temppeca == 'x'){
                    tempxadrez[i][j] = ' ';
                }
            }
            if(temppeca == 'W'){
                tempxadrez[i][j] = 'W';
            }
        }
    }

    if(peca == 'R' || peca == 'r'){
        if(tempxadrez[x-1][y-1] == ' '){
            tempxadrez[x-1][y-1] = peca=='R' ? 'X':'x';
        }
        else if(tempxadrez[x-1][y-1] == 'A'){
            tempxadrez[x-1][y-1] = peca=='R' ? 'X':'A';
        }
        else if(tempxadrez[x-1][y-1] == 'a'){
            tempxadrez[x-1][y-1] = peca=='R' ? 'a':'x';
        }

        if(tempxadrez[x-1][y] == ' '){
            tempxadrez[x-1][y] = peca=='R' ? 'X':'x';
        }
        else if(tempxadrez[x-1][y] == 'A'){
            tempxadrez[x-1][y] = peca=='R' ? 'X':'A';
        }
        else if(tempxadrez[x-1][y] == 'a'){
            tempxadrez[x-1][y] = peca=='R' ? 'a':'x';
        }

        if(tempxadrez[x-1][y+1] == ' '){
            tempxadrez[x-1][y+1] = peca=='R' ? 'X':'x';
        }
        else if(tempxadrez[x-1][y+1] == 'A'){
            tempxadrez[x-1][y+1] = peca=='R' ? 'X':'A';
        }
        else if(tempxadrez[x-1][y+1] == 'a'){
            tempxadrez[x-1][y+1] = peca=='R' ? 'a':'x';
        }

        if(tempxadrez[x][y+1] == ' '){
            tempxadrez[x][y+1] = peca=='R' ? 'X':'x';
        }
        else if(tempxadrez[x][y+1] == 'A'){
            tempxadrez[x][y+1] = peca=='R' ? 'X':'A';
        }
        else if(tempxadrez[x][y+1] == 'a'){
            tempxadrez[x][y+1] = peca=='R' ? 'a':'x';
        }

        if(tempxadrez[x+1][y+1] == ' '){
            tempxadrez[x+1][y+1] = peca=='R' ? 'X':'x';
        }
        else if(tempxadrez[x+1][y+1] == 'A'){
            tempxadrez[x+1][y+1] = peca=='R' ? 'X':'A';
        }
        else if(tempxadrez[x+1][y+1] == 'a'){
            tempxadrez[x+1][y+1] = peca=='R' ? 'a':'x';
        }

        if(tempxadrez[x+1][y] == ' '){
            tempxadrez[x+1][y] = peca=='R' ? 'X':'x';
        }
        else if(tempxadrez[x+1][y] == 'A'){
            tempxadrez[x+1][y] = peca=='R' ? 'X':'A';
        }
        else if(tempxadrez[x+1][y] == 'a'){
            tempxadrez[x+1][y] = peca=='R' ? 'a':'x';
        }

        if(tempxadrez[x+1][y-1] == ' '){
            tempxadrez[x+1][y-1] = peca=='R' ? 'X':'x';
        }
        else if(tempxadrez[x+1][y-1] == 'A'){
            tempxadrez[x+1][y-1] = peca=='R' ? 'X':'A';
        }
        else if(tempxadrez[x+1][y-1] == 'a'){
            tempxadrez[x+1][y-1] = peca=='R' ? 'a':'x';
        }

        if(tempxadrez[x][y-1] == ' '){
            tempxadrez[x][y-1] = peca=='R' ? 'X':'x';
        }
        else if(tempxadrez[x][y-1] == 'A'){
            tempxadrez[x][y-1] = peca=='R' ? 'X':'A';
        }
        else if(tempxadrez[x][y-1] == 'a'){
            tempxadrez[x][y-1] = peca=='R' ? 'a':'x';
        }
    }

    if(peca == 'R'){
        if(tempxadrez[linhadestino][colunadestino] == 'X'){
            return 1;
        }
    }
    else if(peca == 'r'){
        if(tempxadrez[linhadestino][colunadestino] == 'x'){
            return 1;
        }
    }
    return 0;
}                                                                                               
//movimenta��o das pe�as
int moverpeca(int jogador, int linhaorigem, int colunaorigem, int linhadestino, int colunadestino) {
int mover = 0;
int peca = xadrez[linhaorigem][colunaorigem];
int deslvertical = abs(linhadestino - linhaorigem);
int deslhorizontal = abs(colunadestino - colunaorigem);
if( (linhaorigem >=0 && linhaorigem < 8 && colunaorigem >= 0 && colunaorigem < 8) &&
    (linhadestino>=0 && linhadestino < 8 && colunadestino >= 0 && colunadestino < 8) ) {

    if(jogador == -1){
        if (peca == 'T') {
            if(torre('T', linhaorigem, colunaorigem, linhadestino, colunadestino)){
                mover = 1 ;
            }
        }
        if (peca == 'B') {
            if(bispo('B', linhaorigem, colunaorigem, linhadestino, colunadestino)){
                mover = 1 ;
            }
        }
        if (peca == 'C'){
            if(cavalo('C', linhaorigem, colunaorigem, linhadestino, colunadestino)) {
                mover = 1 ;
            }
        }
        if (peca == 'Q'){
            if(rainha('Q', linhaorigem, colunaorigem, linhadestino, colunadestino)) {
                mover = 1 ;
            }
        }
        if (peca == 'R'){
            if(rei('R', linhaorigem, colunaorigem, linhadestino, colunadestino)) {
                mover = 1 ;
            }
        }
        if (peca == 'P'){
            if(peao('P', linhaorigem, colunaorigem, linhadestino, colunadestino)){
                mover = 1 ;
            }
        }
        if(mover){
            xadrez[linhadestino][colunadestino] = xadrez[linhaorigem][colunaorigem];
            xadrez[linhaorigem][colunaorigem] = ' ';
        
            return 1;
        }
        else{
            return 0;
        }
    }
    else if(jogador == 1){
        if (peca == 't') {
            if(torre('t', linhaorigem, colunaorigem, linhadestino, colunadestino)){
                mover = 1 ;
            }
        }
        if (peca == 'b') {  //movimenta��o do bispo
            if(bispo('b', linhaorigem, colunaorigem, linhadestino, colunadestino)){
                mover = 1 ;
            }
        }
        if (peca == 'c'){
            if(cavalo('c', linhaorigem, colunaorigem, linhadestino, colunadestino)) {
                mover = 1 ;
            }
        }
        if (peca == 'q'){
            if(rainha('q', linhaorigem, colunaorigem, linhadestino, colunadestino)) {
                mover = 1 ;
            }
        }
        if (peca == 'r'){
            if(rei('r', linhaorigem, colunaorigem, linhadestino, colunadestino)) {
                mover = 1 ;
            }
        }
        if (peca == 'p'){
            if(peao('p', linhaorigem, colunaorigem, linhadestino, colunadestino)){
                mover = 1 ;
            }
        }
        if(mover){
            xadrez[linhadestino][colunadestino] = xadrez[linhaorigem][colunaorigem];
            xadrez[linhaorigem][colunaorigem] = ' ';

            return 1;
        }
        else{
            return 0;
        }
    }

    } else {
        return 0 ;
    }
}
int testemoverpeca(char peca, int linhaorigem, int colunaorigem, int linhadestino, int colunadestino){
    if(peca == 'p'){
        return peao('p', linhaorigem, colunaorigem, linhadestino, colunadestino);
    }
    else if(peca == 'c'){
        return cavalo('c', linhaorigem, colunaorigem, linhadestino, colunadestino);
    }
    else if(peca == 't'){
        return torre('t', linhaorigem, colunaorigem, linhadestino, colunadestino);
    }
    else if(peca == 'b'){
        return bispo('b', linhaorigem, colunaorigem, linhadestino, colunadestino);
    }
    else if(peca == 'q'){
        return rainha('q', linhaorigem, colunaorigem, linhadestino, colunadestino);
    }
    return 0;
}
int moveraleatoriamente(){
    if(xeque){
        for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){

                if(xadrez[x][y] == 'r'){

                    for(int w = 0; w < 8; w++){
                        for(int z = 0; z < 8; z++){
                            if(rei('r', x, y, w, z)){
                                if(moverpeca(1, x, y, w, z) == 1){
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else{
        int encontrado = 0;
        while(!encontrado){
            for(int x = 0; x < 8; x++){
                for(int y = 0; y < 8; y++){
                    for(int i = 0; i < 6; i++){
                        int ran = rand() % 100+1;
                        if(ran == 1){
                            if(xadrez[x][y] == p2[i]){
                                for(int w = 0; w < 8; w++){
                                    for(int z = 0; z < 8; z++){
                                        if(testemoverpeca(xadrez[x][y], x, y, w, z) == 1){
                                            if(moverpeca(1, x, y, w, z) == 1){
                                                encontrado = 1;
                                                return 0;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

int testexeque(int jogador, int linhaorigem, int colunaorigem, int linhadestino, int colunadestino){
    if(xeque == 1){
        if(jogador = -1){
            if(xadrez[linhaorigem][colunaorigem] != 'r'){
                return 1;
            }
            else{
                xeque = 0;
            }
        }
        else if(jogador = 1){
            if(xadrez[linhaorigem][colunaorigem] != 'R'){
                return 1;
            }
            else{
                xeque = 0;
            }
        }
    }
    return 0;
}
int testexequemate(int jogador) {
    if(jogador == -1){
        int linhaorigem, colunaorigem;

        for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
                if(xadrez[x][y] == 'R'){
                    linhaorigem = x;
                    colunaorigem = y;
                }
            }
        }
        for(int x = -1; x <= 1; x++){
            for(int y = -1; y <= 1; y++){
                if(linhaorigem+x >= 0 && colunaorigem+y >= 0 && linhaorigem+x < 8 && colunaorigem+y < 8){
                    if(rei('R', linhaorigem, colunaorigem, linhaorigem+x, colunaorigem+y)){
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
    if(jogador == 1){
        int linhaorigem, colunaorigem;

        for(int x = 0; x < 8; x++){
            for(int y = 0; y < 8; y++){
                if(xadrez[x][y] == 'r'){
                    linhaorigem = x;
                    colunaorigem = y;
                }
            }
        }
        for(int x = -1; x <= 1; x++){
            for(int y = -1; y <= 1; y++){
                if(linhaorigem+x >= 0 && colunaorigem+y >= 0 && linhaorigem+x < 8 && colunaorigem+y < 8){
                    if(rei('r', linhaorigem, colunaorigem, linhaorigem+x, colunaorigem+y)){
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
    return 1;
}

int main() {
    criartabuleiro(xadrez);

    int movimentoinvalido;
    int jogador = -1;
    int xequemate = 0;
    int escolha;

    char P1[15];
    char P2[15];
    int pontuacaoP1 = 0;
    int pontuacaoP2 = 0;

    int linhaorigem, linhadestino, colunaorigem, colunadestino;

    FILE *rank;

    printf("Escolha uma opção:\n1- 1 Pessoa\n2- 2 Pessoas\n3- Ranking\n4- Créditos\n");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:{
        printf("P1, Digite seu nome: ");
        scanf("%s", P1);
        
        while(jogador != 0) {
            pintartabuleiro();

            if(movimentoinvalido == 1){
                printf("coordenadas invalidas\n");
                movimentoinvalido = 0;
            }
            if(xeque == 1){
                printf("Seu rei está sobre ataque, mova-o\n");
            }

            if(jogador == -1){
                printf("P1, 1nforme a linha e coluna de origem: ");
                scanf("%d %d",&linhaorigem, &colunaorigem);

                printf("\nPeca: %c, informe a linha e coluna de destino: ", xadrez[linhaorigem-1][colunaorigem-1]);
                scanf("%d %d",&linhadestino, &colunadestino);

                if (testexeque(jogador, linhaorigem-1, colunaorigem-1, linhadestino-1, colunadestino-1)) {
                    movimentoinvalido = 1;
                }
                else if(moverpeca(jogador, linhaorigem-1, colunaorigem-1, linhadestino-1, colunadestino-1) == 1){
                    pecasatacadas();
                    jogador *= -1;
                }
                else{
                    movimentoinvalido = 1;
                }

                if(xeque == 1){
                    if(testexequemate(jogador)){
                        jogador*=-1;
                        if(jogador == -1){
                            pontuacaoP1++;
                            printf("\nP1 Venceu!");
                        }
                        else if(jogador == 1){
                            pontuacaoP2++;
                            printf("\nP2 Venceu!");
                        }
                        xequemate = 1;
                    }
                }
                if(xequemate == 1){
                    jogador = 0;
                }
            }
            else if(jogador == 1){
                moveraleatoriamente(linhaorigem, colunaorigem, linhadestino, colunadestino);
                pecasatacadas();

                if(xeque == 1){
                    if(testexequemate(jogador)){
                        if(jogador == -1){
                            pontuacaoP1++;
                            printf("\nP1 Venceu!");
                        }
                        else if(jogador == 1){
                            printf("\nComputador Venceu!");
                        }
                        xequemate = 1;
                    }
                }
                if(xequemate == 1){
                    int continuar;
                    printf("Deseja iniciar um novo jogo?\n1 - Sim\n2 - Nao");
                    scanf("%d", &continuar);
                    if(continuar == 1){
                        xeque = 0;
                        xequemate = 0;
                        criartabuleiro(xadrez);
                        jogador = 1;
                    }
                    else{
                        rank = fopen("ranking.txt", "a");

                        fprintf(rank, "%s: %d\n", P1, pontuacaoP1);
                        fclose(rank);
                        jogador = 0;
                    }
                }
                jogador *= -1;
            }
        }
        break;
    }
    case 2:{
        printf("P1, Digite seu nome: ");
        scanf("%s", P1);
        printf("P2, Digite seu nome: ");
        scanf("%s", P2);
        
        while(jogador != 0) {
            pintartabuleiro();

            if(movimentoinvalido == 1){
                printf("coordenadas invalidas\n");
                movimentoinvalido = 0;
            }
            if(xeque == 1){
                printf("Seu rei está sobre ataque, mova-o\n");
            }

            if(jogador == -1){
                printf("P1, 1nforme a linha e coluna de origem: ");
            }
            else if(jogador == 1){
                printf("P2, 1nforme a linha e coluna de origem: ");
            }
            scanf("%d %d",&linhaorigem, &colunaorigem);

            printf("\nPeca: %c, informe a linha e coluna de destino: ", xadrez[linhaorigem-1][colunaorigem-1]);
            scanf("%d %d",&linhadestino, &colunadestino);

            
            if (testexeque(jogador, linhaorigem-1, colunaorigem-1, linhadestino-1, colunadestino-1)) {
                movimentoinvalido = 1;
            }
            else if(moverpeca(jogador, linhaorigem-1, colunaorigem-1, linhadestino-1, colunadestino-1) == 1){
                pecasatacadas();
                jogador *= -1;
            }
            else{
                movimentoinvalido = 1;
            }

            if(xeque == 1){
                if(testexequemate(jogador)){
                    jogador*=-1;
                    if(jogador == -1){
                        pontuacaoP1++;
                        printf("\nP1 Venceu!\n");
                    }
                    else if(jogador == 1){
                        pontuacaoP2++;
                        printf("\nP2 Venceu!\n");
                    }
                    xequemate = 1;
                }
            }
            if(xequemate == 1){
                    int continuar;
                    printf("Deseja iniciar um novo jogo?\n1 - Sim\n2 - Nao\n");
                    scanf("%d", &continuar);
                    if(continuar == 1){
                        xeque = 0;
                        xequemate = 0;
                        criartabuleiro(xadrez);
                        jogador = -1;
                    }
                    else{
                        rank = fopen("ranking.txt", "a");

                        fprintf(rank, "%s: %d\n", P1, pontuacaoP1);
                        fprintf(rank, "%s: %d\n", P2, pontuacaoP2);
                        fclose(rank);
                        jogador = 0;
                    }
                }
        }

        break;
    }
    case 3: //Ranking
        rank = fopen("ranking.txt", "rb");
        char c;
        do
        {
            //faz a leitura do caracter no arquivo apontado por pont_arq
            c = fgetc(rank);
            
            //exibe o caracter lido na tela
            printf("%c" , c);    
            
        }while (c != EOF);
        fclose(rank);
        
        break;
    case 4: //Créditos
        printf("\n\n\n\n\nEsse jogo foi feito por: \nBianca Schiochet Tiepolo – RGM: 26140489\nCélio Santos da Silva – RGM: 27219551\nKleber Herivelto de Lima Cavalcanti Filho - RGM: 25365037\nMatheus Fialho Barbosa - RGM: 27296377\nMatheus Henrique Meireles de Almeida Silva – RGM: 26565901");
        break;
    case 5: //Sair
        break;
    default:{}
    }
    return 0 ;
}
