
/*
	programador: Jivaldo Da Cruz
	titulo: Tradução de verbo em ing/port
	feito: 11/07/2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 200

//Variáveis global
int x, y, tenta, cont = 0;
int main(void);

//############################################
//Função Principal
int main(void){
	system("clear || cls");
	printf("########################################################\n\n");
	printf("                Bem-Vindo a Verbo Ing             \n\n");
	printf("########################################################\n\n");
	printf("1. - Portugues -> Ingles.\n2. - Ingles -> Portugues.\n3. - Adicionar palavras\n4. - Para sair.\n");
	int opcao;
	printf("Insira uma opcao: ");
	scanf("%d",&opcao);
	if(opcao == 1){
		void porting(void);
		porting();
		system("clear || cls");
	}else if(opcao == 2){
		void ingport(void);
		ingport();
		system("clear || cls");
	}else if(opcao == 3){
		void adicionar(void);
		adicionar();
		system("clear || cls");
	}else if(opcao == 4){
		system("clear || cls");
		printf("########################################################\n\n");
		printf("                Obrigado pela visita!             \n\n");
		printf("########################################################\n\n");
	}else{
		main();
	}
	
	getchar();
	getchar();
	return 0;
}

//############################################
//Função para saber verbo de português para inglês
void porting(void){
	
	char portu[size];
	char buscaPort[50][size];
	char buscaIng[50][size];
	char tamanho[50][size];

	FILE *arquivoPort, *arquivoIng, *arquivoTamanho;
	arquivoPort = fopen("port.txt", "r");
	arquivoIng = fopen("ing.txt", "r");
	arquivoTamanho = fopen("port.txt", "r");

	if(arquivoPort == NULL){
		system("clear || cls");
		printf("Nao existe nenhum base de dados!\nEntre depois do algoritmo fechar e cadastra palavras.\n");
	}

	while( !feof(arquivoTamanho) ){
		fscanf(arquivoTamanho, "%s", tamanho[cont]);
		cont++;
	}
	
	do{	
	printf("Insira uma palavra: ");
	scanf("%s", &portu);
	for(x = 0, y = 0; y < cont, x < cont; x++, y++){
		fscanf(arquivoPort, "%s", buscaPort[x]);
		fscanf(arquivoIng, "%s", buscaIng[y]);
		if(strcmp(portu,buscaPort[x]) == 0){
			printf("A traducao de %s para o ingles eh %s.\n", portu, buscaIng[y]);
		}
	}
		printf("Insira 1 para continuar e 0 para sair: ");
		scanf("%d", &tenta);
		system("clear || cls");
		printf("########################################################\n\n");
		printf("                Bem-Vindo a Verbo Ing             \n\n");
		printf("########################################################\n\n");
	}while(tenta == 1);
	fclose(arquivoPort);
	fclose(arquivoIng);
	fclose(arquivoTamanho);
	system("clear || cls");
	main();
	printf("\a");
}

//############################################
//Função para saber verbo de inglês para português
void ingport(void){
	char ingl[size];
	char buscaPort[50][size];
	char buscaIng[50][size];
	char tamanho[50][size];

	FILE *arquivoPort, *arquivoIng, *arquivoTamanho;
	arquivoPort = fopen("port.txt", "r");
	arquivoIng = fopen("ing.txt", "r");
	arquivoTamanho = fopen("port.txt", "r");

	if(arquivoPort == NULL){
		system("clear || cls");
		printf("Nao existe nenhum base de dados!\nEntre depois do algoritmo fechar e cadastra palavras.\n");
	}

	while( !feof(arquivoTamanho) ){
		fscanf(arquivoTamanho, "%s", tamanho[cont]);
		cont++;
	}
	
	do{
		printf("White a word in ingles: ");
		scanf("%s", &ingl);
		for(x = 0, y = 0; x < cont, y < cont; x++, y++){
			fscanf(arquivoPort, "%s", buscaPort[x]);
			fscanf(arquivoIng, "%s", buscaIng[x]);
			if(strcmp(ingl,buscaIng[x]) == 0){
				printf("A traducao de %s para portugues eh %s.\n", ingl, buscaPort[x]);
			}
		}
		printf("Insira 1 para continuar e 0 para sair: ");
		scanf("%d", &tenta);
		system("clear || cls");
		printf("########################################################\n\n");
		printf("                Bem-Vindo a Verbo Ing             \n\n");
		printf("########################################################\n\n");
	}while(tenta == 1);
	fclose(arquivoPort);
	fclose(arquivoIng);
	fclose(arquivoTamanho);
	system("clear || cls");
	main();
}

//############################################
//Função para adicionar palavra
void adicionar(void){

	char addPort[50][size];
	char addIng[50][size];
	char add1[50][size];
	char add2[50][size];
	int add = 0, add_1 = 0;

	FILE *arquivoPort, *arquivoIng, *arquivoOut1, *arquivoOut2;
	arquivoPort = fopen("port.txt", "r");
	arquivoIng = fopen("ing.txt", "r");
	arquivoOut1 = fopen("port.txt", "ab+");
	arquivoOut2 = fopen("ing.txt", "ab+");

	if(arquivoPort == NULL){
		system("clear || cls");
		printf("Nao existe nenhum base de dados!\nEntre depois do algoritmo fechar e cadastra palavras.\n");
	}

	while( !feof(arquivoPort) ){
		fscanf(arquivoPort, "%s", addPort[add_1]);
		fscanf(arquivoIng, "%s", addIng[add_1]);
		if(add_1 == 1){
			fprintf(arquivoOut1, "Ser\n");
			fprintf(arquivoOut2, "Be\n");
		}
		add_1++;
	}

	printf("Insira verbo a portugues: ");
	scanf("%s",&add1);
	printf("Insira verbo a ingles: ");
	scanf("%s",&add2);
	
	for(; add < 1; add++){
		if( strcmp(add1[add],addPort[add]) != 0){
			fprintf(arquivoOut1, "%s\n", add1);
			fprintf(arquivoOut2, "%s\n", add2);
		}
	}
	printf("Adicionado com exito!\n");
	getchar();
	getchar();
	fclose(arquivoPort);
	fclose(arquivoIng);
	fclose(arquivoOut1);
	fclose(arquivoOut2);
	main();
}