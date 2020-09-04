/*********************************************************************************
* BATALHA NAVAL
*********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

#define clear() printf("\033[H\033[J")

/*******************************************************************************
* FUNÇÃO PARA PREENCHER O TABULEIRO COM AGUA
*******************************************************************************/	
void preenchetabuleiro(char *tabuleiro1, char *tabuleiro2, int tam){
	int i, j;
	for(i = 0; i < tam; i++){
		tabuleiro1[i] = '-';
		tabuleiro2[i] = '-';
	}
}

/*******************************************************************************
* FUNÇÃO PARA IMPRIMIR O TABULEIRO
*******************************************************************************/	
void imprimetabuleiro(char tabuleiro[][25]){
	int i, j;
	printf("    1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25\n");
	printf("______________________________________________________________________________\n");
	for(i = 0; i < 10; i++){
		if(i == 9){
			printf("%d| ", i+1);
		} else {
			printf("%d | ", i+1);
		}
		
		for(j = 0; j < 25; j++){
			printf("%c  ", tabuleiro[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

/*******************************************************************************
* FUNÇÃO PARA COLOCAR OS NAVIOS NO TABULEIRO
*******************************************************************************/	
void colocandonavios(char *tabuleiro1, int semente){
	int i, aux, cont;
	srand(semente + time(NULL));
	
	// COLOCANDO OS SUBMARINOS NO TABULEIRO
	cont = 0;
	i = 0;
	while(cont < 5){
		aux = rand() % 250;
		if(tabuleiro1[aux] == '-' && tabuleiro1[aux-1] == '-' && tabuleiro1[aux+1] == '-'){
			tabuleiro1[aux] = 'X';
			cont = cont + 1;
		}
	}
	
	// COLOCANDO OS HIDROAVIOES
	cont = 0;
	i = 0;
	while(cont < 4){
		aux = rand() % 250;
		if(aux != 24 && aux != 49 && aux != 74 && aux != 99 && aux != 124 && aux != 149 && aux != 174 && aux != 199 && aux != 224 && aux != 249){
			if(tabuleiro1[aux] == '-' && tabuleiro1[aux-1] == '-'){
				if(tabuleiro1[aux+1] == '-' && tabuleiro1[aux+1] == '-'){
					tabuleiro1[aux] = 'X';
					tabuleiro1[aux+1] = 'X';
					cont = cont + 1;
				}
			}
		}
	}
	
	// COLOCANDO OS CRUZADORES
	cont = 0;
	i = 0;
	while(cont < 3){
		aux = rand() % 250;
		if(aux != 24 && aux != 23 && aux != 49 && aux != 48 && aux != 74 && aux != 73 && aux != 99 && aux != 98 && aux != 124 && aux != 123 && aux != 149 && aux != 148 && aux != 174 && aux != 173 && aux != 199 && aux != 198 && aux != 224 && aux != 223 && aux != 249 && aux != 248){
			if(tabuleiro1[aux] == '-' && tabuleiro1[aux-1] == '-'){
				if(tabuleiro1[aux+1] == '-'){
					if(tabuleiro1[aux+2] == '-' && tabuleiro1[aux+3] == '-'){
						tabuleiro1[aux] = 'X';
						tabuleiro1[aux+1] = 'X';
						tabuleiro1[aux+2] = 'X';	
						cont = cont + 1;
					}
				}
			}
		}
	}
	
	// COLOCANDO OS ENCOURACADORES
	cont = 0;
	i = 0;
	while(cont < 2){
	aux = rand() % 250;
		if(aux != 24 && aux != 23 && aux != 22 && aux != 49 && aux != 48 && aux != 47 && aux != 74 && aux != 73 && aux != 72 && aux != 99 && aux != 98 && aux != 97 && aux != 124 && aux != 123 && aux != 122 && aux != 149 && aux != 148 && aux != 147 && aux != 174 && aux != 173 && aux != 172 && aux != 199 && aux != 198 && aux != 197 && aux != 224 && aux != 223 && aux != 222 && aux != 249 && aux != 248 && aux != 247){
			if(tabuleiro1[aux] == '-' && tabuleiro1[aux-1] == '-'){
				if(tabuleiro1[aux+1] == '-'){
					if(tabuleiro1[aux+2] == '-'){
						if(tabuleiro1[aux+3] == '-' && tabuleiro1[aux+4] == '-'){
							tabuleiro1[aux] = 'X';
							tabuleiro1[aux+1] = 'X';
							tabuleiro1[aux+2] = 'X';
							tabuleiro1[aux+3] = 'X';	
							cont = cont + 1;
						}
					}
				}
			}
		}
	}
	
	// COLOCANDO OS PORTA-AVIOES
	cont = 0;
	i = 0;
	while(cont < 1){
		aux = rand() % 250;
		if(aux != 24 && aux != 23 && aux != 22  && aux != 21 && aux != 49 && aux != 48 && aux != 47 && aux != 46 && aux != 74 && aux != 73 && aux != 72  && aux != 71 && aux != 99 && aux != 98 && aux != 97 && aux != 96 && aux != 124 && aux != 123 && aux != 122 && aux != 121 && aux != 149 && aux != 148 && aux != 147 && aux != 146 && aux != 174 && aux != 173 && aux != 172 && aux != 171 && aux != 199 && aux != 198 && aux != 197 && aux != 196 && aux != 224 && aux != 223 && aux != 222 && aux != 221 && aux != 249 && aux != 248 && aux != 247 && aux != 246){
			if(tabuleiro1[aux] == '-' && tabuleiro1[aux-1] == '-'){
				if(tabuleiro1[aux+1] == '-'){
					if(tabuleiro1[aux+2] == '-'){
						if(tabuleiro1[aux+3] == '-'){
							if(tabuleiro1[aux+4] == '-' && tabuleiro1[aux+5] == '-'){
								tabuleiro1[aux] = 'X';
								tabuleiro1[aux+1] = 'X';
								tabuleiro1[aux+2] = 'X';
								tabuleiro1[aux+3] = 'X';
								tabuleiro1[aux+4] = 'X';	
								cont = cont + 1;
							}
						}
					}
				}
			}
		}
	}
}

/*******************************************************************************
* FUNÇÃO PARA CONFERIR SE O TIRO DO PLAYER É VÁLIDO
*******************************************************************************/	
void conferetiroplayer(int i, int j, char *player, char *tabuleiro2, int *contadorplayer){
	int auxi, auxj;
	auxi = i;
	auxj = j;
	
	// CONFERINDO SE O LOCAL JÁ RECEBEU UM TIRO
	if(tabuleiro2[((auxi-1)*25)+(auxj-1)]=='T' ||tabuleiro2[((auxi-1)*25)+(auxj-1)] == 'X'){
		printf("Esse local ja recebeu um tiro, entre com as coordenadas novamente\nLinha: ");
		scanf("%d", &auxi);
		printf("Coluna: ");
		scanf("%d", &auxj);
	}
	
	// CONFERINDO SE A COORDENADA É INVALIDA
	while(auxi>10 || auxj >25){
		printf("Coordenadas invalidas, entre com as coodernadas certas\nLinha: ");
		scanf("%d", &auxi);
		printf("Coluna: ");
		scanf("%d", &auxj);
	}
	
	// CONFERINDO SE A COORDENADA TEM UM BARCO
	// MARCANDO NO TABULEIRO ONDE FOI O TIRO
	if(player[((auxi-1)*25)+auxj] == 'X'){
		tabuleiro2[((auxi-1)*25)+(auxj-1)] = 'X';
		*contadorplayer = *contadorplayer + 1;
	}else{
		tabuleiro2[((auxi-1)*25)+(auxj-1)] = 'T';
	}
}

/*******************************************************************************
* FUNÇÃO PARA CONFERIR SE O TIRO DO COMPUTADOR É VÁLIDO
*******************************************************************************/	
void conferetiropc(char *computer, char *tabuleiro2, int *contadorpc, int *ia, int *aux1){
	int auxi;
	
	// IA = INTELIGENCIA ARTIFICIAL
	if(*ia == 0){
		srand(time(NULL));
	
		 // CONFERINDO SE O LOCAL JA RECEBEU UM TIRO
		do {
			auxi = rand() % 250;
		} while(tabuleiro2[auxi] == 'T' ||tabuleiro2[auxi] == 'X');

		// CONFERINDO SE O LUGAR SORTEADO TEM UM NAVIO
		// MARCANDO NO TABULEIRO ONDE FOI O TIRO
		if(computer[auxi] == 'X'){
			tabuleiro2[auxi] = 'X';
			contadorpc = contadorpc + 1;
			*ia = 1;
			printf("%d", *ia);
			*aux1 = auxi;
			return ;
		} else {
			tabuleiro2[auxi] = 'T';
			*ia = 0;
			return ;
		}
	}
	
	// INTELIGENCIA ARTIFICIAL DO COMPUTADOR
	// TESTAR OS LOCAIS A FRENTE DO PRIMEIRO TIRO SE TEM EMBARCAÇÃO
	if(*ia == 1){
		auxi = *aux1;
		if(computer[auxi+1] == 'X'){
			tabuleiro2[auxi+1] = 'X';
			contadorpc = contadorpc + 1;
			*ia = *ia + 1;
			return ;
		} else {
			tabuleiro2[auxi+1] = 'T';
			*ia = -1;
			return ;
		}
	}

	if(*ia == 2){
		auxi = *aux1;
		if(computer[auxi+2] == 'X'){
			tabuleiro2[auxi+2] = 'X';
			contadorpc = contadorpc + 1;
			*ia = *ia + 1;
			return ;
		} else {
			tabuleiro2[auxi+2] = 'T';
			*ia = -1;
			return ;
		}
	}

	if(*ia == 3){
		auxi = *aux1;
		if(computer[auxi+3] == 'X'){
			tabuleiro2[auxi+3] = 'X';
			contadorpc = contadorpc + 1;
			*ia = *ia + 1;
			return ;
		} else {
			tabuleiro2[auxi+3] = 'T';
			*ia = -1;
			return ;
		}
	}

	if(*ia == 4){
		auxi = *aux1;
		if(computer[auxi+4] == 'X'){
			tabuleiro2[auxi+4] = 'X';
			contadorpc = contadorpc + 1;
			*ia = *ia + 1;
			return ;
		} else {
			tabuleiro2[auxi+4] = 'T';
			*ia = 0;
			return ;
		}
	}
	
	// TESTAR OS LOCAiS ATRAS DO PRIMEIRO TIRO SE TEM EMBARCAÇÕES
	if(*ia == -1){
		auxi = *aux1;
		if(computer[auxi-1] == 'X'){
			tabuleiro2[auxi-1] = 'X';
			contadorpc = contadorpc + 1;
			*ia = *ia - 1;
			return ;
		} else {
			tabuleiro2[auxi-1] = 'T';
			*ia = 0;
			return ;
		}
	}

	if(*ia == -2){
		auxi = *aux1;
		if(computer[auxi-2] == 'X'){
			tabuleiro2[auxi-2] = 'X';
			contadorpc = contadorpc + 1;
			*ia = *ia - 1;
			return ;
		} else {
			tabuleiro2[auxi-2] = 'T';
			*ia = 0;
			return ;
		}
	}

	if(*ia == -3){
		auxi = *aux1;
		if(computer[auxi-3] == 'X'){
			tabuleiro2[auxi-3] = 'X';
			contadorpc = contadorpc + 1;
			*ia = *ia - 1;
			return ;
		} else {
			tabuleiro2[auxi-3] = 'T';
			*ia = 0;
			return ;
		}
	}

	if(*ia == -4){
		auxi = *aux1;
		if(computer[auxi-4] == 'X'){
			tabuleiro2[auxi-4] = 'X';
			contadorpc = contadorpc + 1;
			*ia = *ia - 1;
			return ;
		} else {
			tabuleiro2[auxi-4] = 'T';
			*ia = 0;
			return ;
		}
	}
}

/*******************************************************************************
* FUNÇÃO MAIN
*******************************************************************************/	
int main(){
	setlocale(LC_ALL, "Portuguese");

	// DEFINIÇÃO DAS VARIAVEIS
	char tabuleiro1[10][25], tabuleiro2[10][25], computer[10][25], player[10][25], nomeplayer[15];
	int contadorpc = 0, contadorplayer = 0, i, j, ia = 0, aux1 = 0;
	
	// PREENCHENDO O TABULEIRO DA IMPRESSAO COM AGUA
	// PREENCHENDO O TABULEIRO DOS NAVIOS COM AGUA
	preenchetabuleiro(&tabuleiro1[0][0], &tabuleiro2[0][0], 10*25);
	preenchetabuleiro(&computer[0][0], &player[0][0], 10*25);

	// COLOCANDO OS NAVIOS NOS TABULEIROS
	colocandonavios(&computer[0][0], 0);
	colocandonavios(&player[0][0], 5);
	
	// IMPRESSAO DOS TABULEIROS, LEGENDA DO JOGO
	printf("\t\t\t\tBATALHA NAVAL\n\n");
	printf("\tCOMPUTER\n");
	imprimetabuleiro(tabuleiro1);
	printf("\tPLAYER\n");
	imprimetabuleiro(tabuleiro2);
	printf("Legenda \na= agua \nT= tiro na agua \nX= embarcacao atingida\n\n");

	// LOOP DA EXECUÇÃO DO PROGRAMA
	do{
		
		// TIRO DO PLAYER
		printf("Digite as cordenadas do tiro\nLinha: ");
		scanf("%d", &i);
		printf("Coluna: ");
		scanf("%d", &j);
		conferetiroplayer(i, j, &player[0][0], &tabuleiro2[0][0], &contadorplayer);
		
		// TIRO DO COMPUTADOR
		conferetiropc(&computer[0][0], &tabuleiro1[0][0], &contadorpc, &ia, &aux1);
		
		// LIMPA A JANELA A CADA JOGADA, TÍTULO DO JOGO, IMPRESSAO DOS TABULEIROS, LEGENDA
		clear();
		printf("\t\t\t\tBATALHA NAVAL\n\n");
		printf("\tPLAYER\n");
		imprimetabuleiro(tabuleiro1);
		printf("\tCOMPUTER\n");
		imprimetabuleiro(tabuleiro2);
		printf("Legenda \n-= agua \nT= tiro na agua \nX= embarcacao atingida\n\n");
		
		// CONFERENCIA DO GANHADOR
		if(contadorplayer == 35 || contadorpc == 35){
			break;
		}
	}while(1);
	
	// AVISO DO VENCEDOR DO JOGO
	if(contadorplayer == 35){
		printf("\n\n\n\t\t\tVOCe VENCEU !!!!!");
	} else {
		printf("\n\n\n\t\t\tVOCE PERDEU !!!!!");
	}
	return 0;
}
