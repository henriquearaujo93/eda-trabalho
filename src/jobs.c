#include "jobs.h"
#include "operations.h"
#include <stdio.h>

ListJobs *listJobs = NULL;
int nJobInput;

/**
 * @brief Faz print das opções disponiveis
 *
 */
void jobMenu()
{
    printf("--------------------------------------\n");
    printf("---------------  JOB-MENU  -----------\n");
    printf("--------------------------------------\n");
    printf("  [1] -> Inserir um novo Job\n");
    printf("  [2] -> Remover Job\n");
    printf("  [3] -> Editar Job\n");
    printf("  [4] -> Listar Jobs\n");
    printf("  [5] -> Proposta de escalonameto\n");
    printf("  [6] -> Salvar!\n");
    printf("  [7] -> Carregar process plan\n");
    printf("  [8] -> Remover process plan\n");
    printf("  [0] -> Sair\n");
    printf("opcao: ");
}

/*-----  Manipulation List ---------------------------------------------------------------------------------------------------------
Funcoes para realizar a manipulação da lista
| insertAtBeginAndFile | -> Insere uma nova operação no começo da lista e no ficheiro txt
| insertAtBegin | -> Adiciona uma nova operação no começo da lista
| printListJobs | -> Lista todas os jobs inseridos
| insertAtBeginOp | -> Adiciona uma nova operação com a media das maquinas
| printOperations | -> Listar todas as operações existentes
| freeList | -> libera da memória todos os nós da lista de maquinas
| freeListAv | -> libera da memória todos os nós da lista de operações com a media
| removeOperation | -> Recebe o número de uma operação e remove a mesma
| editOperation | -> Recebe o número de uma operação e permite ao utilizador editar uma maquina da operação
*/
ListJobs *insertJobsAtBegin(int nJob, ListMachines *listmachines, ListJobs *list)
{

    ListJobs *new = (ListJobs *)malloc(sizeof(ListJobs));

    if (new != NULL)
    {
        new->nJob = nJob;
        new->machineHead = listMachines;
        new->proximo = list;
        return (new);
    }
    else
    {
        return (list);
    }
}

/**
 * @brief Recebe todos os inputs do utilizador relativos a uma nova operação
 *
 */
int newJobInputs()
{

    char opcao;

    system("clear");

    do
    {
        printf("Numero do Job(> 0): ");
        scanf("%d", &nJobInput);

        if (verifyInputValues(nJobInput) == FALSE)
        {
            printf("Valor invalido!\n");
        }

        if (verifyIfJobExist(nJobInput) == TRUE)
        {
            printf("Job ja existe!\n");
        }

    } while ((verifyInputValues(nJobInput) == FALSE) || (verifyIfJobExist(nJobInput) == TRUE));

    return nJobInput;
}

// Helpers
bool verifyIfJobExist(int jobNumber)
{

    ListJobs *listHead = listJobs;

    if (listHead != NULL)
    {
        while (listHead != NULL)
        {

            if (listHead->nJob == jobNumber)
            {
                return TRUE;
            }
            listHead = listHead->proximo;
        }
    }
    else
    {
        return FALSE;
    }
}

void printListJobs(ListJobs *list)
{

    ListJobs *listJobsHead = list;
    ListMachines *listHead = NULL;
    bool aux = FALSE;
    char option;

    do
    {
        if (listJobsHead != NULL)
        {

            while (listJobsHead != NULL)
            {

                printf("> Job: %d\n", listJobsHead->nJob);

                listHead = listJobsHead->machineHead;

                aux = FALSE;

                if (listHead != NULL)
                {

                    while (listHead != NULL)
                    {

                        if (aux == FALSE)
                        {
                            printf("    > Operacao: %d\n", listHead->nOperation);
                            aux = TRUE;
                        }

                        if (aux == TRUE)
                        {
                            printf("        > maquina: %d, tempo: %d\n", listHead->nMachine, listHead->vTime);
                        }

                        if (listHead->proximo != NULL)
                        {
                            if (listHead->nOperation != listHead->proximo->nOperation)
                            {
                                aux = FALSE;
                            }
                        }
                        listHead = listHead->proximo;
                    }
                }
                else
                {
                    printf("    Nao existem operacoes para este job!\n");
                    aux = FALSE;
                }
                listJobsHead = listJobsHead->proximo;
            }
        }
        else
        {
            printf("Nao existem jobs!\n");
        }

        printf("Pressione 'v' para voltar: ");
        scanf(" %c", &option);

    } while (option != 'v' && option != 'V');
}

ListJobs *alterarJob(int nJob)
{

    ListJobs *listJobsHead = listJobs;

    bool result = FALSE;

    while (listJobsHead != NULL)
    {
        if (nJob == listJobsHead->nJob)
        {
            return listJobsHead;
            result = TRUE;
        }
        listJobsHead = listJobsHead->proximo;
    };

    if (result == FALSE)
        return NULL;
}

// FUNCAO ADICIONAR TABELA DE JOBS
void addTableJobs()
{
    for (int i = 1; i <= 8; i++)
    {
        listJobs = insertJobsAtBegin(i, NULL, listJobs);
        if (i == 1)
        { // Job 1
            for (int j = 1; j <= 4; j++)
            { // Operations

                if (j == 1)
                { // Op 1
                    listJobs->machineHead = insertAtBegin(j, 1, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 3, 5, listJobs->machineHead);
                }
                else if (j == 2)
                {
                    listJobs->machineHead = insertAtBegin(j, 2, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 4, 5, listJobs->machineHead);
                }
                else if (j == 3)
                {
                    listJobs->machineHead = insertAtBegin(j, 3, 5, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 5, 6, listJobs->machineHead);
                }
                else if (j == 4)
                {
                    listJobs->machineHead = insertAtBegin(j, 4, 5, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 5, 5, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 6, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 7, 5, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 8, 9, listJobs->machineHead);
                }
            }
        }
        else if (i == 2)
        {
            for (int j = 1; j <= 7; j++)
            {
                if (j == 1)
                { // Op 1
                    listJobs->machineHead = insertAtBegin(j, 1, 1, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 3, 5, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 5, 7, listJobs->machineHead);
                }
                else if (j == 2)
                {
                    listJobs->machineHead = insertAtBegin(j, 4, 5, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 8, 4, listJobs->machineHead);
                }
                else if (j == 3)
                {
                    listJobs->machineHead = insertAtBegin(j, 4, 1, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 6, 6, listJobs->machineHead);
                }
                else if (j == 4)
                {
                    listJobs->machineHead = insertAtBegin(j, 4, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 7, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 8, 7, listJobs->machineHead);
                }
                else if (j == 5)
                {
                    listJobs->machineHead = insertAtBegin(j, 4, 1, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 6, 2, listJobs->machineHead);
                }
                else if (j == 6)
                {
                    listJobs->machineHead = insertAtBegin(j, 1, 5, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 6, 6, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 8, 4, listJobs->machineHead);
                }
                else if (j == 7)
                {
                    listJobs->machineHead = insertAtBegin(j, 4, 4, listJobs->machineHead);
                }
            }
        }
        else if (i == 3)
        {
            for (int j = 1; j <= 5; j++)
            {
                if (j == 1)
                { // Op 1
                    listJobs->machineHead = insertAtBegin(j, 2, 7, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 3, 6, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 8, 8, listJobs->machineHead);
                }
                else if (j == 2)
                {
                    listJobs->machineHead = insertAtBegin(j, 4, 7, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 8, 7, listJobs->machineHead);
                }
                else if (j == 3)
                {
                    listJobs->machineHead = insertAtBegin(j, 3, 7, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 5, 8, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 7, 7, listJobs->machineHead);
                }
                else if (j == 4)
                {
                    listJobs->machineHead = insertAtBegin(j, 4, 7, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 6, 8, listJobs->machineHead);
                }
                else if (j == 5)
                {
                    listJobs->machineHead = insertAtBegin(j, 1, 1, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 2, 4, listJobs->machineHead);
                }
            }
        }
        else if (i == 4)
        {
            for (int j = 1; j <= 4; j++)
            {
                if (j == 1)
                { // Op 1
                    listJobs->machineHead = insertAtBegin(j, 1, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 3, 3, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 5, 7, listJobs->machineHead);
                }
                else if (j == 2)
                {
                    listJobs->machineHead = insertAtBegin(j, 2, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 8, 4, listJobs->machineHead);
                }
                else if (j == 3)
                {
                    listJobs->machineHead = insertAtBegin(j, 3, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 4, 5, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 6, 6, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 7, 7, listJobs->machineHead);
                }
                else if (j == 4)
                {
                    listJobs->machineHead = insertAtBegin(j, 5, 3, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 6, 5, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 8, 5, listJobs->machineHead);
                }
            }
        }
        else if (i == 5)
        {
            for (int j = 1; j <= 5; j++)
            {
                if (j == 1)
                { // Op 1
                    listJobs->machineHead = insertAtBegin(j, 1, 3, listJobs->machineHead);
                }
                else if (j == 2)
                {
                    listJobs->machineHead = insertAtBegin(j, 2, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 4, 5, listJobs->machineHead);
                }
                else if (j == 3)
                {
                    listJobs->machineHead = insertAtBegin(j, 3, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 8, 4, listJobs->machineHead);
                }
                else if (j == 4)
                {
                    listJobs->machineHead = insertAtBegin(j, 5, 3, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 6, 3, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 8, 3, listJobs->machineHead);
                }
                else if (j == 5)
                {
                    listJobs->machineHead = insertAtBegin(j, 4, 5, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 6, 4, listJobs->machineHead);
                }
            }
        }
        else if (i == 6)
        {
            for (int j = 1; j <= 3; j++)
            {
                if (j == 1)
                { // Op 1
                    listJobs->machineHead = insertAtBegin(j, 1, 3, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 2, 5, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 3, 6, listJobs->machineHead);
                }
                else if (j == 2)
                {
                    listJobs->machineHead = insertAtBegin(j, 4, 7, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 5, 8, listJobs->machineHead);
                }
                else if (j == 3)
                {
                    listJobs->machineHead = insertAtBegin(j, 3, 9, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 6, 8, listJobs->machineHead);
                }
            }
        }
        else if (i == 7)
        {
            for (int j = 1; j <= 5; j++)
            {
                if (j == 1)
                { // Op 1
                    listJobs->machineHead = insertAtBegin(j, 3, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 5, 5, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 6, 4, listJobs->machineHead);
                }
                else if (j == 2)
                {
                    listJobs->machineHead = insertAtBegin(j, 4, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 7, 6, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 8, 4, listJobs->machineHead);
                }
                else if (j == 3)
                {
                    listJobs->machineHead = insertAtBegin(j, 1, 3, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 3, 3, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 4, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 5, 5, listJobs->machineHead);
                }
                else if (j == 4)
                {
                    listJobs->machineHead = insertAtBegin(j, 4, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 6, 6, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 8, 5, listJobs->machineHead);
                }
                else if (j == 5)
                {
                    listJobs->machineHead = insertAtBegin(j, 1, 3, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 3, 3, listJobs->machineHead);
                }
            }
        }
        else if (i == 8)
        {
            for (int j = 1; j <= 5; j++)
            {
                if (j == 1)
                { // Op 1
                    listJobs->machineHead = insertAtBegin(j, 1, 3, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 2, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 6, 4, listJobs->machineHead);
                }
                else if (j == 2)
                {
                    listJobs->machineHead = insertAtBegin(j, 4, 6, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 5, 5, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 8, 4, listJobs->machineHead);
                }
                else if (j == 3)
                {
                    listJobs->machineHead = insertAtBegin(j, 3, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 7, 5, listJobs->machineHead);
                }
                else if (j == 4)
                {
                    listJobs->machineHead = insertAtBegin(j, 4, 4, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 6, 6, listJobs->machineHead);
                }
                else if (j == 5)
                {
                    listJobs->machineHead = insertAtBegin(j, 7, 1, listJobs->machineHead);
                    listJobs->machineHead = insertAtBegin(j, 8, 2, listJobs->machineHead);
                }
            }
        }
    }
}

void printListJobs2(ListJobs *list)
{

    ListJobs *listJobsHead = list;

    while (listJobsHead != NULL)
    {

        printf("> Job: %d\n", listJobsHead->nJob);
        listJobsHead = listJobsHead->proximo;
    }
}

void removeJob(int nJob, ListJobs *jobsHead)
{

    ListJobs *previousNode = NULL;
    ListJobs *nodeToRemove = NULL;
    ListJobs *listHead = jobsHead;
    bool removed = FALSE;
    char option;

    if (listHead != NULL && listHead->nJob == nJob)
    {

        while (listHead != NULL && listHead->nJob == nJob)
        {

            nodeToRemove = listHead;
            listHead = listHead->proximo;
            free(nodeToRemove);
            removed = TRUE;
        }
        listJobs = listHead;
    }
    else
    {
        while (listHead != NULL)
        {
            if (listHead->nJob == nJob)
            {
                nodeToRemove = listHead;
                listHead = listHead->proximo;
                previousNode->proximo = listHead;
                free(nodeToRemove);
                removed = TRUE;
            }
            else
            {
                previousNode = listHead;
                listHead = listHead->proximo;
            }
        }
    }

    if (removed == TRUE)
    {
        printf("Job n %d removido com sucesso!\n", nJob);
    }
    else
    {
        printf("Nenhum job foi removido!\n");
    }

    printf("Pressione 'v' para voltar: ");

    do
    {
        scanf("%c", &option);
    } while (option != 'v' && option != 'V');
}

void saveJobOnTxt(ListJobs *list)
{
    ListJobs *listHead = list;
    ListMachines *listMachineHead = NULL;
    char jobName[100];
    const char *extension = ".process";
    char option3;

    if (listHead != NULL)
    {

        printf("Insira o nome do process plan:");
        scanf(" %s", jobName);

        FILE *f = fopen(strcat(jobName, extension), "w");

        while (listHead != NULL)
        {

            listMachineHead = listHead->machineHead;

            while (listMachineHead != NULL)
            {

                fprintf(f, "%d,%d,%d,%d\n", listHead->nJob, listMachineHead->nOperation, listMachineHead->nMachine, listMachineHead->vTime);

                listMachineHead = listMachineHead->proximo;
            }

            listHead = listHead->proximo;
        }

        fclose(f);

        printf("Jobs salvos com sucesso!\n");
    }
    else
    {
        printf("Não existem Jobs para serem guardados!\n");
    }

    fflush(stdin);

    printf("Pressione 'v' para voltar: ");

    do
    {
        scanf("%c", &option3);
    } while (option3 != 'v' && option3 != 'V');

    system("clear");
}

void loadJobsFromFile()
{

    int nJob, nOp, nMaq, vTime;
    char fileName[20];

    if (listJobs == NULL)
    {

        // Listar todos os ficheiros .process
        system("ls *.process");

        printf("Digite o nome do ficheiro: ");
        scanf(" %s", fileName);

        FILE *f = fopen(fileName, "r");

        if (f == NULL)
        {
            printf("Ficheiro nao encontrado\n");
        }
        else
        {

            while (!feof(f))
            {

                fscanf(f, "%d,%d,%d,%d\n", &nJob, &nOp, &nMaq, &vTime);

                if (!verifyIfJobExist(nJob))
                {
                    listJobs = insertJobsAtBegin(nJob, NULL, listJobs);
                }

                listJobs->machineHead = insertAtBegin(nOp, nMaq, vTime, listJobs->machineHead);
            }
            printf("Jobs salvos com sucesso na memoria!\n");
        }
    }
    else
    {
        printf("Ja existe um process plan na memoria, apagar existente antes de carregar um novo!\n");
    }

    printf("Pressione 'v' para voltar: ");

    char option;

    do
    {
        scanf(" %c", &option);

    } while (option != 'v' && option != 'V');

    system("clear");
}

void freeListJobs(ListJobs *list)
{
    ListJobs *aux = NULL;
    while (list != NULL)
    {
        aux = list;
        list = list->proximo;
        free(aux);
    }
    listJobs = NULL;
}

//------------------------------------Escalonamento-------------------------------------------//
ListescMachines *insertMachineEscAtBegin(int nMachine, ListescMachines *list)
{

    ListescMachines *new = (ListescMachines *)malloc(sizeof(ListescMachines));

    if (new != NULL)
    {
        new->nMachine = nMachine;
        new->escOperationHead = NULL;
        new->proximo = list;
        return (new);
    }
    else
    {
        return (list);
    }
}

ListescOperation *insertescOperationAtBegin(ListescMachines *machine, ListescOperation operation)
{

    ListescOperation *new = (ListescOperation *)malloc(sizeof(ListescOperation));

    memcpy(new, &operation, sizeof(operation));

    new->proximo = machine->escOperationHead;
    machine->escOperationHead = new;

    return new;
}

bool verifyIfMachineEscExist(int nMachine, ListescMachines *list)
{

    ListescMachines *listHead = list;

    while (list != NULL)
    {

        if (list->nMachine == nMachine)
        {
            return TRUE;
        }

        list = list->proximo;
    }
}

ListescMachines *criarListaMaquinas()
{

    int contador;
    ListJobs *listHead = listJobs;
    ListMachines *listMachineHead = NULL;
    ListescMachines *listescMachines = NULL;

    // Inserir a primeira maquina na lista
    listescMachines = insertMachineEscAtBegin(listHead->machineHead->nMachine, listescMachines);

    while (listHead != NULL)
    {

        listMachineHead = listHead->machineHead;

        while (listMachineHead != NULL)
        {

            // Verificar se maquina existe
            if (verifyIfMachineEscExist(listMachineHead->nMachine, listescMachines) == FALSE)
            {
                listescMachines = insertMachineEscAtBegin(listMachineHead->nMachine, listescMachines);
            }

            listMachineHead = listMachineHead->proximo;
        }

        listHead = listHead->proximo;
    }
    return listescMachines;
}

void escalonamento()
{
    int contador = 0;
    ListJobs *listJobsHead = listJobs;
    ListMachines *listMachinesHead = NULL;

    // Criar lista com o numero de maquinas existentes no process plan
    ListescMachines *listescMachines = criarListaMaquinas();
    ListescMachines *listescMachinesPrimeiro = listescMachines;
    ListescOperation *escOperationHead = NULL;
    bool maquinaLivre = TRUE;

    while (TRUE) //Só sera executado enquanto estiver maquina livre
    {

        listescMachines = listescMachinesPrimeiro;

        // Percorrer as maquinas todas
        while (listescMachines != NULL)
        {
            maquinaLivre = TRUE;
            escOperationHead = listescMachines->escOperationHead;

            // Verificar se a maquina está livre
            while (escOperationHead != NULL)
            {

                if (escOperationHead->end > contador)
                {
                    maquinaLivre = FALSE;
                }
                escOperationHead = escOperationHead->proximo;
            }

            if (maquinaLivre)
            {

                listJobsHead = listJobs;

                ListescOperation fastOperation;
                fastOperation.begin = -1;

                while (listJobsHead != NULL) //Percorrer todos os jobs
                {

                    ListescMachines *head = listescMachinesPrimeiro;
                    bool jobExiste = FALSE;

                    while (head != NULL) //Verificar se alguma maquina esta a executar alguma operacao neste trabalho
                    {

                        escOperationHead = head->escOperationHead;

                        if (escOperationHead != NULL) //Como a primeira operação da maquina será sempre a última porque insiro sempre no começo
                        {
                            if (escOperationHead->end > contador && escOperationHead->nJob == listJobsHead->nJob)
                            {
                                jobExiste = TRUE;
                            }
                        }

                        head = head->proximo;
                    }

                    if (jobExiste == FALSE) // se o job não está a ser executado por outra máquina
                    {

                        listMachinesHead = listJobsHead->machineHead;

                        int proximaOperacao = -1;

                        while (listMachinesHead != NULL) //Verificar qual a próxima operação
                        {

                            if (listMachinesHead->nOperation < proximaOperacao || proximaOperacao == -1)
                            {
                                proximaOperacao = listMachinesHead->nOperation;
                            }
                            listMachinesHead = listMachinesHead->proximo;
                        }

                        listMachinesHead = listJobsHead->machineHead;

                        while (listMachinesHead != NULL) //Procurar a operação com menor tempo para a maquina atual
                        {

                            if (listMachinesHead->nOperation == proximaOperacao && listMachinesHead->nMachine == listescMachines->nMachine)
                            {

                                if (fastOperation.begin == -1 || fastOperation.time > listMachinesHead->vTime)
                                {

                                    fastOperation.begin = contador;
                                    fastOperation.time = listMachinesHead->vTime;
                                    fastOperation.end = contador + listMachinesHead->vTime;
                                    fastOperation.nOperation = listMachinesHead->nOperation;
                                    fastOperation.nJob = listJobsHead->nJob;
                                }
                            }

                            listMachinesHead = listMachinesHead->proximo;
                        }
                    }

                    listJobsHead = listJobsHead->proximo;
                }

                if (fastOperation.begin != -1)
                {
                    insertescOperationAtBegin(listescMachines, fastOperation);

                    removeOperation2(fastOperation.nOperation, alterarJob(fastOperation.nJob));
                }
            }

            listescMachines = listescMachines->proximo;
        }

        listescMachines = listescMachinesPrimeiro; // Volta ao inicio da lista

        maquinaLivre = TRUE;

        while (listescMachines != NULL)
        {

            escOperationHead = listescMachines->escOperationHead;

            while (escOperationHead != NULL)
            {

                if (escOperationHead->end > contador)
                {
                    maquinaLivre = FALSE;
                }
                escOperationHead = escOperationHead->proximo;
            }

            listescMachines = listescMachines->proximo;
        }

        if (maquinaLivre == TRUE)
        {
            break;
        }

        contador++;
    }

    // Save on file
    listescMachines = listescMachinesPrimeiro;

    char *jobName;

    FILE *f = fopen("escalonamento.yaml", "w");

    while (listescMachines != NULL)
    {
        escOperationHead = listescMachines->escOperationHead;

        fprintf(f, "- Maquina %d:\n", listescMachines->nMachine);


        while (escOperationHead != NULL)
        {
            
            fprintf(f, "\t- %d:\n\t\ttrabalho: %d\n\t\toperacao: %d\n\t\tduracao: %d\n\t\tfim: %d\n",escOperationHead->begin, escOperationHead->nJob, escOperationHead->nOperation, escOperationHead->time,
                escOperationHead->end);
            escOperationHead = escOperationHead->proximo;
        }

        listescMachines = listescMachines->proximo;
    }

    fprintf(f, "- TEMPO: %d\n", contador);

    fclose(f);

    system("clear");
    printf("TEMPO: %d\n", contador);

    char opcao;

    printf("Ficheiro de escalonamento salvo com sucesso!\n");

    do {

        printf("Pressione 'v' para voltar:");
        scanf(" %c", &opcao);

    } while (opcao != 'v' && opcao != 'V');

    system("clear");

}
