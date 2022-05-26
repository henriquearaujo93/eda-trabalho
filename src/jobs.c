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
    printf("  [3] -> Editar Job\n");
    printf("  [4] -> Listar Jobs\n");
    printf("  [5] -> Proposta de escalonameto\n");
    printf("  [6] -> Salvar!\n");
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

ListJobs *alterarJob(int nJob) {

    ListJobs *listJobsHead = listJobs;

    bool result = FALSE;

    while (listJobsHead != NULL) {
        if (nJob == listJobsHead->nJob) {
            return listJobsHead;
            result = TRUE;
        }
        listJobsHead = listJobsHead->proximo;
    };

    if (result == FALSE) 
        return NULL;
}


//FUNCAO ADICIONAR TABELA DE JOBS
void addTableJobs() {
    for (int i = 1; i <= 8; i++) {
                listJobs = insertJobsAtBegin(i, NULL, listJobs);
                if (i == 1) { //Job 1
                    for (int j = 1; j <= 4; j++) { //Operations

                        if (j == 1) { //Op 1
                            listJobs->machineHead = insertAtBegin(j, 1, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 3, 5, listJobs->machineHead);
                        } else if (j == 2) {
                            listJobs->machineHead = insertAtBegin(j, 2, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 4, 5, listJobs->machineHead);
                        } else if (j == 3) {
                            listJobs->machineHead = insertAtBegin(j, 3, 5, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 5, 6, listJobs->machineHead);
                        } else if (j == 4) {
                            listJobs->machineHead = insertAtBegin(j, 4, 5, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 5, 5, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 6, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 7, 5, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 8, 9, listJobs->machineHead);
                        }
                    }
                } else if (i == 2) {
                    for (int j = 1; j <= 7; j++ ) {
                        if (j == 1) { //Op 1
                            listJobs->machineHead = insertAtBegin(j, 1, 1, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 3, 5, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 5, 7, listJobs->machineHead);
                        } else if (j == 2) {
                            listJobs->machineHead = insertAtBegin(j, 4, 5, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 8, 4, listJobs->machineHead);
                        } else if (j == 3) {
                            listJobs->machineHead = insertAtBegin(j, 4, 6, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 1, 6, listJobs->machineHead);
                        } else if (j == 4) {
                            listJobs->machineHead = insertAtBegin(j, 4, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 7, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 8, 7, listJobs->machineHead);
                        } else if (j == 5) {
                            listJobs->machineHead = insertAtBegin(j, 4, 1, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 6, 2, listJobs->machineHead);
                        } else if (j == 6) {
                            listJobs->machineHead = insertAtBegin(j, 1, 5, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 6, 6, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 8, 4, listJobs->machineHead);
                        } else if (j == 4) {
                            listJobs->machineHead = insertAtBegin(j, 4, 4, listJobs->machineHead);
                        }
                    }
                } else if (i == 3) {
                    for (int j = 1; j <= 5; j++) {
                        if (j == 1) { //Op 1
                            listJobs->machineHead = insertAtBegin(j, 2, 7, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 3, 6, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 8, 8, listJobs->machineHead);
                        } else if (j == 2) {
                            listJobs->machineHead = insertAtBegin(j, 4, 5, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 7, 7, listJobs->machineHead);
                        } else if (j == 3) {
                            listJobs->machineHead = insertAtBegin(j, 3, 7, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 5, 8, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 7, 7, listJobs->machineHead);
                        } else if (j == 4) {
                            listJobs->machineHead = insertAtBegin(j, 4, 7, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 6, 8, listJobs->machineHead);
                        } else if (j == 5) {
                            listJobs->machineHead = insertAtBegin(j, 1, 1, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 2, 4, listJobs->machineHead);
                        }
                    }
                } else if (i == 4) {
                    for (int j = 1; j <= 4; j++) {
                        if (j == 1) { //Op 1
                            listJobs->machineHead = insertAtBegin(j, 1, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 3, 3, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 5, 7, listJobs->machineHead);
                        } else if (j == 2) {
                            listJobs->machineHead = insertAtBegin(j, 2, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 8, 4, listJobs->machineHead);
                        } else if (j == 3) {
                            listJobs->machineHead = insertAtBegin(j, 3, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 4, 5, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 6, 6, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 7, 7, listJobs->machineHead);
                        } else if (j == 4) {
                            listJobs->machineHead = insertAtBegin(j, 5, 3, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 6, 5, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 8, 5, listJobs->machineHead);
                        }
                    }
                } else if (i == 5) {
                    for (int j = 1; j <= 5; j++) {
                        if (j == 1) { //Op 1
                            listJobs->machineHead = insertAtBegin(j, 1, 3, listJobs->machineHead);
                        } else if (j == 2) {
                            listJobs->machineHead = insertAtBegin(j, 2, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 4, 5, listJobs->machineHead);
                        } else if (j == 3) {
                            listJobs->machineHead = insertAtBegin(j, 3, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 8, 4, listJobs->machineHead);
                        } else if (j == 4) {
                            listJobs->machineHead = insertAtBegin(j, 5, 3, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 6, 3, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 8, 3, listJobs->machineHead);
                        } else if (j == 5) {
                            listJobs->machineHead = insertAtBegin(j, 4, 5, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 6, 4, listJobs->machineHead);
                        }
                    }
                } else if (i == 6) {
                    for (int j = 1; j <= 3; j++) {
                        if (j == 1) { //Op 1
                            listJobs->machineHead = insertAtBegin(j, 1, 3, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 2, 5, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 3, 6, listJobs->machineHead);
                        } else if (j == 2) {
                            listJobs->machineHead = insertAtBegin(j, 4, 5, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 7, 8, listJobs->machineHead);
                        } else if (j == 3) {
                            listJobs->machineHead = insertAtBegin(j, 3, 9, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 6, 8, listJobs->machineHead);
                        }
                    }
                } else if (i == 7) {
                    for (int j = 1; j <= 5; j++) {
                        if (j == 1) { //Op 1
                            listJobs->machineHead = insertAtBegin(j, 3, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 5, 5, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 6, 4, listJobs->machineHead);
                        } else if (j == 2) {
                            listJobs->machineHead = insertAtBegin(j, 4, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 7, 6, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 8, 4, listJobs->machineHead);
                        } else if (j == 3) {
                            listJobs->machineHead = insertAtBegin(j, 1, 3, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 3, 3, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 4, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 5, 5, listJobs->machineHead);
                        } else if (j == 4) {
                            listJobs->machineHead = insertAtBegin(j, 4, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 6, 6, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 8, 5, listJobs->machineHead);
                        } else if (j == 5) {
                            listJobs->machineHead = insertAtBegin(j, 1, 3, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 3, 3, listJobs->machineHead);
                        }
                    }
                } else if (i == 8) {
                    for (int j = 1; j <= 5; j++) {
                        if (j == 1) { //Op 1
                            listJobs->machineHead = insertAtBegin(j, 1, 3, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 2, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 6, 4, listJobs->machineHead);
                        } else if (j == 2) {
                            listJobs->machineHead = insertAtBegin(j, 4, 6, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 5, 5, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 8, 4, listJobs->machineHead);
                        } else if (j == 3) {
                            listJobs->machineHead = insertAtBegin(j, 3, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 7, 5, listJobs->machineHead);
                        } else if (j == 4) {
                            listJobs->machineHead = insertAtBegin(j, 4, 4, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 6, 6, listJobs->machineHead);
                        } else if (j == 5) {
                            listJobs->machineHead = insertAtBegin(j, 7, 1, listJobs->machineHead);
                            listJobs->machineHead = insertAtBegin(j, 8, 2, listJobs->machineHead);
                        }
                    }
                }
            }


}

void printListJobs2(ListJobs *list) {

    ListJobs *listJobsHead = list;

    while (listJobsHead != NULL) {

        printf("> Job: %d\n", listJobsHead->nJob);
        listJobsHead = listJobsHead->proximo;
    }
    
}

void removeJob(int nJob, ListJobs *jobsHead) {

    ListJobs *previousNode = NULL;
    ListJobs *nodeToRemove = NULL;
    ListJobs *listHead = jobsHead;
    bool removed = FALSE;
    char option;
                
    if (listHead != NULL && listHead->nJob == nJob) {

        while (listHead != NULL && listHead->nJob == nJob) {

            nodeToRemove = listHead;
            listHead = listHead->proximo;
            free(nodeToRemove);
            removed = TRUE;
        }
        listJobs = listHead;
    } 
    else
    {
        while (listHead != NULL) {                                                                                                                 
            if (listHead->nJob == nJob) {
                nodeToRemove = listHead;
                listHead = listHead->proximo;
                previousNode->proximo = listHead;
                free(nodeToRemove);
                removed = TRUE;
            } else {
                previousNode = listHead;
                listHead = listHead->proximo;
            }
        }
    }

    if (removed == TRUE) {
        printf("Job n %d removido com sucesso!\n", nJob);

    } else {
        printf("Nenhum job foi removido!\n");
    }

    printf("Pressione 'v' para voltar: ");

    do {
        scanf("%c", &option);
    } while (option != 'v' && option != 'V');
}


void saveJobOnTxt(ListJobs *list) {
    ListJobs *listHead = list;
    ListMachines *listMachineHead = NULL;


    //j o m t

    FILE *f = fopen("jobs.txt", "a");

    while (listHead != NULL) {

        listMachineHead = list->machineHead;

        while (listMachineHead != NULL) {
                
            fprintf(f, "%d,%d,%d,%d\n", listHead->nJob, listMachineHead->nOperation, listMachineHead->nMachine, 
                    listMachineHead->vTime);

            listMachineHead = listMachineHead->proximo;
        }

        listHead = listHead->proximo;
    }
    fclose(f);
}