#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[20];
    char sobrenome[20];
    int idade;
} Pessoa;

typedef struct {
    int capacidade;
    float executiva;
    float economica;
    int vendas;
} Header;

FILE *abrirArquivo (char *nome, char *modo) {
    FILE *arquivo;

    if ((arquivo = fopen(nome, modo)) == NULL) {
        if ((arquivo = fopen(nome, "wb")) == NULL) {
            printf("Erro: não foi possível abrir o arquivo\n");
            exit(1);
        }
    }

    return (arquivo);
}

int adicionarPessoa (Pessoa *p) {
    FILE *arquivo = abrirArquivo("dados.dat", "r+b");

    fwrite(p, sizeof(Pessoa), 1, arquivo);

    fclose(arquivo);

    return (0);
}

void colocarHeader () {
    Header h = { }
}

Pessoa lerDados () {
    FILE *arquivo = abrirArquivo("dados.dat", "rb");
    Pessoa p;

    fread(&p, sizeof(Pessoa), 1, arquivo);

    return (p);
}

int main (void) {
    Pessoa p = { "José", "Carlos", 23 };

    adicionarPessoa(&p);
    Pessoa p2 = lerDados();

    printf("%s\n", p2.nome);

    return (0);
}