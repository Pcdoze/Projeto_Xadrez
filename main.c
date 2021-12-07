#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

char xadrez [8][8]= {
     { 'T', 'C', 'B', 'Q', 'R', 'B', 'C', 'T'},
     { 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
     { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X'},
     { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
     { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},   //tabuleiro
     { 'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x'},
     { 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
     { 't', 'c', 'b', 'q', 'r', 'b', 'c', 't'}
};
char p1 [6] = { 'T', 'C', 'B', 'Q', 'R', 'P'};
char p2 [6] = { 't', 'c', 'b', 'q', 'r', 'p'};

int pintartabuleiro() {
    system("cls");
    system("clear");

    int linha, coluna, r;
    for (linha=0; linha < 8 ; linha++){
        for (r = 0; r < 3; r++) {
            for(coluna=0; coluna < 8 ; coluna++){
                    char peca = xadrez[linha][coluna];
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
                    else if(xadrez[x+1][y-1] == ' '){
                        xadrez[x+1][y-1] = 'X';
                    }
                }
                if(x < 7 && y < 7){
                    if(xadrez[x+1][y+1] == 'x'){
                        xadrez[x+1][y+1] = 'W';
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
                    else if(xadrez[x-1][y-1] == ' '){
                        xadrez[x-1][y-1] = 'x';
                    }
                }
                if(x > 0 && y < 7){
                    if(xadrez[x-1][y+1] == 'X'){
                        xadrez[x-1][y+1] = 'W';
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


        if(x-i < 0 || y+i < 0){
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

        
        if(x+i >= 8 || y+i < 0){
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


            if(x-i < 0 || y+i < 0){
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


            if(x+i >= 8 || y+i < 0){
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
            if(bispo('T', linhaorigem, colunaorigem, linhadestino, colunadestino)){
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
            if(bispo('t', linhaorigem, colunaorigem, linhadestino, colunadestino)){
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

int testcheque(int jogador, int linhadestino, int colunadestino) {
    if(jogador == -1 && xadrez[linhadestino][colunadestino] == 'r'){
        printf(" ");
    }
    else if(jogador == 1 && xadrez[linhadestino][colunadestino] == 'R'){
        if(linhadestino >= 1 && linhadestino < 7 && colunadestino >= 1 && colunadestino < 7){
            if(xadrez){
                
            }
        }
        return 1;
    }

    return 0;
}

int main() {
    int jogador = -1;
    int chequemate = 0;

    int linhaorigem, linhadestino, colunaorigem, colunadestino;
    while(jogador != 0) {
        pintartabuleiro();
        //chequemate = testcheque(jogador, linhadestino, colunadestino);

        if(chequemate == 1){
            jogador = 0;
        }
        else if(chequemate == -1){
            jogador = 0;
        }

        if(jogador == -1){
            printf("P1, 1nforme a linha e coluna de origem: ");
        }
        else if(jogador == 1){
            printf("P2, 1nforme a linha e coluna de origem: ");
        }
        scanf("%d %d",&linhaorigem, &colunaorigem);

        printf("\nPeca: %c, informe a linha e coluna de destino: ", xadrez[linhaorigem][colunaorigem]);
        scanf("%d %d",&linhadestino, &colunadestino);

        if (moverpeca(jogador, linhaorigem, colunaorigem, linhadestino, colunadestino) != 1) {
            printf("\ncoordenadas invalidas");
            getch();

        }
        else{
            pecasatacadas();
            jogador *= -1;
        }
    }
    getch();
    return 0 ;
}