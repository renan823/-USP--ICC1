#include <stdio.h>
#include <stdlib.h>

//documentacao externa no git??
//fazer documentacao interna!!!!
/*
Divisão da memoria ram:
- Stack
- Heap
- Dados
- Codigo

O S.O. define quanto de memoria tem em cada pedaco

As variaveis globais/defines ficam na parte "dados", enqt o programa roda na parte "codigo"
"heap" eh a memoria livre para alocacao
"stack" armazena funcoes, parametros de funcao e variaveis locais - "stack" aumenta do endereco maior para o menor
para evitar espacos vagos na memoria, a "stack" cresce de cima para baixo, otimizando o armazenamento
quando a "stack" ultrapassa o limite da heap ocorre o stack overflow (estou da pilha) - que ocorre 
quando muitas funcoes sao chamadas sem terem terminado outras

Alocar memoria eh obter memoria DURANTE a execucao
A memoria alocada dinamicamente vem da "heap"

funcoes para alocacao vem da <stdlib.h>
- calloc() e malloc() criam espaco na memoria
- free() libera o espcao alocado com malloc() ou calloc()
- realloc() realoca espaco previamente alocados (por exemplo transferir para uma area maior da memoria)

usou memoria e nao devolveu? memory leak 
seria esse o garbage collector?

ponteiro null -> aponta pra lugar nenhum
ponteiro void -> ponteiro sem tipo (aponta para qualquer tipo, ate ser definido)

**CALLOC** - tentativa de alocar espaco

void* calloc(int n, size_t tam);

aloca espaco para "n" elementos que tem o tamanho "tam" bytes
deu certo? rzera todo o espaco de memoria e retorna um ponteiro void (apontando para o endereco alocado)
deu erro? retorna um ponteiro null

int *p;
p = (int*) calloc(1, sizeof(int)); -> aloca um int

int *p, n = 5;
p = (int*) calloc(5, sizeof(int)); -> aloca um vetor (eh continuo)
p[0] = 1; eh valido!

fazer o cast permite mais visibilidade!!!!


**MALLOC**

void* malloc(size_t tam)

aloca "tam" bytes de memoria 
diferentemente de calloc, malloc nao zera o espaco de memoria
deu certo? rzera todo o espaco de memoria e retorna um ponteiro void (apontando para o endereco alocado)
deu erro? retorna um ponteiro null
malloc eh mais rapido que calloc

quando usar qual? depende do problema

int *p;
p = (int*) = malloc(sizeof(int)); -> aloca um int

int *p, n = 5;
p = (int*) = malloc(n * sizeof(int)); -> aloca um vetor

DEVE-SE VERIFICAR SE DEU CERTO A ALOCACAO!!!

if((p = (int*) malloc(12)) == NULL) {
	printf("Sem memoria\n");
	exit(1);
}

**FREE** 

void* free(void *prt)

liberar espaco de memoria alocado pelo malloc/calloc
a memoria deve ser explicitamente devolvida ao S.O
EH BOA PRATICA LIBERAR MEMORIA DE CADA PONTEIRO NAO UTILIZADO MAIS!!!!


**REALLOC**
tenta redimensionar um ptr previamente alocado

void *realloc(void *ptr, size_t size);

a funcao procura um lugar na memoria, aloca o local, copia os dados anteriores
EH MUITO CUSTOSO!!!!

se um realloc retornar nulo, se *ptr for utilizado, O VETOR ANTERIOR SE TORNA NULO

int p [12];

if ((p = (int*) realloc(p, 12*sizeof(int) + (2*sizeof(int)))) = NULL) {
	se o realloc falhar, p se torna nulo e tudo eh perdido!!!!
}


ALOCAÇÃO DE MATRIZ

Para alocar a matriz, eh necessario criar um vetor de ponteiros, que irão apontar para outros ponteiros

cada indice p eh outro ponteiro (vetor), logo, eh um vetor de ponteiros 

Para desalocar, eh necessario primeiro desalocar cada vetor, para depois desalocar a 
matriz (os ponteiros para ponteiros)
*/




int main (void) {
	return (0);
}