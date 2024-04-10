/*
Exemplo de Entrada e Saída juntas:

r
Erro: pilha vazia!
i sala s 150
i quarto1 q 45
i quarto2 q 60
i quarto3 q 45
i cozinha c 130
r
Nome: cozinha Tipo: c Valor: 130
i cozinha c 143
e
Nome: cozinha Tipo: c Valor: 143
i varanda v 111
i banheiro b 33
Erro: pilha cheia!
x q
f
Nome: varanda Tipo: v Valor: 111
Nome: cozinha Tipo: c Valor: 143
Nome: sala Tipo: s Valor: 150

*/
#include <iostream>
#include <vector>

using namespace std;

// Estrutura para representar um item
struct Item
{
    string nome;
    string tipo;
    int valor;
};

// Classe para representar uma pilha
class Pilha
{
private:
    vector<Item> pilha; // Vetor para armazenar os itens da pilha
    int tamanho; // Variável para armazenar o tamanho atual da pilha

public:
    // Método para verificar se a pilha está vazia
    bool vazia()
    {
        return pilha.empty();
    }

    // Método para verificar se a pilha está cheia
    bool cheia(int capacidade)
    {
        return tamanho == capacidade;
    }

    // Método para imprimir um item
    string imprimir(Item item)
    {
        return "Nome: " + item.nome + " Tipo: " + item.tipo + " Valor: " + to_string(item.valor);
    }

    // Método para inserir um item na pilha
    void empilhar(string nome, string tipo, int valor)
    {
        Item novo;
        novo.nome = nome;
        novo.tipo = tipo;
        novo.valor = valor;
        pilha.push_back(novo);
        tamanho++;
    }

    // Método para remover um item da pilha
    void desempilhar(bool imprimir = true)
    {
        if (vazia())
        {
            cout << "Erro: pilha vazia!" << endl;
        }
        else
        {
            Item aux = pilha.back();
            if (imprimir)
            {
                cout << this->imprimir(aux) << endl;
            }
            pilha.pop_back();
            tamanho--;
        }
    }

    // Método para limpar a pilha
    void limpar()
    {
        while (!vazia())
        {
            desempilhar();
        }
    }

    // Método para espiar o item no topo da pilha
    void espiar()
    {
        if (vazia())
        {
            cout << "Erro: pilha vazia!" << endl;
        }
        else
        {
            Item aux = pilha.back();
            cout << imprimir(aux) << endl;
        }
    }

    // Método para remover itens de um tipo específico da pilha
    void removerTipo(char tipo)
    {
        Pilha pilhaAux;
        while (!vazia())
        {
            Item aux = pilha.back();
            if (aux.tipo != string(1, tipo))
            {
                pilhaAux.empilhar(aux.nome, aux.tipo, aux.valor);
            }
            desempilhar(false);
        }
        while (!pilhaAux.vazia())
        {
            Item aux = pilhaAux.pilha.back();
            empilhar(aux.nome, aux.tipo, aux.valor);
            pilhaAux.desempilhar(false);
        }
    }

    // Método para somar os valores dos itens de um tipo específico da pilha

    void somarTipo(char tipo)
    {
        int soma = 0;
        Pilha pilhaAux;
        while (!vazia())
        {
            Item aux = pilha.back();
            if (aux.tipo == string(1, tipo))
            {
                soma += aux.valor;
            }
            pilhaAux.empilhar(aux.nome, aux.tipo, aux.valor);
            desempilhar(false);
        }
        cout << "Soma: " << soma << endl;
        while (!pilhaAux.vazia())
        {
            Item aux = pilhaAux.pilha.back();
            empilhar(aux.nome, aux.tipo, aux.valor);
            pilhaAux.desempilhar(false);
        }
    }

    // Método para buscar os valores dos itens que são maiores que o primeiro elemento e menores que o segundo
    void buscar(int valor1, int valor2)
    {
        Pilha pilhaAux;
        while (!vazia())
        {
            Item aux = pilha.back();
            if (aux.valor > valor1 && aux.valor < valor2)
            {
                cout << imprimir(aux) << endl;
            }
            pilhaAux.empilhar(aux.nome, aux.tipo, aux.valor);
            desempilhar(false);
        }
        while (!pilhaAux.vazia())
        {
            Item aux = pilhaAux.pilha.back();
            empilhar(aux.nome, aux.tipo, aux.valor);
            pilhaAux.desempilhar(false);
        }
    }
};

// Função principal
int main()
{
    Pilha pilha; // Cria uma pilha

    int capacidade;
    capacidade = 6; // Define a capacidade da pilha

    char comando;
    // Loop para ler comandos
    while (cin >> comando)
    {
        switch (comando)
        {
            case 'i': // Comando para inserir um item na pilha
            {
                string nome, tipo;
                int valor;
                cin >> nome >> tipo >> valor;
                if (!pilha.cheia(capacidade))
                {
                    pilha.empilhar(nome, tipo, valor);
                }
                else
                {
                    cout << "Erro: pilha cheia!" << endl;
                }
                break;
            }
            case 'r': // Comando para remover um item da pilha
            {
                pilha.desempilhar();
                break;
            }
            case 'e': // Comando para espiar o item no topo da pilha
            {
                pilha.espiar();
                break;
            }
            case 'f': // Comando para limpar a pilha
            {
                pilha.limpar();
                break;
            }
            case 'x': // Comando para remover itens de um tipo específico da pilha
            {
                char tipo;
                cin >> tipo;
                pilha.removerTipo(tipo);
                break;
            }
            case 's': // Comando para somar os valores dos itens de um tipo específico da pilha
            {
                char tipo;
                cin >> tipo;
                pilha.somarTipo(tipo);
                break;
            }
            case 'b': // Comando para buscar os valores dos itens que são maiores que o primeiro elemento e menores que o segundo
            {
                int valor1, valor2;
                cin >> valor1 >> valor2;
                pilha.buscar(valor1, valor2);
                break;
            }
        }
    }   
    return 0;
}