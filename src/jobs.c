#include "jobs.h"
#include "operations.h"

ListJobs *listJobs = NULL;
int nJobInput;

/**
 * @brief Faz print das opções disponiveis
 * 
 */
void jobMenu() {
    printf("--------------------------------------\n");
    printf("---------------  JOB-MENU  -------------\n");
    printf("--------------------------------------\n");
    printf("  [1] -> Inserir um novo Job\n");
    printf("  [2] -> Remover Job\n");
    printf("  [3] -> Alterar Job\n");
    printf("  [4] -> Listar Jobs\n");
    printf("  [5] -> Remover Job\n");
    printf("  [7] -> Proposta de escalonameto\n");
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
ListJobs *insertJobsAtBegin(int nJob, ListMachines *listmachines, ListJobs *list) {
    
    ListJobs *new = (ListJobs *)malloc(sizeof(ListJobs));
    
    if (new != NULL) {
        new->nJob = nJob;
        new->machineHead = listMachines;
        new->proximo = list;
        return(new);
    } else {
        return(list);
    }
}

/**
 * @brief Recebe todos os inputs do utilizador relativos a uma nova operação
 * 
 */
int newJobInputs() {

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
            
        if (verifyIfJobExist(nJobInput) == TRUE) {
            printf("Job ja existe!\n");
        }
                
    } while ((verifyInputValues(nJobInput) == FALSE) || (verifyIfJobExist(nJobInput) == TRUE));

    return nJobInput;
}

//Helpers
bool verifyIfJobExist(int jobNumber) {

    ListJobs *listHead = listJobs;

    if (listHead != NULL) {
        while(listHead != NULL) {

            if (listHead->nJob == jobNumber) {
                return TRUE;
            }
            listHead = listHead->proximo;
        }
    } else {
        return FALSE;
    }
}

void printListJobs(ListJobs *list) {
    
    ListJobs *listJobsHead = list;
    ListMachines *listHead = NULL;
    bool aux = FALSE;
    char option;

    
    do {
        if (listJobsHead != NULL) {

            while (listJobsHead != NULL) {

                printf("> Job: %d\n", listJobsHead->nJob);

                listHead = listJobsHead->machineHead;

                aux = FALSE;

                if (listHead != NULL) {

                    while (listHead != NULL) {

                        if (aux == FALSE) {
                            printf("    > Operacao: %d\n", listHead->nOperation);
                            aux = TRUE;
                        }

                        if (aux == TRUE) {
                            printf("        > maquina: %d, tempo: %d\n", listHead->nMachine, listHead->vTime);
                        }

                        if (listHead->proximo != NULL) {
                            if (listHead->nOperation != listHead->proximo->nOperation) {
                                aux = FALSE;
                            }
                        }
                        listHead = listHead->proximo;
                    }
                } else {
                    printf("    Nao existem operacoes para este job!\n");
                    aux = FALSE;
                }    
                listJobsHead = listJobsHead->proximo;
            }

        } else {
            printf("Nao existem jobs!\n");
        }

        printf("Pressione 'v' para voltar: ");
        scanf(" %c", &option);

    } while (option != 'v' && option != 'V');
    
}   
