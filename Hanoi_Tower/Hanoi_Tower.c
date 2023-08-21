#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int count = 0;
void towerR(int, char, char, char);

void main(int argc, char** argv)
{
    printf("\n\n\t\t\033[0;36m--------------------------[Torre hanoi]--------------------------\n\n\n");
    int n;
    int option;
    int from, to, k;


    printf("Introduza o numero de discos : \033[0m");
    scanf_s("%d", &n);
    printf("\n\n+---------[Sorting]---------+\n");
    printf("|\033[0;32m  1 - Recursive        \033[0m    |\n");
    printf("|\033[0;33m  2 - Iterative         \033[0m   |\n");
    printf("|\033[0;31m  3 - Sair           \033[0m      |\n");
    printf("+---------------------------+\n");
    printf("\n\033[0;36mintruduza o metodo que deseja usar:\033[0m");
    scanf_s("%d", &option);

    
    switch (option)
    {
    case 1:
       
        printf("\n\nAqui esta o esquema da torre de hanoi  :\n");
        clock_t begin1 = clock();
        // n = a numero de discos
        // a,b,c sao o nome dos paus
        towerR(n, 'A', 'C', 'B');     
        printf("\n\nNumero de movimentos: %d\n\n", count);
        clock_t end1 = clock();
        printf("O programa demorou: %f seconds\n", (double)(end1 - begin1) / CLOCKS_PER_SEC);
        break;

    case 2:

        if (argc > 1) n = atoi(argv[1]);
        clock_t begin2 = clock();
        for (k = 1; k < (1 << n); k++) {
            /* obtem haste origem */
            from = (k & (k - 1)) % 3;

            /* obtem haste destino */
            to = ((k | (k - 1)) + 1) % 3;

            /* descreve o movimento */
            printf("Mova disco de %d para %d\n", from, to);
            count += 1;
        }
        printf("\n\nNumero de movimentos: %d\n\n", count);
        clock_t end2 = clock();
        printf("O programa demorou: %f seconds\n", (double)(end2 - begin2) / CLOCKS_PER_SEC);
        break;

    case 3:
        exit(0);
  
    default:
        printf("Essa opcao nao existe");
        return 0;
    }
    
}
    void towerR(int no, char source, char destination, char spare)

    {
        //se so ha 1 disco
        if (no == 1)
        {
            count += 1;
            printf("\n mover disco 1 de %c para %c\n", source, destination);
            

            return;
        }

        towerR(no - 1, source, spare, destination);

        printf("\n mover disco %d de %c para %c\n", no, source, destination);
        count += 1;

        towerR(no - 1, spare, destination, source);

    }