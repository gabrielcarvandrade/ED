/*

Elabore um programa que preencha uma matriz 10 x 10 com números inteiros, 
execute cada operação de troca especificada a seguir na matriz original e 
mostre cada matriz resultante. Você vai precisar de ao menos uma matriz extra
para realizar as operações.

Operações de troca a serem realizadas (considerando índices que começam em 1):

    a linha 2 com a linha 8;
    a coluna 4 com a coluna 10;
    a diagonal principal com a diagonal secundária;
    a linha 5 com a coluna 10.

Entrada:

    Uma matriz 10 x 10 de inteiros.

Saída:

    A matriz 10 x 10 resultante das devidas operações descritas em 1, 2, 3, e 4 
    (utilizando um índice numérico antes de exibir cada matriz).

Exemplo de entrada:

1 2 3 4 5 6 7 8 9 0
2 3 4 5 6 7 8 9 0 1
3 4 5 6 7 8 9 0 1 2
4 5 6 7 8 9 0 1 2 3
5 6 7 8 9 0 1 2 3 4
6 7 8 9 0 1 2 3 4 5
7 8 9 0 1 2 3 4 5 6
8 9 0 1 2 3 4 5 6 7
9 0 1 2 3 4 5 6 7 8
0 1 2 3 4 5 6 7 8 9

Exemplo de saí­da:


1.
1 2 3 4 5 6 7 8 9 0
8 9 0 1 2 3 4 5 6 7
3 4 5 6 7 8 9 0 1 2
4 5 6 7 8 9 0 1 2 3
5 6 7 8 9 0 1 2 3 4
6 7 8 9 0 1 2 3 4 5
7 8 9 0 1 2 3 4 5 6
2 3 4 5 6 7 8 9 0 1
9 0 1 2 3 4 5 6 7 8
0 1 2 3 4 5 6 7 8 9
2.
1 2 3 0 5 6 7 8 9 4
2 3 4 1 6 7 8 9 0 5
3 4 5 2 7 8 9 0 1 6
4 5 6 3 8 9 0 1 2 7
5 6 7 4 9 0 1 2 3 8
6 7 8 5 0 1 2 3 4 9
7 8 9 6 1 2 3 4 5 0
8 9 0 7 2 3 4 5 6 1
9 0 1 8 3 4 5 6 7 2
0 1 2 9 4 5 6 7 8 3
3.
0 2 3 4 5 6 7 8 9 1
2 0 4 5 6 7 8 9 3 1
3 4 0 6 7 8 9 5 1 2
4 5 6 0 8 9 7 1 2 3
5 6 7 8 0 9 1 2 3 4
6 7 8 9 1 0 2 3 4 5
7 8 9 3 1 2 0 4 5 6
8 9 5 1 2 3 4 0 6 7
9 7 1 2 3 4 5 6 0 8
9 1 2 3 4 5 6 7 8 0
4.
1 2 3 4 5 6 7 8 9 5
2 3 4 5 6 7 8 9 0 6
3 4 5 6 7 8 9 0 1 7
4 5 6 7 8 9 0 1 2 8
0 1 2 3 4 5 6 7 8 9
6 7 8 9 0 1 2 3 4 0
7 8 9 0 1 2 3 4 5 1
8 9 0 1 2 3 4 5 6 2
9 0 1 2 3 4 5 6 7 3
0 1 2 3 4 5 6 7 8 4

*/

#include <iostream>

using namespace std;

int main()
{
    int tamMatriz = 10, matrizInicial[tamMatriz][tamMatriz];
    int matriz1[tamMatriz][tamMatriz];
    int matriz2[tamMatriz][tamMatriz];
    int matriz3[tamMatriz][tamMatriz];
    int matriz4[tamMatriz][tamMatriz];
    
    //recebe a informação da matriz inicial e coloca em cada matriz separadamente
    for (int i = 0; i < tamMatriz; i++)
    {
        for (int j = 0; j < tamMatriz; j++)
        {
            cin>>matrizInicial[i][j];
            matriz1[i][j] = matrizInicial[i][j];
            matriz2[i][j] = matrizInicial[i][j];
            matriz3[i][j] = matrizInicial[i][j];
            matriz4[i][j] = matrizInicial[i][j];
        }
    }

    //operacao para o primeiro caso de matriz (linha 2 x linha 8)
    for (int i = 0; i < tamMatriz; i++)
    {
        int aux[tamMatriz];
        for (int j = 0; j < tamMatriz; j++)
        {
            if(i == 1)aux[j] = matriz1[i][j];
            if(i == 7)
            {
                matriz1[1][j] = matriz1[i][j];
                matriz1[i][j] = aux[j]; 
            }
        }  
    }

    //operacao para o segundo caso de matriz (coluna 4 x coluna 10)
    for (int i = 0; i < tamMatriz; i++)
    {
        int aux[tamMatriz];
        for (int j = 0; j < tamMatriz; j++)
        {
            if(j == 3)aux[i] = matriz2[i][j];
            if(j == 9)
            {
                matriz2[i][3] = matriz2[i][j];
                matriz2[i][j] = aux[i]; 
            }
        }  
    }

    //operacao para o terceiro caso de matriz (diagonal principal x diagonal secundaria)
    int aux1[tamMatriz];
    int contJ = 9;
    for (int i = 0; i < tamMatriz; i++)
    {
        aux1[i] = matriz3[i][contJ];
        matriz3[i][contJ] = matriz3[i][i];
        matriz3[i][i] = aux1[i];
        contJ--;
    }
    
    //operacao para o quarto caso de matriz (linha 5 x coluna 10)
    int aux2[tamMatriz];
    for (int i = 0; i < tamMatriz; i++)
    {
        aux2[i] = matriz4[i][9];
        matriz4[i][9] = matriz4[4][i];
        matriz4[4][i] = aux2[i];
    }

    for (int k = 0; k < 4; k++)
    {
        cout<<k+1<<"."<<endl;
        for (int i = 0; i < tamMatriz; i++)
        {
            for (int j = 0; j < tamMatriz; j++)
            {
                if(k == 0)
                cout<<matriz1[i][j]<<" ";
                if(k == 1)
                cout<<matriz2[i][j]<<" ";
                if(k == 2)
                cout<<matriz3[i][j]<<" ";
                if(k == 3)
                cout<<matriz4[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}