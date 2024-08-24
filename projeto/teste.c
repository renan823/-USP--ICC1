#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nome;
    char *sobrenome;
    char cpf[15];
} Pessoa;

typedef struct {
    int tam_nome, tam_sobr;
} Separador;

typedef struct {
    int usuarios;
} Cabecalho;

void *alocar (int quantidade, int tamanho) {
    void *vetor;

    if ((vetor = (void *) malloc(quantidade * tamanho)) == NULL) {
        printf("Erro: sem memória para alocar\n");
        exit(1);
    }

    return (vetor);
}

void *realocar (void *ponteiro, int quantidade, int tamanho) {
    if ((ponteiro = (void *) realloc(ponteiro, quantidade * tamanho)) == NULL) {
        printf("Erro: sem memória para alocar\n");
        exit(1);
    }

    return (ponteiro);
}

FILE *abrirArquivo (char *nome, char *modo) {
	FILE *arquivo;

	if ((arquivo = fopen(nome, modo)) == NULL) {
		//printf("Erro: nenhum arquivo encontrado\n");
		//exit(1);
		return (NULL);
	}

	return (arquivo);
}

Pessoa *lerDados (int *tamanho) {
    FILE *arquivo = abrirArquivo("dados.dat", "rb");

    if (arquivo == NULL) {
        return (NULL);
    }

    Cabecalho c;
    Separador s;
    fread(&c, sizeof(Cabecalho), 1, arquivo);

    *tamanho = c.usuarios;

    Pessoa *pessoas = (Pessoa *) alocar(*tamanho, sizeof(Pessoa));


    for (int i = 0; i < *tamanho; i++) {
        fread(&pessoas[i], sizeof(Pessoa), 1, arquivo);
        fread(&s, sizeof(Separador), 1, arquivo);

        pessoas[i].nome = (char *) alocar(s.tam_nome, sizeof(char));
        pessoas[i].sobrenome = (char *) alocar(s.tam_sobr, sizeof(char));
 
        fread(pessoas[i].nome, sizeof(char), s.tam_nome, arquivo);
        fread(pessoas[i].sobrenome, sizeof(char), s.tam_sobr, arquivo);
    }   

    fclose(arquivo);

    return (pessoas);
}

void gravarDados (Pessoa *pessoas, int tamanho) {
    FILE *arquivo = abrirArquivo("dados.dat", "wb");

    Cabecalho c = { tamanho };
    Separador s;

    fwrite(&c, sizeof(Cabecalho), 1, arquivo);

    for (int i = 0; i < tamanho; i++) {
        fwrite(&pessoas[i], sizeof(Pessoa), 1, arquivo);

        s.tam_nome = strlen(pessoas[i].nome); 
        s.tam_sobr = strlen(pessoas[i].sobrenome);
        fwrite(&s, sizeof(Separador), 1, arquivo);

        fwrite(pessoas[i].nome, sizeof(char), strlen(pessoas[i].nome), arquivo);
        fwrite(pessoas[i].sobrenome, sizeof(char), strlen(pessoas[i].sobrenome), arquivo);

        free(pessoas[i].nome);
        free(pessoas[i].sobrenome);
    }

    free(pessoas);

    fclose(arquivo);
}



int main (int argc, char *argv[]) {
    Pessoa *pessoas = NULL;
    int n;

        if (strcmp(argv[1], "G") == 0) {
            scanf("%d", &n);

            pessoas = (Pessoa *) alocar(n, sizeof(Pessoa));

            for (int i = 0; i < n; i++) {
                pessoas[i].nome = (char *) alocar(30, sizeof(char));
                pessoas[i].sobrenome = (char *) alocar(30, sizeof(char));

                scanf("%s %s %s", pessoas[i].nome, pessoas[i].sobrenome, pessoas[i].cpf);
            }

            gravarDados(pessoas, n);
        } else {
            pessoas = lerDados(&n);

            for (int i = 0; i < n; i++) {
                printf("%s %s %s\n", pessoas[i].nome, pessoas[i].sobrenome, pessoas[i].cpf);

                free(pessoas[i].nome);
                free(pessoas[i].sobrenome);
            }

            free(pessoas);
        }

    return (0);
}