#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_MAX_STRING 50

/*-----------------------------------------------------------------------------------
Declaração dos tipos usados no programa.
Os nomes são sugestivos às suas aplicações aqui usadas.
O tipo 'reserva' relaciona os tipos 'voo' e 'pessoa'.
-----------------------------------------------------------------------------------*/

typedef struct {
    int capacidade;
    float executiva;
    float economica;
} Aviao;

typedef struct Voo {
    char id[5];
    char data[11];
    char origem[4];
    char destino[4];
} Voo;

typedef struct {
    char *nome;
    char *sobrenome;
    char cpf[15];
} Pessoa;

typedef struct {
    Pessoa *pessoa;
    Voo *voo;
    char assento[5];
    char classe[10];
    float valor;
} Reserva;

typedef struct {
    int vendas, fechado;
    Aviao aviao;
} Cabecalho;

typedef struct {
    int tam_nome, tam_sobr;
} Separador;

/*-----------------------------------------------------------------------------------
Funções de utilidades (principalmente para alocação de memória 
e manipulação de arquivos).
Descrição específica em cada função.
-----------------------------------------------------------------------------------*/

/*
Aloca, dinamicamente, um vetor sem tipo.
O tamanho (em bytes) do vetor é definido pela multiplicação da quantidade de items e 
do tamanho (em bytes) dos items.
A quantidade de items e o tamanho são passados por parâmetro.
Se não houver memória para alocação, um erro é disparado.
Em caso de sucesso na alocação, o vetor é retornado.
*/
void *alocar (int quantidade, int tamanho) {
    void *vetor;

    if ((vetor = (void *) malloc(quantidade * tamanho)) == NULL) {
        printf("Erro: sem memória para alocar\n");
        exit(1);
    }

    return (vetor);
}

/*
Redimensiona um vetor/ponteiro.
Permite adicionar ou remover espaço.
O vetor, a quantidade de items e o tamanho do item são
passado svia parametro.
Se a realocação for bem sucedida, o vetor é retornado.
Senão, um erro é disparado.
*/
void *realocar (void *ponteiro, int quantidade, int tamanho) {
    if ((ponteiro = (void *) realloc(ponteiro, quantidade * tamanho)) == NULL) {
        printf("Erro: sem memória para alocar\n");
        exit(1);
    }

    return (ponteiro);
}

/*
Abre um arquivo.
O nome do arquivo e o modo (leitura, escrita, etc) são
passados por parametro.
Se o arquivo não for aberto, um erro é disparado.
Senão, o arquivo é retornado.
*/
FILE *abrirArquivo (char *nome, char *modo) {
	FILE *arquivo;

	if ((arquivo = fopen(nome, modo)) == NULL) {
		//printf("Erro: nenhum arquivo encontrado\n");
		//exit(1);
		return (NULL);
	}

	return (arquivo);
}

/* 
Grava todos os dados do programa para um arquivo binario.
A ordem de gravação é:
    - Cabeçalho: contém dados do aviao e total de vendas
    - Reservas
Para cada reserva, coloca-se no arquivo:
    - Reserva: dados da reserva
    - Voo: dados do voo
    - Pessoa: dados da pessoa
    - Separador: indica o tamanho da proximas strings
        a serem salvas (nome e sobrenome)
    -Nome e Sobrenome: salvos separadamente da pessoa

...A ordem se repete até o fim do vetor de reservas

Os ponteiros anteriormente alocados são liberados.
O vetor de reservas é liberado.
Nada é retornado.
*/
void gravarDados (Reserva **reservas, Aviao av, int tamanho, int fechado) {
    FILE *arquivo = abrirArquivo("dados.dat", "wb");

    Cabecalho c = { tamanho, fechado, av };
    fwrite(&c, sizeof(Cabecalho), 1, arquivo);

    Separador s;

    for (int i = 0; i < tamanho; i++) {
        fwrite(reservas[i], sizeof(Reserva), 1, arquivo);
        fwrite(reservas[i]->voo, sizeof(Voo), 1, arquivo);
        fwrite(reservas[i]->pessoa, sizeof(Pessoa), 1, arquivo);

        s.tam_nome = strlen(reservas[i]->pessoa->nome);
        s.tam_sobr = strlen(reservas[i]->pessoa->sobrenome);

        fwrite(&s, sizeof(Separador), 1, arquivo);

        fwrite(reservas[i]->pessoa->nome, sizeof(char), s.tam_nome, arquivo);
        fwrite(reservas[i]->pessoa->sobrenome, sizeof(char), s.tam_sobr, arquivo);

        free(reservas[i]->pessoa->nome);
        free(reservas[i]->pessoa->sobrenome);
        free(reservas[i]->pessoa);
        free(reservas[i]->voo);
        free(reservas[i]);
    }

    free(reservas);
}

/*
Lê os dados anteriormente salvos no arquivo "dados.dat" (binário)
*/
void lerDados (Reserva ***reservas, Aviao *av, int *tamanho, int *fechado) {
    FILE *arquivo = abrirArquivo("dados.dat", "rb");

    if (arquivo != NULL) {
        Cabecalho c;
        fread(&c, sizeof(Cabecalho), 1, arquivo);

        *tamanho = c.vendas;
        *fechado = c.fechado;

        Separador s;

        *reservas = (Reserva **) realocar(*reservas, (*tamanho), sizeof(Reserva *));

        for (int i = 0; i < *tamanho; i++) {
            Pessoa *p = alocar(1, sizeof(Pessoa));
            Voo *v = (Voo *) alocar(1, sizeof(Voo));
            Reserva *r = (Reserva *) alocar(1, sizeof(Reserva));

            fread(r, sizeof(Reserva), 1, arquivo);
            fread(v, sizeof(Voo), 1, arquivo);
            fread(p, sizeof(Pessoa), 1, arquivo);

            fread(&s, sizeof(Separador), 1, arquivo);

            p->nome = (char *) alocar(s.tam_nome, sizeof(char));
            fread(p->nome, sizeof(char), s.tam_nome, arquivo);

            p->sobrenome = (char *) alocar(s.tam_sobr, sizeof(char));
            fread(p->sobrenome, sizeof(char), s.tam_sobr, arquivo);

            r->pessoa = p;
            r->voo = v;

            *reservas[i] = r;
        }

        //printf("%s\n", (*reservas[0])->pessoa->nome);

        fclose(arquivo); 
    } 
}

/*-----------------------------------------------------------------------------------
Funções usadas de entrada /saída de dados.
Descrição específica em cada função.
-----------------------------------------------------------------------------------*/

/*
Exibe uma linha com 50 caracteres
*/
void linha () {
    printf("--------------------------------------------------\n");
}

/*
Permite a leitura de uma string.
O tamanho máximo da string é passado por parâmetro.
Inicializado com tamanho máximo, o ponteiro para char recebe a
entrada do usuário.
Em seguida, é removido o caracter '\n' (se existir).
Então, o ponteiro passa por uma realocação de memória,
ocupando apenas o espaço necessário para acomodar a string.
Se a realocação não for bem sucedida, um erro é mostrado.
Senão, a string é retornada.
*/
char *lerString (int tamanho) {
    char *string = (char *) alocar(tamanho, sizeof(char));

    scanf("%s", string);

    if (string[strlen(string) - 1] == '\n') {
        string[strlen(string) - 1] = '\0';
    }

    string = (char *) realocar(string, strlen(string), sizeof(char));

    return (string);
}

/*
Permite a leitura de datas.
O tamanho 11 acomoda a data e '\0' no final.
O programa recebe como entrada do usuário dia, mês e ano.
A entrada é processada de modo a formatar a data como
dd/mm/AAAA.
A data formatada é retornada.
*/
char *lerData () {
    char *data = (char *) alocar(11, sizeof(char));
    char temp;

    getc(stdin);
    for (int i = 0; i < 10; i++) {
        scanf("%c", &temp);

        if (temp == ' ') {
            temp = '/';
        }

        data[i] = temp;
    }
    data[10] = '\0';
    return (data);
}

Pessoa *lerPessoa () {
    Pessoa *p = (Pessoa *) alocar(1, sizeof(Pessoa));

    char *nome = lerString(TAM_MAX_STRING);
    char *sobrenome = lerString(TAM_MAX_STRING);

    p->nome = (char *) alocar(strlen(nome), sizeof(char));
    p->sobrenome = (char *) alocar(strlen(sobrenome), sizeof(char));

    strcpy(p->nome, nome);
    strcpy(p->sobrenome, sobrenome);
    strcpy(p->cpf, lerString(15));

    free(nome);
    free(sobrenome);

    return (p);
}

/*
Exibe os dados de uma reserva de modo formatado.
*/
void exibirReserva (Reserva *r) {
    printf("%s\n", r->pessoa->cpf);
    printf("%s %s\n", r->pessoa->nome, r->pessoa->sobrenome);
    printf("%s\n", r->voo->data);
    printf("Voo: %s\n", r->voo->id);
    printf("Assento: %s\n", r->assento);
    printf("Classe: %s\n", r->classe);
    printf("Trecho: %s %s\n", r->voo->origem, r->voo->destino);
    printf("Valor: %.2f\n", r->valor);
    linha();
}

/*
Exibe os dados do voo ao ser fechado.
Inclui a soma de todas as passagens vendidas.
*/
void exibirVoo (Reserva **reservas, int tamanho) {
    float total = 0;

    for (int i = 0; i < tamanho; i++) {
        total += reservas[i]->valor;

        printf("%s\n", reservas[i]->pessoa->cpf);
        printf("%s %s\n", reservas[i]->pessoa->nome, reservas[i]->pessoa->sobrenome);
        printf("%s\n\n", reservas[i]->assento);
    }

    printf("Valor Total: %.2f\n", total);
    linha();
}

/*-----------------------------------------------------------------------------------
Casos de uso.
Descrição específica em cada função.
-----------------------------------------------------------------------------------*/

Aviao aberturaVoo () {
    Aviao aviao;

    scanf("%d %f %f", &aviao.capacidade, &aviao.economica, &aviao.executiva);

    return (aviao);
}

void realizarReserva (Aviao a, Reserva ***reservas, int *tamanho) {
    Pessoa *p = lerPessoa();
    Voo *v = (Voo *) alocar(1, sizeof(Voo));
    Reserva *r = (Reserva *) alocar(1, sizeof(Reserva));

    strcpy(v->data, lerData());
    strcpy(v->id, lerString(5));
    strcpy(r->assento, lerString(5));
    strcpy(r->classe, lerString(10));
    scanf("%f", &r->valor);
    strcpy(v->origem, lerString(4));
    strcpy(v->destino, lerString(4));

    r->pessoa = p;
    r->voo = v;


    if ((*tamanho) == 0) {
        *reservas = (Reserva **) alocar(1, sizeof(Reserva *));
    } else {
        *reservas = (Reserva **) realocar(*reservas, (*tamanho)+1, sizeof(Reserva *));
    }

    *reservas[(*tamanho)] = r;
    (*tamanho)++;
}

void consultarReserva (Reserva **reservas, int tamanho) {
    char *cpf = alocar(15, sizeof(char));
    strcpy(cpf, lerString(15));

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(cpf, reservas[i]->pessoa->cpf) == 0) {
            exibirReserva(reservas[i]);
            break;
        }
    }

    free(cpf);
}

void modificarReserva (Reserva **reservas,  int tamanho) {
    char *cpf = alocar(15, sizeof(char));
    strcpy(cpf, lerString(15));

    Pessoa *p = lerPessoa();

    for (int i = 0; i < tamanho; i++) {
        if (strcmp(cpf, reservas[i]->pessoa->cpf) == 0) {
            free(reservas[i]->pessoa->nome);
            free(reservas[i]->pessoa->sobrenome);

            free(reservas[i]->pessoa);
            
            reservas[i]->pessoa = p;

            printf("Reserva Modificada:\n");
            exibirReserva(reservas[i]);
            break;
        }
    }

    free(cpf);
}

void cancelarReserva (Reserva ***reservas,  int *tamanho) {
    char *cpf = alocar(15, sizeof(char));
    strcpy(cpf, lerString(15));

    int pos = -1;

    for (int i = 0; i < *tamanho; i++) {
        if (strcmp(cpf, (*reservas[i])->pessoa->cpf) == 0) {
            free((*reservas[i])->pessoa->nome);
            free((*reservas[i])->pessoa->sobrenome);
            free((*reservas[i])->pessoa);
            free((*reservas[i])->voo);
            free(reservas[i]);
            
            pos = i;

            break;
        }
    }

    if (pos != -1) {
        for (int i = pos; i < ((*tamanho) - 1); i++) {
            (*reservas)[i] = (*reservas)[i+1];
        }

        (*tamanho)--;
        *reservas = (Reserva **) realocar(*reservas, (*tamanho), sizeof(Reserva *));

    } else {
        printf("Nenhuma reserva encontrada com %s!\n", cpf);
    }

    free(cpf);
}

void fecharDia (Reserva **reservas, int tamanho) {
    float total = 0;

    printf("Fechamento do dia: \n");
    printf("Quantidade de reservas: \n");

    for (int i = 0; i < tamanho; i++) {
        total += reservas[i]->valor;
    }

    printf("Posição: %.2f\n", total);
    linha();
}

void fecharVoo (Reserva **reservas, Aviao av, int tamanho) {
    printf("Voo fechado!\n\n");

    exibirVoo(reservas, tamanho);
}


/*-----------------------------------------------------------------------------------
Função principal.
Coordena o funcionamento das outras funções.
-----------------------------------------------------------------------------------*/

int main (void) {

    char codigo[3];
    int vendas = 0, fechado = 0;

    Reserva **reservas = NULL;
    Aviao aviao;

    lerDados(&reservas, &aviao, &vendas, &fechado);

    do {
        scanf("%s", &codigo);

        if (strcmp("AV", codigo) == 0) {
            aviao = aberturaVoo();
        } else if (strcmp("RR", codigo) == 0) {
            if (!fechado) {
                realizarReserva(aviao, &reservas, &vendas);
            } else {
                printf("Voo fechado! Apenas consultas são permitidas!\n");
            }
        } else if (strcmp("CR", codigo) == 0) {
            consultarReserva(reservas, vendas);
        } else if (strcmp("MR", codigo) == 0) {
            if (!fechado) {
                modificarReserva(reservas, vendas);
            } else {
                printf("Voo fechado! Apenas consultas são permitidas!\n");
            }
        } else if (strcmp("CA", codigo) == 0) {
            if (!fechado) {
                cancelarReserva(&reservas, &vendas);
            } else {
                printf("Voo fechado! Apenas consultas são permitidas!\n");
            }
        } else if (strcmp("FD", codigo) == 0) {
            fecharDia(reservas, vendas);
            gravarDados(reservas, aviao, vendas, 0);
            break;
        } else if (strcmp("FV", codigo) == 0) {
            fecharVoo(reservas, aviao, vendas);
            gravarDados(reservas, aviao, vendas, 1);
            break;
        }
    } while (1);

    return (0);
}
