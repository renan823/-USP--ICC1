#include <stdio.h>
#include<stdlib.h>

/*
Duvida 1:
Como alocar uma struct cujo elemento "x" venha de uma alocação dinâmica?
Nesse caso, eu tentei o sizeof, mas não estava funcionando.
No struct Pessoa2, o sizeof funciona, uma vez que defini o tamanho dos vetores.
Mas, pré-definir esse tamanho para os vetores não iria contra a parte de 
"use alocação dinâmica" ? 
Caso isso não possa ser feito, como deveria ser feito para alocar essa struct Pessoa1?
*/

typedef struct {
    char *nome;
    char *sobrenome;
} Pessoa1;

typedef struct {
    char nome[50];
    char sobrenome[50];
} Pessoa2;

R.:
Pessoa1 *p1;

p1 = (Pessoa1 *) malloc(sizeof(Pessoa1)*tamanho);
p1->nome = (char *) malloc(sizeof(char)*tamanho da string);
strcpy(p1[0].nome, "Nome");


Pessoa2 *p2;
p2 = (Pessoa2 *) malloc(sizeof(Pessoa2)*tamanho);
strcpy(p2[0].nome,"Nome");



/*
Duvida 2:
No trabalho, optei por realizar as operações diretamente no arquivo, sem um vetor auxiliar para isso.
Então, sempre que é necessário manipular (adicionar, editar, etc) uma reserva, o arquivo é aberto,
a operação é realizada e o arquivo (alterado ou não) é fechado.
Esse modo é considerado correto? Ou deveria ter um vetor de reservas que guarda tudo, sendo 
descarregado no arquivo somente quando o dia é encerrado?
*/

int main (void) {
    return (0);
}

R.: Arquivos (e seus dados) devem sempre ser carregados para a memória. O acesso a disco
é muito mais lento/caro! Então, abre o arquivo (carrega na memória, usando as 
    estruturas/variáveis necessárias), processa tudo o que precisar, fecha 
    somente quando não precisar mais do arquivo. No caso do projeto, no fechamento
    do dia e/ou voo. 

/*
Duvida 3 (e última, prometo):
Como padrão de projeto, optei por criar structs bem definidos para os tipos,
tendo Aviao, Voo, Pessoa e Reserva. (exemplo abaixo).
Então, coloquei alguns structs como atributo de outra struct.
Esse padrão de projeto foi baseado no meu conhecimento sobre POO,
logo, não sei se é algo aceitável em C ou se estou totalmente errado.
*/

typedef struct {
    int capacidade;
    float executiva;
    float economica;
} Aviao;

typedef struct Voo {
    char id[5];
    char data[11];
    char localPartida[5];
    char localChegada[5];
} Voo;

typedef struct {
    char nome[50];
    char sobrenome[50];
    char cpf[15];
} Pessoa;

typedef struct {
    Pessoa pessoa;
    Voo voo;
    char assento[5];
    char classe[10];
    float valor;
} Reserva;

R.: Tudo certo. O que você fez chama-se modelagem dos dados. Cada grupo
pessoa é responsável por sua modelagem. Existem várias possibilidades
corretas. Umas melhores que outras. 