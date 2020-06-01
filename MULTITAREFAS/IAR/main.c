#include <stdint.h>
#include <stdio.h>

#include "multitarefas.h"

/*
 * Prototipos das tarefas
 */
void tarefa_1(void);
void tarefa_2(void);
void tarefa_3(void);
void tarefa_4(void);
void tarefa_5(void);
void tarefa_Soma(void);


/*
 * Configuracao dos tamanhos das pilhas
 */
#define TAM_PILHA_1		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_2		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_3		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_4		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_5		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_6		(TAM_MINIMO_PILHA + 24)
#define TAM_PILHA_OCIOSA	(TAM_MINIMO_PILHA + 24)



/*
 * Declaracao das pilhas das tarefas
 */
uint32_t PILHA_TAREFA_1[TAM_PILHA_1];
uint32_t PILHA_TAREFA_2[TAM_PILHA_2];
uint32_t PILHA_TAREFA_3[TAM_PILHA_3];
uint32_t PILHA_TAREFA_4[TAM_PILHA_4];
uint32_t PILHA_TAREFA_5[TAM_PILHA_5];
uint32_t PILHA_TAREFA_6[TAM_PILHA_6];
uint32_t PILHA_TAREFA_OCIOSA[TAM_PILHA_OCIOSA];

// Contadores

uint16_t a = 0;
uint16_t b = 0;
uint16_t c = 0;
uint16_t d = 0;
uint16_t e = 0;



/*
 * Funcao principal de entrada do sistema
 */
int main(void)
{
	
	/* Criacao das tarefas */
	/* Parametros: ponteiro, nome, ponteiro da pilha, tamanho da pilha, prioridade da tarefa */
	
	CriaTarefa(tarefa_1, "T1", PILHA_TAREFA_1, TAM_PILHA_1, 1, PRONTA);
	
	CriaTarefa(tarefa_2, "T2", PILHA_TAREFA_2, TAM_PILHA_2, 2, SUSPENSA);
        
        CriaTarefa(tarefa_3, "T3", PILHA_TAREFA_3, TAM_PILHA_3, 3, SUSPENSA);
        
        CriaTarefa(tarefa_4, "T4", PILHA_TAREFA_4, TAM_PILHA_4, 4, SUSPENSA);
        
        CriaTarefa(tarefa_5, "T5", PILHA_TAREFA_5, TAM_PILHA_5, 5, SUSPENSA);
        
        CriaTarefa(tarefa_Soma, "SomaCount", PILHA_TAREFA_6, TAM_PILHA_6, 6, PRONTA);
	
	/* Cria tarefa ociosa do sistema */
	CriaTarefa(tarefa_ociosa,"Tarefa ociosa", PILHA_TAREFA_OCIOSA, TAM_PILHA_OCIOSA, 0, PRONTA);
	
	/* Configura marca de tempo */
	ConfiguraMarcaTempo();   
	
	/* Inicia sistema multitarefas */
	IniciaMultitarefas();
	
	/* Nunca chega aqui */
	while (1)
	{
	}
}


/* Tarefas de exemplo que usam funcoes para suspender/continuar as tarefas */
void tarefa_1(void)
{
    	//volatile uint16_t a = 0;
	for(;;)
	{
		a++;
                
		TarefaContinua(2); // ativa mas não troca contexto
                TarefaSuspende(1); // suspende e troca contexto
	
	}

}

void tarefa_2(void)
{
  	//volatile uint16_t b = 0;
	for(;;)
	{
		b++;
		TarefaContinua(3);  // ativa mas não troca contexto
                TarefaSuspende(2); // suspende e troca contexto
	
	}

}

void tarefa_3(void)
{
  	//volatile uint16_t c = 0;
	for(;;)
	{
		c++;
		TarefaContinua(4);  // ativa mas não troca contexto
                TarefaSuspende(3); // suspende e troca contexto
	
	}

}

void tarefa_4(void)
{
  	//volatile uint16_t d = 0;
	for(;;)
	{
		d++;
		TarefaContinua(5);  // ativa mas não troca contexto
                TarefaSuspende(4); // suspende e troca contexto
	
	}

}

void tarefa_5(void)
{
  	//volatile uint16_t e = 0;
	for(;;)
	{
		e++;
		TarefaContinua(1);  // ativa mas não troca contexto
                TarefaSuspende(5); // suspende e troca contexto
	
	}

}

void tarefa_Soma(void)
{             
          uint32_t sum;
          TarefaEspera(30);
          sum = a+b+c+d+e;
}


