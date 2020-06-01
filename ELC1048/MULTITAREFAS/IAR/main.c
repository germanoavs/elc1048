#include <stdint.h>
#include <stdio.h>

#include "multitarefas.h"

/*
 * Prototipos das tarefas
 */
void tarefa_Produtor(void);
void tarefa_Consumidor(void);

/*
 * Configuracao dos tamanhos das pilhas
 */
#define TAM_PILHA_1		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_2		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_OCIOSA	(TAM_MINIMO_PILHA + 24)

/*
 * Declaracao das pilhas das tarefas
 */
uint32_t PILHA_TAREFA_1[TAM_PILHA_1];
uint32_t PILHA_TAREFA_2[TAM_PILHA_2];
uint32_t PILHA_TAREFA_OCIOSA[TAM_PILHA_OCIOSA];

// Define buffer
#define TAM_BUFFER 10
uint8_t buffer[TAM_BUFFER]; /* declaracao de um buffer (vetor) ou fila circular */


// Semaforos para compartilhamento 
semaforo_t SemaforoCheio = {0,0}; /* declaracao e inicializacao de um semaforo */
semaforo_t SemaforoVazio = {TAM_BUFFER,0}; /* declaracao e inicializacao de um semaforo */

/*
 * Funcao principal de entrada do sistema
 */
int main(void)
{
	
	/* Criacao das tarefas */
	/* Parametros: ponteiro, nome, ponteiro da pilha, tamanho da pilha, prioridade da tarefa */
	
	CriaTarefa(tarefa_Produtor, "Tarefa Produtora", PILHA_TAREFA_1, TAM_PILHA_1, 2);
	
	CriaTarefa(tarefa_Consumidor, "Tarefa Consumidora", PILHA_TAREFA_2, TAM_PILHA_2, 1);
	
	/* Cria tarefa ociosa do sistema */
	CriaTarefa(tarefa_ociosa,"Tarefa ociosa", PILHA_TAREFA_OCIOSA, TAM_PILHA_OCIOSA, 0);
	
	/* Configura marca de tempo */
	ConfiguraMarcaTempo();   
	
	/* Inicia sistema multitarefas */
	IniciaMultitarefas();
	
	/* Nunca chega aqui */
	while (1)
	{
	}
}


void tarefa_Produtor(void)
{
	uint8_t a = 1;			
	uint8_t i = 0;
	
	for(;;)
	{
		SemaforoAguarda(&SemaforoVazio);
		
		buffer[i] = a++;
		i = (i+1)%TAM_BUFFER;
		
		SemaforoLibera(&SemaforoCheio); 
		
		TarefaEspera(10); 	
	}
}

void tarefa_Consumidor(void)
{
	static uint8_t f = 0;
	volatile uint8_t valor;
		
	for(;;)
	{
		
		SemaforoAguarda(&SemaforoCheio);
		
		valor = buffer[f];
		f = (f+1) % TAM_BUFFER;		
		
		SemaforoLibera(&SemaforoVazio);
	}
}
