/*Faça um programa que cadastre o sobrenome e as idades de famílias de 3 membros cada (idade do pai, da mãe e do filho). Os dados devem ser lidos em um arranjo alocado dinamicamente, inicialmente com tamanho 3. A leitura deve ser encerrada quando for lida a palavra FIM como nome da familia. Após o término da leitura dos dados, identifique os casais que possuem filhos de mesma idade e armazene os sobrenomes das famílias envolvidas na igualdade. Caso não haja correspondentes, deve ser impressa a mensagem NENHUM.

Restrições adicionais:
* As idades dos membros de uma família devem ser armazenadas em um registro.
** O tamanho inicial do vetor a ser utilizado é 3 e devem ser acrescentadas 3 posições a cada redimensionamento.

Entradas:

    Conjunto de sobrenomes e idades das famílias

Saídas:

    Tamanho do vetor após cada redimensionamento do vetor de entrada.
    Sobrenome das famílias com filhos de mesma idade.

Entradas:
Silva 44 41 17
Araujo 54 49 19
Pires 25 30 4
Correia 29 27 19
Paulino 60 65 19
Moreira 29 28 4
Matos 42 41 14
FIM 

Saídas:
6
9
Araujo
Correia
Paulino
Pires
Moreira

 

Entradas:

Castro 44 41 17
Gomes 38 36 15
Perez 44 49 19
FIM

Saídas:
NENHUM

Entradas:
Xavier 50 41 10
Salles 58 56 20
Geraldi 44 49 10
Torres 44 49 20
FIM

Saídas:
6
Xavier
Geraldi
Salles
Torres
*/

#include <iostream>

using namespace std;

struct Familia
{
    string sobrenome;
    int pai;
    int mae;
    int filho;
};

int main()
{
    int tamanho = 3;
    int contador = 0;
    Familia *familias = new Familia[tamanho];
    string sobrenome;
    int pai, mae, filho;

    while (cin >> sobrenome && sobrenome != "FIM")
    {
        cin >> pai >> mae >> filho;
        if (contador == tamanho)
        {
            tamanho += 3;
            Familia *temp = new Familia[tamanho];
            for (int i = 0; i < contador; i++)
            {
                temp[i] = familias[i];
            }
            delete[] familias;
            familias = temp;
        }
        familias[contador].sobrenome = sobrenome;
        familias[contador].pai = pai;
        familias[contador].mae = mae;
        familias[contador].filho = filho;
        contador++;
        cout << tamanho << endl;
    }

    bool temIgual = false;
    for (int i = 0; i < contador; i++)
    {
        for (int j = i + 1; j < contador; j++)
        {
            if (familias[i].filho == familias[j].filho)
            {
                temIgual = true;
                cout << familias[i].sobrenome << endl;
                cout << familias[j].sobrenome << endl;
            }
        }
    }
    if (!temIgual)
    {
        cout << "NENHUM" << endl;
    }

    delete[] familias;
    return 0;
}