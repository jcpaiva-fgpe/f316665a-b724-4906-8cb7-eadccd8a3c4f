/*
 * mainCompra.c
 *
 *  Created on: Apr 23, 2016
 *      Author: cpm
 */

#include <stdio.h>

#define MAXMOEDA 8
#define EUROS2CENT 100
#define MAXLINHA 20

void escreve(int* v, int cont){
	int i=0;
	for(;i<cont-1;i++)
		printf("%d ",v[i]);
	printf("%d\n",v[cont-1]);
}

void calculaTroco(int cent,int *troco, int * valores,int cont){
	int i=0;
	while ((cent > 0) && (i<cont)){
		troco[i] = cent / valores[i];
		cent = cent % valores[i];
		i++;
	}
}

int main(void){
	int euros,cent,i=0,d=0;
	int moedas[MAXMOEDA];
	int valores[MAXMOEDA]={200,100,50,20,10,5,2,1};
	int troco[MAXMOEDA]={0,0,0,0,0,0,0,0};
	char linha[MAXLINHA];

	fgets(linha,MAXLINHA-1,stdin);
	sscanf(linha,"%d %d",&euros,&cent);
	euros = euros*EUROS2CENT+cent;
	for(;i<MAXMOEDA;i++){
		scanf("%d",&moedas[i]);
		d= d+ valores[i]*moedas[i];
	}

	if (d<euros)
		escreve(moedas,MAXMOEDA);
	else{
		calculaTroco(d-euros,troco,valores,MAXMOEDA);
		escreve(troco,MAXMOEDA);
	}
	return 0;
}
