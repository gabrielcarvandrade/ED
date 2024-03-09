/*

Escreva um programa que leia duas cadeias de caracteres e altere a primeira cadeia para retirar todos os caracteres que estão também na segunda cadeia. As duas cadeias de entrada devem ser declaradas como vetores de char alocados dinamicamente.

No final, a primeira cadeia de caracteres resultante deve ser copiada para um vertor de caracteres alocado dinamicamente com o tamanho exato. Todas alocações de vetores do programa devem ser dinâmicas.

Entradas:

    Numero de elementos do primeiro vetor
    Elementos do primeiro vetor
    Numero de elementos do segundo vetor
    Elementos do segundo vetor

Saídas:

    Vetor resultante com os caracteres do primeiro vetor que não se encontram no segundo.

Exemplo de Entrada:

10
q w e r t y u i o p
9
m n b v c x z q w

Exemplo de Saída:

e r t y u i o p

*/

#include <iostream>

using namespace std;

int main()
{
    int n1, n2;
    cin >> n1;
    char *vet1 = new char[n1];
    for (int i = 0; i < n1; i++)
    {
        cin >> vet1[i];
    }
    cin >> n2;
    char *vet2 = new char[n2];
    for (int i = 0; i < n2; i++)
    {
        cin >> vet2[i];
    }
    int cont = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (vet1[i] == vet2[j])
            {
                vet1[i] = ' ';
                cont++;
            }
        }
    }
    char *vet3 = new char[n1 - cont];
    int k = 0;
    for (int i = 0; i < n1; i++)
    {
        if (vet1[i] != ' ')
        {
            vet3[k] = vet1[i];
            k++;
        }
    }
    for (int i = 0; i < n1 - cont; i++)
    {
        cout << vet3[i] << " ";
    }
    delete[] vet1;
    delete[] vet2;
    delete[] vet3;
    return 0;
}
