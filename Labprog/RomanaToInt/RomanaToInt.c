/*
Laboratório de Programação - 21178 - 2022

       __                         ______                       _
      / /___  _________ ____     / ____/___  __  ___   _____  (_)___ _
 __  / / __ \/ ___/ __ `/ _ \   / / __/ __ \/ / / / | / / _ \/ / __ `/
/ /_/ / /_/ / /  / /_/ /  __/  / /_/ / /_/ / /_/ /| |/ /  __/ / /_/ /
\____/\____/_/   \__, /\___/   \____/\____/\__,_/ |___/\___/_/\__,_/
                /____/

2003777 - Jorge Gouveia
--------------------------------------Enunciado----------------------------
Conversor de numerais romanos.
Escreva um programa para converter um número em numeração romana para a notação decimal. Ex. MCMLXXIX = 1979.
Implemente um adequado tratamento de erros, que informe o utilizador de forma clara sobre o erro que cometeu na escrita do numeral romano (ex. usou uma letra não permitida como "P").
---------------------------------------------------------------------------

*/

#include <stdio.h>
#include <string.h>

#define MAX_BUF 255

void red()
{
    printf("\033[1;31m");
};

void yellow()
{
    printf("\033[1;33m");
};

void green()
{
    printf("\033[0;32m");
};

void reset()
{
    printf("\033[0m");
};

int checkvalida(int tam, char *str)
{

    int arabe = 0;

    for (int i = 0; i < tam; i++)
    {

        if ((str[i] == 'I') && (str[i + 1] == 'V'))
        {
            arabe = arabe + 4;
            i++;
        }
        else if ((str[i] == 'I') && (str[i + 1] == 'X'))
        { 
            arabe = arabe + 9;
            i++;
        }
        else if (str[i] == 'I')
        {
            arabe = arabe + 1;
        }
        else if (str[i] == 'V')
        {
            arabe = arabe + 5;
        }
        else if ((str[i] == 'X') && (str[i + 1] == 'C'))
        {
            arabe = arabe + 90;
            i++;
        }
        else if ((str[i] == 'X') && (str[i + 1] == 'L'))
        {
            arabe = arabe + 40;
            i++;
        }
        else if (str[i] == 'X')
        {
            arabe = arabe + 10;
        }
        else if (str[i] == 'L')
        {
            arabe = arabe + 50;
        }
        else if ((str[i] == 'C') && (str[i + 1] == 'D'))
        {
            arabe = arabe + 400;
            i++;
        }
        else if ((str[i] == 'C') && (str[i + 1] == 'M'))
        {
            arabe = arabe + 900;
            i++;
        }
        else if (str[i] == 'D')
        {
            arabe = arabe + 500;
        }
        else if (str[i] == 'C')
        {
            arabe = arabe + 100;
        }
        else if (str[i] == 'M')
        {
            arabe = arabe + 1000;
        }
        else
        {
            printf("\nA letra %c não é valida", str[i]);
            i = tam;
            return 0;
        }
    }
    return arabe;
};

void main()
{

    char str[MAX_BUF];
    int tam;
    int resultado;
    char exit;

    printf("\nBem vindo ao programa de conversao de Numeracao Romana para Inteiro\n\n");
    printf("Introduza o Valor para converter\n\n");

    fgets(str, MAX_BUF, stdin);
    tam = strlen(str) - 1;

    resultado = checkvalida(tam, str);

    if (resultado == 0)
    {
    }
    else
    {
        printf("\nResposta: ");
        green();
        printf("%d", resultado);
        reset();
        printf(" é o valor decimal de ");
        red();
        printf("%s\n", str);
        reset();
    };

    printf("Sair Y/N");
    scanf("%c"&exit);

    if (exit=='Y')
        exit();
    
}