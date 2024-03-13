/*

Uma escola resolveu criar um sistema para fazer o registro de notas dos seus alunos.
Para isso, você deve criar um programa que recebe as seguintes informações: número
total de alunos e para cada aluno o nome, número de matrícula e nota final do mesmo.
É garantido que os dados serão fornecidos em ordem crescente de matrícula.
Esses dados devem ser gravados em um arquivo tipado chamado de "alunos.bin".

A seguir, o programa recebe dois números de matrícula. O seu programa deve:
buscar o aluno no arquivo tipado com o primeiro número de matrícula (busca binária).
Em seguida, alterar esse campo para o segundo número de matrícula fornecido.
Esse registro agora deve ser reposicionado para manter a ordem do arquivo tipado.
Para isso, deve-se deslocar as posições dos registros no arquivo.
No final, um relatório contendo o nome e nota de cada aluno, na mesma ordem que
aparecem no arquivo tipado deve ser gerado na tela.

OBS: Não é permitida a utilização de vetores ou matrizes nesse programa.

Entradas:

    Número de Alunos - (inteiro)
    Sequência de dados de aluno: nome (sem espaco), matrícula, nota - (string, inteiro, real)
    matrícula do registro que deve ser modificado
    nova matrícula

Saídas:

    Lista de alunos ordenada (nome, nota)

Exemplo de Entrada:

3
Joao 1010 80.0
Paulo 1020 85.0
Ana 1030 90.5
1030 1000

Exemplo de Saída:

Ana 90.5
Joao 80.0
Paulo 85.0

*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//struct para armazenar os dados dos alunos
struct Aluno
{
    string nome;
    int matricula;
    float nota;
};

int main()
{
    int numAlunos;
    cin >> numAlunos;
    Aluno aluno;
    fstream file;
    //abre o arquivo para escrita (out) e em modo binário (binary)
    file.open("alunos.bin", ios::out | ios::binary);
    //escreve os dados dos alunos no arquivo
    for (int i = 0; i < numAlunos; i++)
    {
        cin >> aluno.nome >> aluno.matricula >> aluno.nota;
        file.write((char *)&aluno, sizeof(Aluno));
    }
    file.close();
    int matricula, novaMatricula;
    cin >> matricula >> novaMatricula;
    //abre o arquivo para leitura (in) ou para escrita (out) e em modo binário (binary)
    file.open("alunos.bin", ios::in | ios::out | ios::binary);
    //calcula o tamanho do arquivo
    file.seekg(0, ios::end);
    int tam = file.tellg();
    int numRegistros = tam / sizeof(Aluno);
    int inicio = 0;
    int fim = numRegistros - 1;
    int meio;
    //busca binária
    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        file.seekg(meio * sizeof(Aluno));
        file.read((char *)&aluno, sizeof(Aluno));
        if (aluno.matricula == matricula)
        {
            aluno.matricula = novaMatricula;
            file.seekp(meio * sizeof(Aluno));
            file.write((char *)&aluno, sizeof(Aluno));
        }
        else if (aluno.matricula < matricula)
        {
            inicio = meio + 1;
        }
        else
        {
            fim = meio - 1;
        }
    }
    file.close();
    //abre o arquivo para leitura (in) e em modo binário (binary)
    file.open("alunos.bin", ios::in | ios::binary);
    //imprime os dados dos alunos em ordem crescente de matrícula
    
    
    file.close();
    return 0;
}
