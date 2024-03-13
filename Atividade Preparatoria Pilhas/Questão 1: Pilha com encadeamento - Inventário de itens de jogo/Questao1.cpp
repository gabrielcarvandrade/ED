/*

Implemente uma estrutura de dados pilha, utilizando encadeamento de nós,
para implementar um inventário de itens em um jogo digital. A estrutura deve
possibilitar, pelo menos, as seguintes ações: empilhamento e desempilhamento de itens,
verificação do item no topoPilha da pilha e limpeza do inventário (remoção de todos os elementos da pilha).
O desempilhamento deve escrever mensagem de erro na saída ("Erro: pilha vazia!"),
quando a pilha já estiver vazia. Os itens do inventários possuem os seguintes atributos:
nome (uma string sem espaços), tipo (um único caracter) e valor (um inteiro).

Entradas:

O programa deve aceitar os seguintes comandos:

    i: seguido de uma string, um caracter e um inteiro: para inserir um item no inventário
    r: para retirar um item do inventário
    l: para limpar (remover todos) os itens do inventário
    e: para espiar o topoPilha do inventário (escreve o topoPilha sem removê-lo)
    f: para finalizar a execução do programa

Saídas:

Todas as saídas de comandos já estão implementadas na função principal desse código exemplo fornecido.
Ao terminar a execução do programa, todos os itens da pilha são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: pilha vazia!
i um a 1
i dois b 2
i quatro d 4
i sete g 7
i oito h 8
r
Nome: oito Tipo: h Valor: 8
e
Nome: sete Tipo: g Valor: 7
r
Nome: sete Tipo: g Valor: 7
f
Nome: quatro Tipo: d Valor: 4
Nome: dois Tipo: b Valor: 2
Nome: um Tipo: a Valor: 1

*/

#include <iostream>

using namespace std;

struct ItemPilha
{
    string nome;
    char tipo;
    int valor;
    ItemPilha *proximoItem;
};

struct Pilha
{
    ItemPilha *topoPilha;
    Pilha()
    {
        topoPilha = NULL;
    }
    void empilhar(string nome, char tipo, int valor)
    {
        ItemPilha *novo = new ItemPilha;
        novo->nome = nome;
        novo->tipo = tipo;
        novo->valor = valor;
        novo->proximoItem = topoPilha;
        topoPilha = novo;
    }
    void desempilhar()
    {
        if (topoPilha == NULL)
        {
            cout << "Erro: pilha vazia!" << endl;
            return;
        }
        ItemPilha *aux = topoPilha;
        topoPilha = topoPilha->proximoItem;
        cout << "Nome: " << aux->nome << " Tipo: " << aux->tipo << " Valor: " << aux->valor << endl;
        delete aux;
    }
    void limpar()
    {
        while (topoPilha != NULL)
        {
            desempilhar();
        }
    }
    void espiar()
    {
        if (topoPilha == NULL)
        {
            cout << "Erro: pilha vazia!" << endl;
            return;
        }
        cout << "Nome: " << topoPilha->nome << " Tipo: " << topoPilha->tipo << " Valor: " << topoPilha->valor << endl;
    }
};

int main()
{
    Pilha pilha;
    string nome;
    char comando;
    char tipo;
    int valor;
    int contPilha = 1;
    while (cin >> comando)
    {
        if (comando == 'i')
        {
            cin >> nome >> tipo >> valor;
            pilha.empilhar(nome, tipo, valor);
            contPilha++;
        }
        else if (comando == 'r')
        {
            pilha.desempilhar();
            contPilha--;
        }
        else if (comando == 'l')
        {
            pilha.limpar();
        }
        else if (comando == 'e')
        {
            pilha.espiar();
        }
        else if (comando == 'f')
        {
            while (contPilha != 0)
            {
                pilha.desempilhar();
                contPilha--;
            }
            return 0;
        }
    }
    return 0;
}
