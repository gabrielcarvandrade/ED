/*

Faça um programa que receba como entrada um tabuleiro de xadrez (matriz de 8x8 posições) e 
informe quais são as peças ameaçadas pela torre do jogador.

O tabuleiro será dado como uma matriz de 0s, 1s e 2s. Zeros representam posições sem peça. 
O número 1 representa uma torre (haverá somente uma torre no tabuleiro) e os números 2 representam 
outras peças (haverá zero ou mais peças representadas pelo número 2 no tabuleiro).

A torre pode ser movida na vertical ou na horizontal quantas casas quiser, mas não pode passar por 
cima de outra peça. As posições com outras peças que a torre pode tomar são posições ditas "ameaçadas" pela torre. A imagem abaixo mostra uma torre que ameça outras 3 peças (marcadas com um X).

Seu programa deve escrever as coordenadas (linha e coluna, nesta ordem) de cada peça 
(valor 2 na matriz) ameaçada pela torre (valor 1 na matriz).

Entradas:

    64 valores inteiros, dispostos na forma de uma matriz 8x8 de peças representadas 
    conforme explicado acima.

Saídas:

    As coordenadas (linha e depois coluna) de cada peça ameaçada, seguindo a ordem de leitura da 
    matriz, ou seja, da menor para a maior linha e da menor para maior coluna (de cima para baixo e 
    da esquerda para direita). As linhas e colunas começam em zero. Cada par de coordenadas deve 
    estar numa linha. Caso nenhuma peça seja ameaçada pela torre, o programa não deve escrever coisa 
    alguma.

Exemplo de entrada:

0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 2 0 0 0
2 2 0 0 1 0 2 2
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0

Exemplo de saída:

2 4
3 1
3 6

*/#include <iostream>

using namespace std;

int main()
{
    int tabuleiro[8][8];
    int i, j, linhaTorre, colunaTorre;

    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            cin >> tabuleiro[i][j];
            if (tabuleiro[i][j] == 1)
            {
                linhaTorre = i;
                colunaTorre = j;
            }
        }
    }

    // Verifica acima da torre
    for (i = linhaTorre - 1; i >= 0; i--)
    {
        if (tabuleiro[i][colunaTorre] != 0)
        {
            cout << i << " " << colunaTorre << endl;
            i = 0;
        }
    }

    // Verifica abaixo da torre
    for (i = linhaTorre + 1; i < 8; i++)
    {
        if (tabuleiro[i][colunaTorre] != 0)
        {
            cout << i << " " << colunaTorre << endl;
            i = 8;
        }
    }

    // Verifica à esquerda da torre
    for (j = colunaTorre - 1; j >= 0; j--)
    {
        if (tabuleiro[linhaTorre][j] != 0)
        {
            cout << linhaTorre << " " << j << endl;
            j = 0;
        }
    }

    // Verifica à direita da torre
    for (j = colunaTorre + 1; j < 8; j++)
    {
        if (tabuleiro[linhaTorre][j] != 0)
        {
            cout << linhaTorre << " " << j << endl;
            j = 8;
        }
    }

    return 0;
}