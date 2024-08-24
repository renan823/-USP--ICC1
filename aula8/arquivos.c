#include <stdio.h>
#include <stdlib.h>

/*
Por que usar arquivos?
Armazenar dados permanentemente ou para volumes
de dados muito grande

Um arquivo é um modelo que representa informação

- Stream: é um fluxo ou sequência
O C fornece uma interface (abstração) para manipular arquivos

Para um SO, tudo é arquivo, são streams!
Por exemplo, ao digitar no teclado, o buffer armazena
o que foi digitado e pode ser usado futuramente

Arquivos podem ser texto (caracteres) ou binario
Para texto, há um método de como ler aqueles bits

Já para o binário, é necessário um header
que coordena o modo de operar o arquivo (como um mapa)

É possivel colocar informações no header 

Estrutura FILE é a stream
Para usar FILE é necessário um ponteiro

ABRIR ARQUIVO:

FILE *arquivo = fopen(nomeDoArquivo, modoDeLeitura);

Ao abrir com "w" um arquivo que já existe, os dados serão sobrescritos
Deve então abrir com leitura/escrita -> "r+"

Ao tentar abrir o arquivo, se o retorno é nullo, então
o arquivo não existe.

o fclose(*arquivo) fecha o arquivo
Então, e só então, os dados serã gravados no disco!

Para escrever em arquivos:

putc(caracter, arquivo);
fputc(caracter, arquivo);

Recebe um caracter (como int) e o arquivo
Então o caracter é escrito.

fprintf(arquivo, formatador, dados);
Recebe o arquivo, o formatador e os dados;
É igual ao printf!!!!!;
*/

FILE *abrirArquivo (char *nome, char *modo) {
	FILE *arquivo;

	if ((arquivo = fopen(nome, modo)) == NULL) {
		printf("Erro: Não foi possível abrir o arquivo\n");
		exit(1);
	} 

	return (arquivo);
}

int main (int argc, char *argv[]) {

	FILE *arquivo = abrirArquivo(argv[1], "w");

	fclose(arquivo);

	return (0);
}