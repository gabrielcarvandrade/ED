/*

Dadas duas filas F1 e F2, implemente o método que remove os elementos de F2, 
presentes em F1. F1 deve estar disponível após a remoção dos elementos de F2 
para outras operações. As propriedades de fila devem ser estritamente respeitadas, 
ou seja: não é permitido o acesso aleatório aos elementos da fila.A fila deve ser 
implementada utilizando encadeamento.

Entradas:

    Número de elementos a serem inseridos em F1.
    Elementos de F1 em ordem de inserção (inserção no fim da fila).
    Número de elementos a serem inseridos em F2.
    Elementos de F2 em ordem de inserção (inserção no fim da fila).

Saídas:

    Elementos restantes em F1 após a remoção.

Exemplo de Entrada:

11

4 6 9 10 1 9 2 13 7 3 5

4

9 2 7 3

Exemplo de Saída:

4 6 10 1 13 5

*/

#include <iostream>

using namespace std;

class ItemFila
{
    public:
        int valor;
        ItemFila *proximoItem;
};

class Fila
{
    public:
        ItemFila *primeiroItem;
        ItemFila *ultimoItem;
        int tamanho;

        Fila()
        {
            primeiroItem = NULL;
            ultimoItem = NULL;
            tamanho = 0;
        }

        void inserir(int valor)
        {
            ItemFila *novoItem = new ItemFila();
            novoItem->valor = valor;
            novoItem->proximoItem = NULL;

            if (tamanho == 0)
            {
                primeiroItem = novoItem;
                ultimoItem = novoItem;
            }
            else
            {
                ultimoItem->proximoItem = novoItem;
                ultimoItem = novoItem;
            }

            tamanho++;
        }

        int remover()
        {
            if (tamanho == 0)
            {
                return -1;
            }

            ItemFila *itemRemovido = primeiroItem;
            int valor = itemRemovido->valor;

            if (tamanho == 1)
            {
                primeiroItem = NULL;
                ultimoItem = NULL;
            }
            else
            {
                primeiroItem = itemRemovido->proximoItem;
            }

            delete itemRemovido;
            tamanho--;

            return valor;
        }
};

void removerElementos(Fila *f1, Fila *f2)
{
    Fila f3;
    int valorF2;
    int valorF1;

    while (f2->tamanho > 0)
    {
        valorF2 = f2->remover();
        while (f1->tamanho > 0)
        {
            valorF1 = f1->remover();
            if (valorF1 != valorF2)
            {
                f3.inserir(valorF1);
            }
        }
        while (f3.tamanho > 0)
        {
            f1->inserir(f3.remover());
        }
    }
}

int main()
{
    Fila f1;
    Fila f2;
    int quantF1;
    int quantF2;
    int valor;

    cin >> quantF1;
    for (int i = 0; i < quantF1; i++)
    {
        cin >> valor;
        f1.inserir(valor);
    }

    cin >> quantF2;
    for (int i = 0; i < quantF2; i++)
    {
        cin >> valor;
        f2.inserir(valor);
    }

    removerElementos(&f1, &f2);

    while (f1.tamanho > 0)
    {
        cout << f1.remover() << " ";
    }

    return 0;
}

