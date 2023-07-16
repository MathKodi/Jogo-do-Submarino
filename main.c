/*
Nome...: Matheus Kodi Y.
RA: 2503557 
Data...: 25/11/22 
Curso...: TADS - Algoritmos N11A (2022_02)
Trabalho final - JOGO DE CAÇA AO SUBMARINO 
*/
//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
//Variaveis Universais
int randlinha = 0,
    randcoluna = 0,
    Oceano[3][3] = {{0, 0, 0},
    				{0, 0, 0},
    				{0, 0, 0}};
//Funções secundárias
void mostraOceano(int x[3][3]);  //Função para mostrar a matriz do Oceano
void randlinhacoluna();          //Função para sortear a linha e coluna do Submarino
void limpaOceano();              //Função para limpar a posição do submarino e couraçado.
//Função principal
int main()
{
    //Variaveis
    int i = 0,  
        j = 0,
        ulinha = 0,
        ucoluna = 0,
        jogar = 0;   
    //Mensagem ao iniciar o jogo
    printf("Bem-Vindo ao Jogo do Submarino!    feito por...: Kodi Y.\n\n");
    printf("O Jogo consiste em um algoritmo controlando um submarino\n");
    printf("e  o  jogador  um  navio  de guerra chamado couraçado...\n\n");
    printf("Objetivo do  jogo  é  uma  embarcação  destruir a outra!\n");
    printf("E  uma  acha a outra  estando na mesma  posição, logo...\n");
    printf("Quem achar o outro primeiro ganha! Bom jogo e Boa sorte!\n\n");
    //Estrutura de repetição do-while para sempre repetir o jogo 
    do {
        mostraOceano(Oceano);              
        randlinhacoluna(); 
        //Estrutura de repetição do-while caso o usuário digite um número fora do intervalo de 0 a 2...
        do {
            //Entrada de Dados
            printf("Determine a posição do couraçado(a linha e a coluna)...:\n");
            scanf("%d %d", &ulinha, &ucoluna);      //Recebe a linha e coluna do couraçado
            
            //Estrutura de decisão caso o usuário digite um número fora do intervalo
            if(ulinha < 0 || ulinha > 2) {           
                printf("Linha fora do intervalo... Digite novamente...\n");
            }
            if(ucoluna < 0 || ucoluna > 2) {        
                printf("Coluna fora do intervalo... Digite novamente...\n");
            }
            //Processamento
            Oceano[ulinha][ucoluna] = 1;    //A matriz do oceano vai receber a posição do couraçado
        } while (ulinha < 0 || ulinha > 2 || ucoluna < 0 || ucoluna > 2); 
        //Estrutura de decisão caso o usuário acerte a posição do submarino
        if ( randlinha == ulinha && randcoluna == ucoluna) {
            sleep(1);       //função para pausar o programa por um tempo (não funciona em compilador online)
            mostraOceano(Oceano);
            //Saída de dados
            printf("Parabéns!!! Você acertou o submarino !!!\n");
            printf("Deseja jogar novamente?\n");
            printf("0 - para Sim\nQualquer outro valor - Para Sair\n"); 
            scanf("%d", &jogar);                           //Variavel inteiro, caso seja 0, o jogo será reiniciado e se for outro valor, o programa terminará
        }
        //Estrutura de decisão caso o usuário não acerte o submarino, fazendo o mesmo atacar o couraçado.
        else { 
            sleep(1); 
            mostraOceano(Oceano);
            //Saída de Dados
            printf("Submarino não encontrado...\n");        
            printf("Agora o Submarino irá te atacar...\n");
            randlinhacoluna();
            //Estrutura de decisão caso o submarino acerte o couraçado.
            if(randlinha == ulinha && randcoluna == ucoluna) { 
                sleep(1);                           
                mostraOceano(Oceano);  
                //Saída de Dados
                printf("Submarino acertou você... Game over...\n"); 
                printf("Deseja jogar novamente?\n");
                printf("0 - para Sim\nQualquer outro valor - Para Sair\n");                         
                scanf("%d", &jogar);       //Recebe um valor, 1 - para reiniciar o jogo, qualquer outro valor para sair
                system("cls");  //Limpa o console (não funciona em compilador online)
            }
            //Estrutura de decisão caso o submarino não acerte o couraçado - voltando o jogo para o começo
            else { 
                sleep(1);
                mostraOceano(Oceano);
                //Saída de Dados
                printf("Ufa! O submarino não te encontrou... Tente novamente!\n");
                system("pause");    //Função para pausar o programa e só continuar se o usuário digitar qualquer tecla. (não funciona em compilador online)
                system("cls");      //Limpa o console (não funciona em compilador online)
            }
        }
        limpaOceano();  //Limpa a posição do submarino e couraçado na matriz do Oceano.
    } while (jogar == 0);     //Enquanto o valor for 0, o jogo sempre será reiniciado
    return 0;
}
//Função para mostrar a matriz do Oceano
void mostraOceano(int x[3][3]) {
    int i = 0, j = 0, aux = 0;
    printf("   Campo do jogo (Oceano)...: \n");
    printf("   0  1  2\n");
    for(i = 0; i < 3; i++){
        printf("%d  ", aux);
        for(j = 0; j < 3; j++){
            if(x[i][j] == 1){ //Ao definir a posição do couraçado com a linha e coluna, o valor dessa posição será 1, apresentando o caracter 'C'.
                printf("C  ");
            }
            else
                if(x[i][j] == 2) { //Quando a função para sortear a posição do submarino for usada, terá o valor de 2, apresentado o caracter 'S'.
                    printf("S  ");
                }
                else{ //Se não tiver nenhum submarino ou couraçado, será apresentado apenas um '.'
                    printf(".  ");
                }
        }
        printf("\n");
        aux++;
    }
}
//Função para sortear a linha e coluna do submarino
void randlinhacoluna() {
    int *rlinha = 0,
        *rcoluna = 0;
    rlinha = &randlinha;
    rcoluna = &randcoluna;
    //Estrutura de repetição para limpar a antiga posição do submarino
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(Oceano[i][j] == 2) {  
                Oceano[i][j] = 0;
            }
        }
    }
    //Processamento para sortear a posição nova do submarino
    srand(time(NULL));
    *rlinha = rand() % 3;
    *rcoluna = rand() % 3;
    Oceano[randlinha][randcoluna] = 2; //A nova posição do submarino dentro da matriz do Oceano terá o valor de 2
}
//Função para limpar o Oceano, deixando todos os valores da matriz = 0.
void limpaOceano() {
    int i = 0, j = 0;
    for(i = 0; i < 3; i++) {
        for(j = 0; j < 3; j++) {
            Oceano[i][j] = 0;
        }
    }
}