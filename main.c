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
                    printf("  %c  ",letra);

                }
            }
            printf("\n");
        }
    }
}
      
int pecasatacadas(){
    //for limpa todos os x e X do tabuleiro e cria novos
    for(int x = 0; x < 8; x++){
        for(int y = 0; y < 8; y++){
            char peca = xadrez[x][y];

            if(peca == 'X' || peca == 'x'){
                xadrez[x][y] = ' ';
            }
            else if(peca == 'P'){
                if(x < 7 && y > 0){
                    if(xadrez[x+1][y-1] == 'x'){
                        xadrez[x+1][y-1] = 'Xx';
                    }
                    else if(xadrez[x+1][y-1] == ' '){
                        xadrez[x+1][y-1] = 'X';
                    }
                }
                if(x < 7 && y < 7){
                    if(xadrez[x+1][y+1] == 'x'){
                        xadrez[x+1][y+1] = 'Xx';
                    }
                    else if(xadrez[x+1][y+1] == ' '){
                        xadrez[x+1][y+1] = 'X';
                    }
                }
            }
            else if(peca == 'p'){
                if(x > 0 && y > 0){
                    if(xadrez[x+1][y-1] == 'X'){
                        xadrez[x+1][y-1] = 'Xx';
                    }
                    else if(xadrez[x+1][y-1] == ' '){
                        xadrez[x+1][y-1] = 'X';
                    }
                }
                if(x > 0 && y < 7){
                    if(xadrez[x-1][y+1] == 'X'){
                        xadrez[x-1][y+1] = 'Xx';
                    }
                    else if(xadrez[x-1][y+1] == ' '){
                        xadrez[x-1][y+1] = 'X';
                    }
                }
            }
            else if(peca == 'C' || peca == 'c'){
                if(x >= 2 && y >= 1){
                    if(xadrez[x-2][y-1] == 'X'){
                        xadrez[x-2][y-1] = peca == 'C' ? 'X':'Xx';
                    }
                    else if(xadrez[x-2][y-1] == 'x'){
                        xadrez[x-2][y-1] = peca == 'C' ? 'Xx':'x';
                    }
                    else if(xadrez[x-2][y-1] == ' '){
                        xadrez[x-2][y-1] = peca == 'C' ? 'X':'x';
                    }
                }
                if(x >= 2 && y < 7){
                    if(xadrez[x-2][y+1] == 'X'){
                        xadrez[x-2][y+1] = peca == 'C' ? 'X':'Xx';
                    }
                    else if(xadrez[x-2][y+1] == 'x'){
                        xadrez[x-2][y+1] = peca == 'C' ? 'Xx':'x';
                    }
                    else if(xadrez[x-2][y+1] == ' '){
                        xadrez[x-2][y+1] = peca == 'C' ? 'X':'x';
                    }
                }
                if(x >= 1 && y < 6){
                    if(xadrez[x-1][y+2] == 'X'){
                        xadrez[x-1][y+2] = peca == 'C' ? 'X':'Xx';
                    }
                    else if(xadrez[x-1][y+2] == 'x'){
                        xadrez[x-1][y+2] = peca == 'C' ? 'Xx':'x';
                    }
                    else if(xadrez[x-1][y+2] == ' '){
                        xadrez[x-1][y+2] = peca == 'C' ? 'X':'x';
                    }
                }
                if(x < 7 && y < 6){
                    if(xadrez[x+1][y+2] == 'X'){
                        xadrez[x+1][y+2] = peca == 'C' ? 'X':'Xx';
                    }
                    else if(xadrez[x+1][y+2] == 'x'){
                        xadrez[x+1][y+2] = peca == 'C' ? 'Xx':'x';
                    }
                    else if(xadrez[x+1][y+2] == ' '){
                        xadrez[x+1][y+2] = peca == 'C' ? 'X':'x';
                    }
                }
                if(x < 6 && y >= 1){
                    if(xadrez[x+2][y+1] == 'X'){
                        xadrez[x+2][y+1] = peca == 'C' ? 'X':'Xx';
                    }
                    else if(xadrez[x+2][y+1] == 'x'){
                        xadrez[x+2][y+1] = peca == 'C' ? 'Xx':'x';
                    }
                    else if(xadrez[x+2][y+1] == ' '){
                        xadrez[x+2][y+1] = peca == 'C' ? 'X':'x';
                    }
                }
                if(x < 6 && y >= 1){
                    if(xadrez[x+2][y-1] == 'X'){
                        xadrez[x+2][y-1] = peca == 'C' ? 'X':'Xx';
                    }
                    else if(xadrez[x+2][y-1] == 'x'){
                        xadrez[x+2][y-1] = peca == 'C' ? 'Xx':'x';
                    }
                    else if(xadrez[x+2][y-1] == ' '){
                        xadrez[x+2][y-1] = peca == 'C' ? 'X':'x';
                    }
                }
                if(x < 7 && y >= 2){
                    if(xadrez[x+1][y-2] == 'X'){
                        xadrez[x+1][y-2] = peca == 'C' ? 'X':'Xx';
                    }
                    else if(xadrez[x+1][y-2] == 'x'){
                        xadrez[x+1][y-2] = peca == 'C' ? 'Xx':'x';
                    }
                    else if(xadrez[x+1][y-2] == ' '){
                        xadrez[x+1][y-2] = peca == 'C' ? 'X':'x';
                    }
                }
                if(x >= 1 && y >= 2){
                    if(xadrez[x-1][y-2] == 'X'){
                        xadrez[x-1][y-2] = peca == 'C' ? 'X':'Xx';
                    }
                    else if(xadrez[x-1][y-2] == 'x'){
                        xadrez[x-1][y-2] = peca == 'C' ? 'Xx':'x';
                    }
                    else if(xadrez[x-1][y-2] == ' '){
                        xadrez[x-1][y-2] = peca == 'C' ? 'X':'x';
                    }
                }
            }
            else if(peca == 'B' || peca == 'b'){

                if(x+1 != 8 || y+1 != 8){
                    int barreira = 0;

                    for(int i = 1; i <= 8; i++){
                        if(x+i >= 8 || y+i >= 8){
                            barreira = 1;
                        }
                        if(!barreira){
                            if(xadrez[x+i][y+i] == ' '){
                                xadrez[x+i][y+i] = peca=='B' ? 'X':'x';
                            }
                            else if(xadrez[x+i][y+i] == 'X'){
                                xadrez[x+i][y+i] = peca=='B' ? 'X':'Xx';
                            }
                            else if(xadrez[x+i][y+i] == 'x'){
                                xadrez[x+i][y+i] = peca=='B' ? 'Xx':'X';
                            }
                            else{
                                barreira = 1;
                            }
                        }
                        barreira = 0;


                        if(x-i < 0 || y+i >= 8){
                            barreira = 1;
                        }
                        if(!barreira){
                            if(xadrez[x-i][y+i] == ' '){
                                xadrez[x-i][y+i] = peca=='B' ? 'X':'x';
                            }
                            else if(xadrez[x-i][y+i] == 'X'){
                                xadrez[x-i][y+i] = peca=='B' ? 'X':'Xx';
                            }
                            else if(xadrez[x-i][y+i] == 'x'){
                                xadrez[x-i][y+i] = peca=='B' ? 'Xx':'X';
                            }
                            else{
                                barreira = 1;
                            }
                        }
                        barreira = 0;


                        if(x-i < 0 || y+i < 0){
                            barreira = 1;
                        }
                        if(!barreira){
                            if(xadrez[x-i][y-i] == ' '){
                                xadrez[x-i][y-i] = peca=='B' ? 'X':'x';
                            }
                            else if(xadrez[x-i][y-i] == 'X'){
                                xadrez[x-i][y-i] = peca=='B' ? 'X':'Xx';
                            }
                            else if(xadrez[x-i][y-i] == 'x'){
                                xadrez[x-i][y-i] = peca=='B' ? 'Xx':'X';
                            }
                            else{
                                barreira = 1;
                            }
                        }
                        barreira = 0;


                        if(x+i >= 0 || y+i < 0){
                            barreira = 1;
                        }
                        if(!barreira){
                            if(xadrez[x+i][y-i] == ' '){
                                xadrez[x+i][y-i] = peca=='B' ? 'X':'x';
                            }
                            else if(xadrez[x+i][y-i] == 'X'){
                                xadrez[x+i][y-i] = peca=='B' ? 'X':'Xx';
                            }
                            else if(xadrez[x+i][y-i] == 'x'){
                                xadrez[x+i][y-i] = peca=='B' ? 'Xx':'X';
                            }
                            else{
                                barreira = 1;
                            }
                        }
                        barreira = 0;
                    }
                }
            }
            else if(peca == 'T' || peca == 't'){

                if(x+1 != 8 || y+1 != 8){
                    int barreira = 0;

                    for(int i = 1; i <= 8; i++){
                        if(x+i >= 8){
                            barreira = 1;
                        }
                        if(!barreira){
                            if(xadrez[x+i][y] == ' '){
                                xadrez[x+i][y] = peca=='T' ? 'X':'x';
                            }
                            else if(xadrez[x+i][y] == 'X'){
                                xadrez[x+i][y] = peca=='T' ? 'X':'Xx';
                            }
                            else if(xadrez[x+i][y] == 'x'){
                                xadrez[x+i][y] = peca=='T' ? 'Xx':'X';
                            }
                            else{
                                barreira = 1;
                            }
                        }
                        barreira = 0;


                        if(y+i >= 8){
                            barreira = 1;
                        }
                        if(!barreira){
                            if(xadrez[x][y+i] == ' '){
                                xadrez[x][y+i] = peca=='T' ? 'X':'x';
                            }
                            else if(xadrez[x][y+i] == 'X'){
                                xadrez[x][y+i] = peca=='T' ? 'X':'Xx';
                            }
                            else if(xadrez[x][y+i] == 'x'){
                                xadrez[x][y+i] = peca=='T' ? 'Xx':'X';
                            }
                            else{
                                barreira = 1;
                            }
                        }
                        barreira = 0;


                        if(x-i < 0){
                            barreira = 1;
                        }
                        if(!barreira){
                            if(xadrez[x-i][y] == ' '){
                                xadrez[x-i][y] = peca=='T' ? 'X':'x';
                            }
                            else if(xadrez[x-i][y] == 'X'){
                                xadrez[x-i][y] = peca=='T' ? 'X':'Xx';
                            }
                            else if(xadrez[x-i][y] == 'x'){
                                xadrez[x-i][y] = peca=='T' ? 'Xx':'X';
                            }
                            else{
                                barreira = 1;
                            }
                        }
                        barreira = 0;


                        if(y+i < 0){
                            barreira = 1;
                        }
                        if(!barreira){
                            if(xadrez[x][y-i] == ' '){
                                xadrez[x][y-i] = peca=='T' ? 'X':'x';
                            }
                            else if(xadrez[x][y-i] == 'X'){
                                xadrez[x][y-i] = peca=='T' ? 'X':'Xx';
                            }
                            else if(xadrez[x][y-i] == 'x'){
                                xadrez[x][y-i] = peca=='T' ? 'Xx':'X';
                            }
                            else{
                                barreira = 1;
                            }
                        }
                        barreira = 0;
                    }
                }
            }
            else if(peca == 'Q' || peca == 'q'){

                if(x+1 != 8 || y+1 != 8){
                    int barreira = 0;

                    for(int i = 1; i <= 8; i++){
                        if(x+i >= 8 || y+i >= 8){
                            barreira = 1;
                        }
                        if(!barreira){
                            if(xadrez[x+i][y+i] == ' '){
                                xadrez[x+i][y+i] = peca=='Q' ? 'X':'x';
                            }
                            else if(xadrez[x+i][y+i] == 'X'){
                                xadrez[x+i][y+i] = peca=='Q' ? 'X':'Xx';
                            }
                            else if(xadrez[x+i][y+i] == 'x'){
                                xadrez[x+i][y+i] = peca=='Q' ? 'Xx':'X';
                            }
                            else{
                                barreira = 1;
                            }
                        }
                        barreira = 0;


                        if(x-i < 0 || y+i >= 8){
                            barreira = 1;
                        }
                        if(!barreira){
                            if(xadrez[x-i][y+i] == ' '){
                                xadrez[x-i][y+i] = peca=='Q' ? 'X':'x';
                            }
                            else if(xadrez[x-i][y+i] == 'X'){
                                xadrez[x-i][y+i] = peca=='Q' ? 'X':'Xx';
                            }
                            else if(xadrez[x-i][y+i] == 'x'){
                                xadrez[x-i][y+i] = peca=='Q' ? 'Xx':'X';
                            }
                            else{
                                barreira = 1;
                            }
                        }
                        barreira = 0;


                        if(x-i < 0 || y+i < 0){
                            barreira = 1;
                        }
                        if(!barreira){
                            if(xadrez[x-i][y-i] == ' '){
                                xadrez[x-i][y-i] = peca=='Q' ? 'X':'x';
                            }
                            else if(xadrez[x-i][y-i] == 'X'){
                                xadrez[x-i][y-i] = peca=='Q' ? 'X':'Xx';
                            }
                            else if(xadrez[x-i][y-i] == 'x'){
                                xadrez[x-i][y-i] = peca=='Q' ? 'Xx':'X';
                            }
                            else{
                                barreira = 1;
                            }
                        }
                        barreira = 0;


                        if(x+i >= 0 || y+i < 0){
                            barreira = 1;
                        }
                        if(!barreira){
                            if(xadrez[x+i][y-i] == ' '){
                                xadrez[x+i][y-i] = peca=='Q' ? 'X':'x';
                            }
                            else if(xadrez[x+i][y-i] == 'X'){
                                xadrez[x+i][y-i] = peca=='Q' ? 'X':'Xx';
                            }
                            else if(xadrez[x+i][y-i] == 'x'){
                                xadrez[x+i][y-i] = peca=='Q' ? 'Xx':'X';
                            }
                            else{
                                barreira = 1;
                            }
                        }
                        barreira = 0;
                    }
                }


                if(x+1 != 8 || y+1 != 8){
                    int barreira = 0;

                    for(int i = 1; i <= 8; i++){
                        if(x+i >= 8){
                            barreira = 1;
                        }
                        if(!barreira){
                            if(xadrez[x+i][y] == ' '){
                                xadrez[x+i][y] = peca=='Q' ? 'X':'x';
                            }
                            else if(xadrez[x+i][y] == 'X'){
                                xadrez[x+i][y] = peca=='Q' ? 'X':'Xx';
                            }
                            else if(xadrez[x+i][y] == 'x'){
                                xadrez[x+i][y] = peca=='Q' ? 'Xx':'X';
                            }
                            else{
                                barreira = 1;
                            }
                        }
                        barreira = 0;


                        if(y+i >= 8){
                            barreira = 1;
                        }
                        if(!barreira){
                            if(xadrez[x][y+i] == ' '){
                                xadrez[x][y+i] = peca=='Q' ? 'X':'x';
                            }
                            else if(xadrez[x][y+i] == 'X'){
                                xadrez[x][y+i] = peca=='Q' ? 'X':'Xx';
                            }
                            else if(xadrez[x][y+i] == 'x'){
                                xadrez[x][y+i] = peca=='Q' ? 'Xx':'X';
                            }
                            else{
                                barreira = 1;
                            }
                        }
                        barreira = 0;


                        if(x-i < 0){
                            barreira = 1;
                        }
                        if(!barreira){
                            if(xadrez[x-i][y] == ' '){
                                xadrez[x-i][y] = peca=='Q' ? 'X':'x';
                            }
                            else if(xadrez[x-i][y] == 'X'){
                                xadrez[x-i][y] = peca=='Q' ? 'X':'Xx';
                            }
                            else if(xadrez[x-i][y] == 'x'){
                                xadrez[x-i][y] = peca=='Q' ? 'Xx':'X';
                            }
                            else{
                                barreira = 1;
                            }
                        }
                        barreira = 0;


                        if(y+i < 0){
                            barreira = 1;
                        }
                        if(!barreira){
                            if(xadrez[x][y-i] == ' '){
                                xadrez[x][y-i] = peca=='Q' ? 'X':'x';
                            }
                            else if(xadrez[x][y-i] == 'X'){
                                xadrez[x][y-i] = peca=='Q' ? 'X':'Xx';
                            }
                            else if(xadrez[x][y-i] == 'x'){
                                xadrez[x][y-i] = peca=='Q' ? 'Xx':'X';
                            }
                            else{
                                barreira = 1;
                            }
                        }
                        barreira = 0;
                    }
                }
            }
        }
    }
}
int moverrei(int jogador, int linhaorigem, int colunaorigem, int linhadestino, int colunadestino){
    int peca = xadrez [linhaorigem][colunaorigem];
    int pecaf = xadrez [linhadestino][colunadestino];
    int deslvertical = abs(linhadestino - linhaorigem);
    int deslhorizontal = abs(colunadestino - colunaorigem);

    if( (linhaorigem >=0 && linhaorigem < 8 && colunaorigem >= 0 && colunaorigem < 8) &&
        (linhadestino>=0 && linhadestino < 8 && colunadestino >= 0 && colunadestino < 8) ) {

        if(jogador == -1){
            if(pecaf != ' '){
                return 0;
            }
            else if(pecaf != 'x'){
                
            }
            else if(){
                
            }
            else if(){
                
            }
            else{
                return 1;
            }
        }
        if(jogador == 1){
            if(pecaf != ' '){
                return 0;
            }
            else if (!( (peca == 'R') && (deslvertical >= 0 && deslvertical <= 1         //movimeta��o do rei
                || deslhorizontal >= 0 && deslhorizontal <= 1))) {
                return 0;
            }
            else if(){

            }
            else{
                return 1;
            }
        }
    }
    else{
        return 0;
    }
    return 1;
}                                                                                               
//movimenta��o das pe�as
int moverpeca(int jogador, int linhaorigem, int colunaorigem, int linhadestino, int colunadestino) {
int mover = 0;
int peca = xadrez [linhaorigem][colunaorigem];
int deslvertical = abs(linhadestino - linhaorigem);
int deslhorizontal = abs(colunadestino - colunaorigem);
if( (linhaorigem >=0 && linhaorigem < 8 && colunaorigem >= 0 && colunaorigem < 8) &&
    (linhadestino>=0 && linhadestino < 8 && colunadestino >= 0 && colunadestino < 8) ) {

    if(jogador == -1){
        if ( (peca == 'T') && (deslvertical == 0 || deslhorizontal == 0) ) {          //movimenta��o da torre
            mover = 1 ;
        }
        if ( (peca == 'B') && (deslvertical ==  deslhorizontal) ) {                   //movimenta��o do bispo
            mover = 1 ;
        }
        if ( (peca == 'C') && ((deslvertical == 1 && deslhorizontal == 2)              //movimenta��o do cavalo
            ||(deslvertical == 2 && deslhorizontal == 1)) ) {
            mover = 1 ;
        }
        if ( (peca == 'Q') && ((deslvertical ==  deslhorizontal)                   //movimeta��o da rainha
            ||(deslvertical == 0 || deslhorizontal == 0)) ) {
            mover = 1 ;
        }
        if ( (peca == 'R') && ((deslvertical >= 0 && deslvertical <= 1)           //movimeta��o do rei
            || (deslhorizontal >= 0 && deslhorizontal <= 1)) ) {
            mover = 1 ;
        }
        if ( (peca == 'P') && ( (linhadestino - linhaorigem) == 1  && (deslhorizontal == 0) 
            || deslhorizontal==1 && (linhadestino - linhaorigem)==1 && xadrez[linhadestino][colunadestino] != ' ') ) {   // movimeta��o do pe�o
            mover = 1 ;
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
        if ( (peca == 't') && (deslvertical == 0 || deslhorizontal == 0) ) {          //movimenta��o da torre
            mover = 1 ;
        }
        if ( (peca == 'b') && (deslvertical ==  deslhorizontal) ) {                   //movimenta��o do bispo
            mover = 1 ;
        }
        if ( (peca == 'c') && ((deslvertical == 1 && deslhorizontal == 2)              //movimenta��o do cavalo
            ||(deslvertical == 2 && deslhorizontal == 1)) ) {
            mover = 1 ;
        }
        if ( (peca == 'q') && ((deslvertical ==  deslhorizontal)                   //movimeta��o da rainha
            ||(deslvertical == 0 || deslhorizontal == 0)) ) {
            mover = 1 ;
        }
        if ( (peca == 'r') && ((deslvertical >= 0 && deslvertical <= 1)           //movimeta��o do rei
            || (deslhorizontal >= 0 && deslhorizontal <= 1)) ) {
            mover = 1 ;
        }
        if ( (peca == 'p') && ((linhadestino - linhaorigem) == -1  && (deslhorizontal == 0) 
            || deslhorizontal==1 && (linhadestino - linhaorigem)==-1 && xadrez[linhadestino][colunadestino] != ' ') ) {
            
            mover = 1 ;
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
        printf();
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
        chequemate = testcheque(jogador, linhadestino, colunadestino);

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

        printf("\ninforme a linha e coluna de destino: ");
        scanf("%d %d",&linhadestino, &colunadestino);

        if (moverpeca(jogador, linhaorigem, colunaorigem, linhadestino, colunadestino) != 1) {
            printf("\ncoordenadas invalidas");
            getch();

        }
        else{
            jogador *= -1;
        }
    }
    getch();
    return 0 ;
}