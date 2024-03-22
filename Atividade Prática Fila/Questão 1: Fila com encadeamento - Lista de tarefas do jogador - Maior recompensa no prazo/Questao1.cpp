/*

Modifique o tipo do campo prêmio para inteiro, sendo o valor a ser recebido em moedas digitais pela
atividade realizada pelo jogador. Implemente uma função que imprima a soma das recompensas das
atividades com tempo menor que o informado e coloque essas atividade no início da fila.
Caso não exista nenhuma atividade menor que o valor informado, deve ser impresso o valor 0.

Você pode (e deve!) utilizar o código que você desenvolveu na atividade "Fila com encadeamento -
Lista de tarefas do jogador" como base.

Com essa finalidade, você deverá adicionar mais um comando, como segue:

    p seguido de um inteiro: para contabilizar (e imprimir) o valor total do premio das atividades
    que foram realizadas dentro do valor determinado.

Saídas:

Todas as saídas de comandos já estão implementadas na função principal código entregue, somente
falta implementar a chamada para a remoção. Ao terminar a execução do programa, todos os itens da
pilha são desempilhados e escritos.

Exemplo de Entrada e Saída juntas:

r
Erro: Fila vazia!
i destruirArmazen 252 f 100
i salvarDonzela 888 e 300
i montarObservatorioMonteM2 582 d 400
i eliminarChefao 12585 a 2000
i eliminarBando 25354 a 30000
p 500
1722
r
Nome: destruirArmazen Premio: 252 Tipo: f tempo: 100
e
Nome: salvarDonzela Premio: 888 Tipo: e tempo: 300
f
Nome: salvarDonzela Premio: 888 Tipo: e tempo: 300
Nome: montarObservatorioMonteM2 Premio: 582 Tipo: d tempo: 400
Nome: eliminarChefao Premio: 12585 Tipo: a tempo: 2000
Nome: eliminarBando Premio: 25354 Tipo: a tempo: 30000

*/

#include <iostream>

using namespace std;

struct ItemFila
{
    string nome;
    int premio;
    char tipo;
    int tempo;
};

class Fila
{
private:
    ItemFila *itens;
    int inicio;
    int fim;
    int tamanho;
    int capacidade;
public:
    Fila(int capacidade)
    {
        this->capacidade = capacidade;
        itens = new ItemFila[capacidade];
        inicio = 0;
        fim = -1;
        tamanho = 0;
    }

    bool vazia()
    {
        if(inicio>fim)
        return true;
        else
        return false;
    }

    void imprime()
    {
        cout << "Nome: " << itens[inicio].nome << " Premio: " << itens[inicio].premio << " Tipo: " << itens[inicio].tipo << " tempo: " << itens[inicio].tempo << endl;
    }

    void redimensionar()
    {
        ItemFila *novoVetor = new ItemFila[capacidade * 2];
        for (int i = 0; i < tamanho; i++)
        {
            novoVetor[i] = itens[(inicio + i) % capacidade];
        }
        delete[] itens;
        itens = novoVetor;
        inicio = 0;
        fim = tamanho;
        capacidade *= 2;
    }

    void inserir(ItemFila item)
    {
        if (tamanho == capacidade)
        {
            redimensionar();
        }
        itens[fim] = item;
        fim = (fim + 1) % capacidade;
        tamanho++;
    }

    ItemFila remover()
    {
        ItemFila item = itens[inicio];
        if (tamanho == 0)
        {
            cout << "Erro: Fila vazia!" << endl;
        }
        else
        {
            inicio = (inicio + 1) % capacidade;
            tamanho--;
        }
        return item;
    }

    void imprimirPremio(int tempo)
    {
        int soma = 0;
        Fila auxMenor(capacidade);
        Fila auxMaior(capacidade);

        while (!vazia())
        {
            ItemFila aux= remover();
            if (aux.tempo < tempo)
            {
                soma += aux.premio;
                auxMenor.inserir(aux);
            }
            else
            {
                auxMaior.inserir(aux);
            }
        }

        cout << "Soma dos prêmios: " << soma << endl;

        while (auxMenor.tamanho > 0)
        {
            inserir(auxMenor.remover());
        }

        while (auxMaior.tamanho > 0)
        {
            inserir(auxMaior.remover());
        }
    }

    void espiar()
    {
        if (tamanho == 0)
        {
            cout << "Erro: fila vazia!" << endl;
        }
        else
            imprime();
    }
};

int main()
{
    Fila fila(3);
    char comando;
    while (cin >> comando)
    {
        switch (comando)
        {
        case 'i':
        {
            ItemFila item;
            cin >> item.nome >> item.premio >> item.tipo >> item.tempo;
            fila.inserir(item);
            break;
        }
        case 'r':
        {
            try
            {
                ItemFila item = fila.remover();
                if(!fila.vazia()) fila.imprime();
            }
            catch (const char *e)
            {
                cout << e << endl;
            }
            break;
        }
        case 'p':
        {
            int tempo;
            cin >> tempo;
            fila.imprimirPremio(tempo);
            break;
        }
        case 'e':
        {
            fila.espiar();
            break;
        }
        case 'f':
        {
            while (!fila.vazia())
            {
                fila.remover();
                fila.imprime();
            }
            return 0;
        }
        }
    }
    return 0;
}