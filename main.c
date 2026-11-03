#include <stdio.h> 
#include <stdlib.h>

int main() {

    int opcao;

    char tarefas[100][100];
    int totalTarefas = 0;

    do {

        system("cls");

        printf("=================================\n");
        printf("           DEV TASKS             \n");
        printf("      GERENCIADOR DE TAREFAS     \n");
        printf("=================================\n\n");

        printf(" [1] Adicionar tarefa\n");
        printf(" [2] Listar tarefas\n");
        printf(" [3] Concluir tarefa\n");
        printf(" [4] Remover tarefa\n");
        printf(" [0] Sair\n\n");

        printf("=================================\n");
        printf(" Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

           case 1:

    if (totalTarefas < 100) {

        printf("\nDigite o nome da tarefa: ");

        scanf(" %99[^\n]", tarefas[totalTarefas]);

        totalTarefas++;

        printf("\nTarefa cadastrada com sucesso!");

    } else {

        printf("\nLimite de tarefas atingido!");

    }

    break;

            case 2:
                printf("\nListar tarefas\n");
                break;

            case 3:
                printf("\nConcluir tarefa\n");
                break;

            case 4:
                printf("\nRemover tarefa\n");
                break;

            case 0:
                printf("\nEncerrando DevTasks...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }

        if (opcao != 0) {
            printf("\nPressione ENTER para continuar...");
            getchar();
            getchar();
        }

    } while (opcao != 0);

    return 0;
}