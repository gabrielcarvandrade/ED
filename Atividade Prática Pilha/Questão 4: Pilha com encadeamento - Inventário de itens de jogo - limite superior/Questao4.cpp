/*
Exemplo de Entrada e Saída juntas:

r
Erro: pilha vazia!
i um a 1
i dois b 2
i dez j 10
i quatro d 4
i sete g 7
i oito h 8
r
Nome: oito Tipo: h Valor: 8
e
Nome: sete Tipo: g Valor: 7
x 4
Nome: sete Tipo: g Valor: 7
Nome: dez Tipo: j Valor: 10
f
Nome: quatro Tipo: d Valor: 4
Nome: dois Tipo: b Valor: 2
Nome: um Tipo: a Valor: 1

*/
#include <iostream>

using namespace std;

// Estrutura para representar um item
struct Item
{
    string nome;
    string tipo;
    int valor;
    Item *prox; // Ponteiro para o próximo item na pilha
};

// Classe para representar uma pilha
class Pilha
{
private:
    Item *topo; // Ponteiro para o item no topo da pilha
    int tamanho; // Variável para armazenar o tamanho atual da pilha

public:
    // Método para verificar se a pilha está vazia
    bool vazia(Pilha *pilha)
    {
        if (pilha->topo == NULL)
        {
            return true;
        }
        else
            return false;
    }

    // Método para imprimir um item
    string imprime(string nome, string tipo, int valor)
    {
        return "Nome: " + nome + " Tipo: " + tipo + " Valor: " + to_string(valor);
    }

    // Método para inicializar a pilha
    void inicializar(Pilha *pilha)
    {
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }

    // Método para adicionar um item à pilha
    void empilhar(Pilha *pilha, string nome, string tipo, int valor)
    {
        Item *novo = new Item;
        novo->nome = nome;
        novo->tipo = tipo;
        novo->valor = valor;
        novo->prox = pilha->topo;
        pilha->topo = novo;
        pilha->tamanho++;
    }

    // Método para remover um item da pilha
    void desempilhar(Pilha *pilha)
    {
        if (vazia(pilha))
        {
            cout << "Erro: pilha vazia!" << endl;
        }
        else
        {
            Item *aux = pilha->topo;
            pilha->topo = pilha->topo->prox;
            cout << imprime(aux->nome, aux->tipo, aux->valor);
            cout << endl;
            delete aux;
            pilha->tamanho--;
        }
    }

    // Método para espiar o item no topo da pilha
    void espiar(Pilha *pilha)
    {
        if (vazia(pilha))
        {
            cout << "Erro: pilha vazia!" << endl;
        }
        else
        {
            cout << imprime(pilha->topo->nome, pilha->topo->tipo, pilha->topo->valor);
            cout << endl;
        }
    }

    // Método para remover itens com valor maior que um valor específico da pilha
    void removerEspecial(Pilha *pilha, int valor)
    {
        Pilha aux;
        inicializar(&aux);
        while (!vazia(pilha))
        {
            if (pilha->topo->valor > valor)
            {
                Item *removido = pilha->topo;
                pilha->topo = pilha->topo->prox;
                cout << imprime(removido->nome, removido->tipo, removido->valor);
                cout << endl;
                delete removido;
                pilha->tamanho--;
            }
            else
            {
                Item *novo = new Item;
                novo->nome = pilha->topo->nome;
                novo->tipo = pilha->topo->tipo;
                novo->valor = pilha->topo->valor;
                novo->prox = aux.topo;
                aux.topo = novo;
                aux.tamanho++;
                Item *removido = pilha->topo;
                pilha->topo = pilha->topo->prox;
                delete removido;
                pilha->tamanho--;
            }
        }
        while (aux.topo != NULL)
        {
            Item *novo = new Item;
            novo->nome = aux.topo->nome;
            novo->tipo = aux.topo->tipo;
            novo->valor = aux.topo->valor;
            novo->prox = pilha->topo;
            pilha->topo = novo;
            pilha->tamanho++;
            Item *removido = aux.topo;
            aux.topo = aux.topo->prox;
            delete removido;
            aux.tamanho--;
        }
    }
};

// Função principal
int main()
{
    Pilha pilha;
    pilha.inicializar(&pilha);
    char comando;
    string nome, tipo;
    int valor;
    while (cin >> comando)
    {
        switch (comando)
        {
        case 'i': // Comando para inserir um item na pilha
        {
            cin >> nome >> tipo >> valor;
            pilha.empilhar(&pilha, nome, tipo, valor);
            break;
        }
        case 'r': // Comando para remover um item da pilha
        {
            pilha.desempilhar(&pilha);
            break;
        }
        case 'x': // Comando para remover itens com valor maior que um valor específico da pilha
        {
            cin >> valor;
            pilha.removerEspecial(&pilha, valor);
            break;
        }
        case 'e': // Comando para espiar o item no topo da pilha
        {
            pilha.espiar(&pilha);
            break;
        }
        case 'f': // Comando para limpar a pilha
        {
            while (!pilha.vazia(&pilha))
            {
                pilha.desempilhar(&pilha);
            }
            return 0;
        }
        }
    }
    return 0;
}