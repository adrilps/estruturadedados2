#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hash.h"
#include "avl.h"
#include "hashEncadeada.h"

int executarAvl(FILE* entrada);
int executarHash(FILE* entrada);
int executarHashEncadeada(FILE* entrada);

int main() {

	//lendo arquivo de entrada
	FILE* entrada = fopen("in.txt", "r");

	int comparacoesHash = executarHash(entrada);
	int comparacoesHashEncadeada = executarHashEncadeada(entrada);
	int comparacoesAvl = executarAvl(entrada);

	printf("comparaçoes hash: %d\n", comparacoesHash);
	printf("comparaçoes hash encadeada: %d\n",comparacoesHashEncadeada);
	printf("comparaçoes avl: %d\n", comparacoesAvl);

	return 0;
}

int executarHash(FILE* entrada) {
	
	clock_t tempoHash = clock();

	int qntComparacoes = 0;
	int posicoes = 8;
	int qnt = 0;
	
	//tabela hash
	Hash* tabela = (Hash*) malloc(sizeof(Hash) * posicoes);	
	
	inicializarTabela(tabela, posicoes);

	//chaves lidas do arquivo
	int chave = 0;

	//opçao de operaçao: i - inserir e b - buscar
	char op;

	while(fscanf(entrada, "%c %d\n", &op, &chave) != EOF) {

		if(op == 'i') {

			inserirElemento( chave, tabela, posicoes, &qnt );
			tabela = calcularCarga( tabela, &qnt, &posicoes);
			
		} else if(op == 'b'){

			buscarElemento(chave, tabela, posicoes, &qntComparacoes);
			tabela = calcularCarga( tabela, &qnt, &posicoes);
		}
	}

	//abrindo arquivo hash.txt de saida
	FILE* saida = fopen("hash.txt", "w");

	//imprimindo tabela Hash no arquivo de saida

	tempoHash = clock() - tempoHash;
	
	double tempoFinal = ((double)tempoHash)/CLOCKS_PER_SEC;

	fprintf(saida, "tempo: %f\n", tempoFinal);

	imprimirTabela(tabela, posicoes, saida, qntComparacoes);
	
	return qntComparacoes;

};

int executarHashEncadeada(FILE* entrada) {

	rewind(entrada);

	clock_t tempoHashEncadeada = clock();
	
	int qntComparacoes = 0;
	
	//tabela hash
	Encad* tabela = (Encad*) malloc(sizeof(Encad) * 100);	
	
	inicializarTabelaE(tabela);

	//chaves lidas do arquivo
	int chave = 0;

	//opçao de operaçao: i - inserir e b - buscar
	char op;

	while(fscanf(entrada, "%c %d\n", &op, &chave) != EOF) {

		if(op == 'i') {

			inserirElementoE(chave, tabela);
			
		} else if(op == 'b'){

			buscarElementoE(chave, tabela, &qntComparacoes);
		}
	}

	//abrindo arquivo hash.txt de saida
	FILE* saida = fopen("hashEncadeada.txt", "w");

	//imprimindo tabela Hash no arquivo de saida

	tempoHashEncadeada = clock() - tempoHashEncadeada;

	double tempoFinal = ((double)tempoHashEncadeada)/CLOCKS_PER_SEC;

	fprintf(saida, "tempo: %f\n", tempoFinal);

	imprimirTabelaE(tabela, saida, qntComparacoes);

	
	return qntComparacoes;
};

int executarAvl(FILE* entrada) {

	rewind(entrada);

	clock_t tempoAvl = clock();
	
	int qntComparacoes = 0;
	
	//avl
	Nodo* raiz = NULL;

	//chaves lidas do arquivo
	int chave = 0;

	//opçao de operaçao: i - inserir e b - buscar
	char op;

	while(fscanf(entrada, "%c %d\n", &op, &chave) != EOF) {

		if(op == 'i') {

			raiz = inserirNodo(raiz, chave);
			raiz = balancear(raiz);
			
		} else if(op == 'b') {

			buscarNodo(raiz, chave, &qntComparacoes);
			raiz = balancear(raiz);
		}
	}

	//abrindo arquivo avl.txt de saida
	FILE* saida = fopen("avl.txt", "w");

	//imprimindo avl em ordem no arquivo de saida

	tempoAvl = clock() - tempoAvl;

	double tempoFinal = ((double)tempoAvl)/CLOCKS_PER_SEC;

	fprintf(saida, "tempo: %f\n", tempoFinal);

	imprimirArvore(raiz, saida);

	
	return qntComparacoes;
};