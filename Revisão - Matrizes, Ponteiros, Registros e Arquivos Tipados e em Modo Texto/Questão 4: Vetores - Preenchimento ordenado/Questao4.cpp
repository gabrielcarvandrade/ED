/*

Faça um programa que receba oito números inteiros e os armazene de forma ordenada em um vetor.
 Ou seja, assim que lidos, os números já devem ser inseridos no vetor em uma posição que mantém
 a ordem crescente. Eles não podem ser inseridos no final do vetor para o vetor passar por uma ordenação.

Cada vez que um número for colocado no vetor o programa deve exibir os números inseridos até então.

Entrada:

    Oito números inteiros a serem inseridos no vetor.

Saída:

    Oito linhas contendo em cada uma a situação do vetor após a inserção de cada número lido.

Exemplo de entrada:

7 3 4 6 2 9 0 1

Exemplo de saída:

7
3 7
3 4 7
3 4 6 7
2 3 4 6 7
2 3 4 6 7 9
0 2 3 4 6 7 9
0 1 2 3 4 6 7 9

*/

#include <iostream>

using namespace std;

int main()
{
    int vetor[8];
    int i, j, aux;

    for (i = 0; i < 8; i++)
    {
        cin >> vetor[i];
        for (j = i; j > 0; j--)
        {
            if (vetor[j] < vetor[j - 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j - 1];
                vetor[j - 1] = aux;
            }
        }
        for (j = 0; j <= i; j++)
        {
            cout << vetor[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
