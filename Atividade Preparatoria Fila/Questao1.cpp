/*

Implemente uma estrutura de dados fila, utilizando armazenamento em vetor, para implementar
uma lista de processos para uma repartição pública, utilizando como base o código fornecido.
A estrutura deve possibilitar, pelo menos, as seguintes ações: enfileiramento e desenfileiramento
de itens, verificação do item no topo da pilha e limpeza de processos (remoção de todos os
elementos da fila). O desenfileiramento deve escrever mensagem de erro na saída ("Erro: fila vazia!"),
quando a fila já estiver vazia. O enfileiramento também deve gerar mensagem de erro
("Erro: fila cheia!"), quanto todas as posições do vetor estiverem ocupadas. Os itens da
lista de processos possuem os seguintes atributos: assunto (uma string sem espaços), nome
do interessado(uma string sem espaços), tipo (um único caracter) e numero do processo (um inteiro).
Além disso, essa repartição tem capacidade para trabalhar com apenas seis processos por vez.

Entradas:

O programa deve aceitar os seguintes comandos:

    i seguido de uma string, um caracter e um inteiro: para inserir um item na lista de processos
    r: para retirar um item da lista de processos
    l: para limpar (remover todos) os itens da lista de processos
    e: para espiar o topo da lista de processo (escreve o topo sem removê-lo)
    f: para finalizar a execução do programa

Saídas:

Todas as saídas de comandos já estão implementadas na função principal desse código exemplo fornecido.
Ao terminar a execução do programa, todos os itens da fila são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: fila vazia!
i processo1 Joao a 2
i processo2 Maria c 5
i processo3 Severino d 9
i processo4 Marcos f 12
i processo5 Barnabe a 10
i processo6 Tiao z 22
i processo7 Marlon a 40
Erro: fila cheia!
r
Nome: processo1 Assunto: Joao Tipo: a Processo: 2
e
Nome: processo2 Assunto: Maria Tipo: c Processo: 5
i processo7 Marlon a 40
f
Nome: processo2 Assunto: Maria Tipo: c Processo: 5
Nome: processo3 Assunto: Severino Tipo: d Processo: 9
Nome: processo4 Assunto: Marcos Tipo: f Processo: 12
Nome: processo5 Assunto: Barnabe Tipo: a Processo: 10
Nome: processo6 Assunto: Tiao Tipo: z Processo: 22
Nome: processo7 Assunto: Marlon Tipo: a Processo: 40

*/
#include <iostream>

using namespace std;

class ItemFila
{
public:
    string assunto;
    string nomeInteressado;
    char tipo;
    int numeroProcesso;
};

class Fila
{
public:
    ItemFila *itens;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;

    Fila(int capacidade)
    {
        this->capacidade = capacidade;
        itens = new ItemFila[capacidade];
        inicio = 0;
        fim = 0;
        tamanho = 0;
    }

    void enfileirar(string assunto, string nomeInteressado, char tipo, int numeroProcesso)
    {
        if (tamanho == capacidade)
        {
            cout << "Erro: fila cheia!" << endl;
            return;
        }

        itens[fim].assunto = assunto;
        itens[fim].nomeInteressado = nomeInteressado;
        itens[fim].tipo = tipo;
        itens[fim].numeroProcesso = numeroProcesso;
        fim = (fim + 1) % capacidade;
        tamanho++;
    }

    void desenfileirar()
    {
        if (tamanho == 0)
        {
            cout << "Erro: fila vazia!" << endl;
            return;
        }
        cout << "Nome: " << itens[inicio].assunto << " Assunto: " << itens[inicio].nomeInteressado << " Tipo: " << itens[inicio].tipo << " Processo: " << itens[inicio].numeroProcesso << endl;
        inicio = (inicio + 1) % capacidade;
        tamanho--;
    }

    void limpar()
    {
        while (tamanho > 0)
        {
            desenfileirar();
        }
    }

    void espiar()
    {
        if (tamanho == 0)
        {
            cout << "Erro: fila vazia!" << endl;
            return;
        }
        cout << "Nome: " << itens[inicio].assunto << " Assunto: " << itens[inicio].nomeInteressado << " Tipo: " << itens[inicio].tipo << " Processo: " << itens[inicio].numeroProcesso << endl;
    }
};

int main()
{
    Fila fila(6);

    char comando;
    string assunto;
    string nomeInteressado;
    char tipo;
    int numeroProcesso;

    while (cin >> comando)
    {
        switch (comando)
        {
        case 'i':
            cin >> assunto >> nomeInteressado >> tipo >> numeroProcesso;
            fila.enfileirar(assunto, nomeInteressado, tipo, numeroProcesso);
            break;
        case 'r':
            fila.desenfileirar();
            break;
        case 'l':
            fila.limpar();
            break;
        case 'e':
            fila.espiar();
            break;
        case 'f':
            while (fila.tamanho > 0)
            {
                fila.desenfileirar();
            }
            return 0;
        }
    }
    return 0;
}