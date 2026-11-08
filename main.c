
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionarTarefas (char tarefas[100][100], int *totalTarefas, int concluida[100]);

int main()
{
    int opcao;
    char tarefas[100][100];
    int totalTarefas = 0;
    int concluida[100] = {0};

    do
    {
        system("cls");
        printf("Bem vindo ao DEV TASK\n");
        printf("=================================\n");
        printf("            DEV TASKS            \n");
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

        switch (opcao)
        {
        case 1:
            adicionarTarefas(tarefas, &totalTarefas, concluida);
            break;

        case 2:
            printf("\n========== MINHAS TAREFAS ==========\n\n");

            if (totalTarefas == 0)
            {
                printf("Nenhuma tarefa cadastrada.\n");
            }
            else
            {
                for (int i = 0; i < totalTarefas; i++)
                {
                    printf("[%d] %s - %s\n",
                           i + 1,
                           tarefas[i],
                           concluida[i] ? "Concluida" : "Pendente");
                }
            }
            break;

        case 3:
        {
            int numero;

            printf("\n========== CONCLUIR TAREFA ==========\n");

            if (totalTarefas == 0)
            {
                printf("\nNenhuma tarefa cadastrada.\n");
            }
            else
            {
                printf("\nDigite o numero da tarefa: ");
                scanf("%d", &numero);

                if (numero >= 1 && numero <= totalTarefas)
                {
                    concluida[numero - 1] = 1;
                    printf("\nTarefa concluida com sucesso!");
                }
                else
                {
                    printf("\nNumero de tarefa invalido!");
                }
            }
            break;
        }

        case 4:
        {
            int numero;

            printf("\n========== REMOVER TAREFA ==========\n");

            if (totalTarefas == 0)
            {
                printf("\nNenhuma tarefa cadastrada.\n");
            }
            else
            {
                printf("\nDigite o numero da tarefa: ");
                scanf("%d", &numero);

                if (numero >= 1 && numero <= totalTarefas)
                {
                    for (int i = numero - 1; i < totalTarefas - 1; i++)
                    {
                        strcpy(tarefas[i], tarefas[i + 1]);
                        concluida[i] = concluida[i + 1];
                    }

                    totalTarefas--;
                    printf("\nTarefa removida com sucesso!");
                }
                else
                {
                    printf("\nNumero de tarefa invalido!");
                }
            }
            break;
        }

        case 0:
            printf("\nEncerrando DevTasks...\n");
            break;

        default:
            printf("\nOpcao invalida!\n");
            break;
        }

        if (opcao != 0)
        {
            printf("\nPressione ENTER para continuar...");
            getchar();
            getchar();
        }

    } while (opcao != 0);

    printf("\nObrigado por usar o codigo!\n");
    return 0;
}

void adicionarTarefas (char tarefas[100][100], int *totalTarefas, int concluida[100])
{
    if (*totalTarefas < 100)
    {
        printf("\nDigite o nome da tarefa: ");
        scanf(" %99[^\n]", tarefas[*totalTarefas]);

        concluida[*totalTarefas] = 0;
        (*totalTarefas)++;

        printf("\nTarefa cadastrada com sucesso!");
    }
    else
    {
        printf("\nLimite de tarefas atingido!");
    }
}