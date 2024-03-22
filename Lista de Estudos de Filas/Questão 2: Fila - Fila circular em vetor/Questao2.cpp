/*


Filas podem ser implementadas com armazenamento de dados em vetor, se a capacidade fixa
não for um problema. Nesse caso, é importante controlar os índices para "dar a volta" no
vetor sempre que for necessário. Uma fila assim pode ser chamada de fila circular.

Faça a implementação de uma fila circular fazendo com que a inserção (método Enfileirar)
sempre use o início do vetor (posição zero) quando a fila estiver vazia.

Entradas:

Inicialmente, o programa lê um número inteiro que é capacidade da fila a ser criada.

Depois, o programa lê códigos de comandos a executar. Sempre um caractere identificando o comando seguido dos parâmetros necessários para executar o comando, se houverem. Os códigos de comandos são:

    t - para terminar a execução do programa
    e - para enfileirar um valor - seguido do valor (número inteiro)
    d - para desenfileirar um valor
    i - para escrever as informações da fila (atributos e conteúdo)

Saídas:

Os comandos d e i são os únicos que produzem saída de dados. Cada um pode ser observado no exemplo.

Exemplo de Entrada e Saída juntos:

3
e 1
e 2
e 3
i
tamanho=3 capacidade=3 inicio=0 fim=2
1 2 3
d
1
e 4
i
tamanho=3 capacidade=3 inicio=1 fim=0
2 3 4
d
2
d
3
i
tamanho=1 capacidade=3 inicio=0 fim=0
4
t

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
        ItemFila *itens;
        int inicio;
        int fim;
        int tamanho;
        int capacidade;

        Fila(int capacidade)
        {
            this->capacidade=capacidade;
            itens = new ItemFila[capacidade];
            inicio = 0;
            fim = 0;
            tamanho = 0;
        }

        void enfileirar(int valor)
        {
            if (tamanho == 0)
            {
                itens[inicio].valor = valor;
                tamanho++;
            }
            else if (tamanho < capacidade)
            {
                fim = (fim + 1) % capacidade;
                itens[fim].valor = valor;
                tamanho++;
            }
        }

        int desenfileirar()
        {
            if (tamanho == 0)
            {
                return -1;
            }

            int valor = itens[inicio].valor;
            inicio = (inicio + 1) % capacidade;
            tamanho--;

            return valor;
        }
};

int main()
{
    int capacidade;
    cin >> capacidade;

    Fila fila(capacidade);

    char comando;
    int valor;

    while (cin >> comando)
    {
        switch (comando)
        {
            case 't':
                return 0;
            case 'e':
                cin >> valor;
                fila.enfileirar(valor);
                break;
            case 'd':
                cout << fila.desenfileirar() << endl;
                break;
            case 'i':
                cout << "tamanho=" << fila.tamanho << " capacidade=" << fila.capacidade << " inicio=" << fila.inicio << " fim=" << fila.fim << endl;
                for (int i = 0; i < fila.tamanho; i++)
                {
                    cout << fila.itens[(fila.inicio + i) % fila.capacidade].valor;
                    if (i < fila.tamanho - 1)
                    {
                        cout << " ";
                    }
                }
                cout << endl;
                break;
        }
    }

    return 0;
}