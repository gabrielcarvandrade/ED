/*

Na matemática a união de dois conjuntos A e B é representada por A ∪ B e é formada por todos os elementos 
pertencentes a A ou B. Por exemplo, seja A = {1, 2, 3} e B = {4, 5}, então a união destes dois conjuntos 
será A ∪ B = {1, 2, 3, 4, 5}, porém caso um elemento esteja em ambos os conjuntos ele não irá aparecer 
duas vezes no conjunto união, por exemplo, seja A = {1, 2, 3} e B = {1, 2, 4}, assim a união será 
A ∪ B = {1, 2, 3, 4}.

Utilizando os conceitos de conjunto faça um programa que leia dois vetores A e B e determine a união. 
O tamanho de cada vetor será informado pelo usuário.

Obs.: Considere que não existirão vetores vazios.

Obs.2: Os vetores devem ser alocados dinamicamente.

Entradas:

    Tamanho do vetor A.
    Elementos do vetor A.
    Tamanho do vetor B.
    Elementos do vetor B.

Saídas:

    Vetor C representado a união dos vetores A e B.

Exemplo de Entrada:

3
1 2 3
2
2 4

Exemplo de Saída:

1 2 3 4

*/

#include <iostream>

using namespace std;

int main()
{
    int tamA = 0, tamB = 0, tamC = 0;

    cin>>tamA;
    tamC = tamA;
    int* vetA = new int[tamA];

    for(int i = 0; i<tamA;i++)
    {   
        cin>>vetA[i];
    }

    cin>>tamB;
    int* vetB = new int[tamB];

    for(int i = 0; i<tamB;i++)
    {   
        cin>>vetB[i];
    }

    int* vetC = new int[tamA];

    for (int i = 0; i < tamC; i++)
    {
        vetC[i] = vetA[i];
    }

    for (int i = 0; i < tamB; i++)
    {
        int numDiferentes = 0;
        bool ehDiferente = false;
        for (int j = 0; j < tamA; j++)
        {
            if(vetB[i] != vetA[j])
            {
                numDiferentes++;
            }
        }
        if(numDiferentes == tamA)
            ehDiferente = true;
        if(ehDiferente)
        {
            tamC++;
            int* vetC2 = new int[tamC];
            vetC2 = vetC;
            vetC2[tamC-1] = vetB[i];
            vetC = vetC2;
        }
    }

    for (int i = 0; i < tamC; i++)
    {
        cout<<vetC[i]<<" ";
    }

    return 0;
}