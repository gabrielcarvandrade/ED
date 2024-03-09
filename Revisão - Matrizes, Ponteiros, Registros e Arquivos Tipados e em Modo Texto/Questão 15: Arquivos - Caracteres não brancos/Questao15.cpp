/*

Faça um programa que abra um arquivo texto chamado "Meu_Arquivo.txt" e conte o 
número de caracteres não brancos nele. Escreva o resultado da contagem na saída padrão.

Entrada:

    O arquivo de texto "Meu_Arquivo.txt".

Saída:

    Número de caracteres não brancos dentro do arquivo.

Exemplo de arquivo:

Vou aproveitar os exercicios do dredd para estudar muito e tirar 100 em IALG!!

Exemplo de saída:

65

*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string arquivoIn = "Meu_Arquivo.txt";
    ifstream arquivo(arquivoIn); 
    if (arquivo.is_open()) 
    {
        int contCaracteres = 0;
        char c;
        while (arquivo.get(c))
        {
            if (c != ' ' and c != '\n' and c != '\t')
                contCaracteres++;
        }
        cout << contCaracteres << endl;
    }
    else
    {
        cout << "O arquivo não foi encontrado." << endl;
    }

    return 0;
}