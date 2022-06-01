#include "operations.h"
#include "jobs.h"

/*-----  Variaveis Globais ---------------------------------------------------------------------------------------------------------
Declaração de todas as variaveis globais que serão utilizadas
| *listOperations | -> Novo apontador para uma nova lista de operações
| nOperationInput, nMachineInput, vTimeINput | -> Variaveis de recolha de inputs pelo utilizador
*/
ListMachines *listMachines = NULL; //Declaração de uma nova lista de Operações
int nOperationInput;
int nMachineInput;
int vTimeInput;

/*-----  Manipulation List ---------------------------------------------------------------------------------------------------------
Funcoes para realizar a manipulação da lista
| insertAtBeginAndFile | -> Insere uma nova operação no começo da lista e no ficheiro txt
| insertAtBegin | -> Adiciona uma nova operação no começo da lista
| printListMachines | -> Lista todas as operacoes inseridas com suas maquinas
| insertAtBeginOp | -> Adiciona uma nova operação com a media das maquinas
| printOperations | -> Listar todas as operações existentes
| freeList | -> libera da memória todos os nós da lista de maquinas
| freeListAv | -> libera da memória todos os nós da lista de operações com a media   
| removeOperation | -> Recebe o número de uma operação e remove a mesma
| editOperation | -> Recebe o número de uma operação e permite ao utilizador editar uma maquina da operação
*/

/**
 * @brief Insere uma nova operação no começo da lista e no ficheiro txt
 * 
 * @param nOperation 
 * @param nMachine 
 * @param vTime 
 * @param list 
 * @return ListMachines* 
 */
ListMachines *insertAtBeginAndFile(int nOperation, int nMachine, int vTime, ListMachines *list) {
    
    ListMachines *new = (ListMachines *)malloc(sizeof(ListMachines));
    
    if (new != NULL) {

        new->nOperation = nOperation;
        new->nMachine = nMachine;
        new->inUse = FALSE;
        new->vTime = vTime;
        new->proximo = list;

        //Save in file
        saveJob(nOperation, nMachine, vTime);

        return(new);
    } else {
        return(list);
    }
}

/**
 * @brief Adiciona uma nova operação no começo da lista
 * 
 * @param nOperation 
 * @param nMachine 
 * @param vTime 
 * @param list 
 * @return ListMachines* 
 */
ListMachines *insertAtBegin(int nOperation, int nMachine, int vTime, ListMachines *list) {
    
    ListMachines *new = (ListMachines *)malloc(sizeof(ListMachines));
    
    if (new != NULL) {
        new->nOperation = nOperation;
        new->nMachine = nMachine;
        new->vTime = vTime;
        new->proximo = list;
        return(new);
    } else {
        return(list);
    }
}

ListMachines *insertAtBegin2(int nOperation, int nMachine, int vTime, ListMachines *list) {
    
    ListMachines *new = (ListMachines *)malloc(sizeof(ListMachines));
    
    if (new != NULL && list->nOperation == nOperation) {
        new->nOperation = nOperation;
        new->nMachine = nMachine;
        new->vTime = vTime;
        new->proximo = list;
        return(new);
    } else {
        return(list);
    }
}

/**
 * @brief Adiciona uma nova operação com a media das maquinas
 * 
 * @param nOperation 
 * @param vTime 
 * @param list 
 * @return ListAverageOp* 
 */
ListAverageOp *insertAtBeginOp(int nOperation, float vTime, ListAverageOp *list) {
    
    ListAverageOp *new = (ListAverageOp *)malloc(sizeof(ListAverageOp));
    
    if (new != NULL) {

        new->nOperation = nOperation;
        new->vTime = vTime;
        new->proximo = list;

        return(new);
    } else {
        return(list);
    }
}

/**
 * @brief Lista todas as operacoes inseridas com suas maquinas
 * 
 * @param list 
 */
void printListMachines(ListMachines *list) {   
    ListMachines *listHead = list;
    bool aux = FALSE;
    char option;

    do {

        if (listHead != NULL) {

            while (listHead != NULL) {

                if (aux == FALSE) {
                    printf("> Operacao: %d\n", listHead->nOperation);
                    aux = TRUE;
                }

                if (aux == TRUE) {
                    printf("    > maquina: %d, tempo: %d\n", listHead->nMachine, listHead->vTime);
                }

                if (listHead->proximo != NULL) {
                    if (listHead->nOperation != listHead->proximo->nOperation) {
                        aux = FALSE;
                    }
                }
                listHead = listHead->proximo;
            }
        } else {
            printf("Nao existem operacoes!\n");
        } 

        printf("Pressione 'v' para voltar: ");
        scanf(" %c", &option);

    } while (option != 'v' && option != 'V');
}   

void printListMachines2(ListMachines *list) {   
    ListMachines *listHead = list;
    bool aux = FALSE;
    char option;

    while (listHead != NULL) {
        if (aux == FALSE) {
            printf("> Operacao: %d\n", listHead->nOperation);
            aux = TRUE;
        }
        if (aux == TRUE) {
            printf("    > maquina: %d, tempo: %d\n", listHead->nMachine, listHead->vTime);
        }
        if (listHead->proximo != NULL) {
            if (listHead->nOperation != listHead->proximo->nOperation) {
                aux = FALSE;
            }
        }
        listHead = listHead->proximo;
    }
}

void printListMachines3(ListMachines *list) {   
    ListMachines *listHead = list;
    bool aux = FALSE;
    char option;

    while (listHead != NULL) {
        if (aux == FALSE) {
            printf("> Operacao: %d\n", listHead->nOperation);
            aux = TRUE;
        }
        if (listHead->proximo != NULL) {
            if (listHead->nOperation != listHead->proximo->nOperation) {
                aux = FALSE;
            }
        }
        listHead = listHead->proximo;
    }
}

bool printListMachines4(int nOperation, ListMachines *list) {

    ListMachines *listHead = list;
    bool aux = FALSE;
    char option;
    bool result = FALSE;

    while (listHead != NULL) {
        if (listHead->nOperation == nOperation) {
            printf("> machine: %d, tempo: %d\n", listHead->nMachine, listHead->vTime);
            result = TRUE;
        }
        listHead = listHead->proximo;
    }

    if (result == FALSE) {
        return FALSE;
    } else {
        return TRUE;
    }

}




/**
 * @brief Listar todas as operações existentes
 * 
 * @param list 
 * @param nOperation 
 */
void printOperationMachines(ListMachines *list, int nOperation) {

    ListMachines *listHead = list;
    bool aux = FALSE;
    char option;

    if (listHead != NULL) {

        while (listHead != NULL && listHead->nOperation == nOperation) {

            if (aux == FALSE) {
                printf("> Operacao: %d\n", listHead->nOperation);
                aux = TRUE;
            }

            if (aux == TRUE) {
                printf("    > maquina: %d, tempo: %d\n", listHead->nMachine, listHead->vTime);
            }

            if (listHead->proximo != NULL) {
                if (listHead->nOperation != listHead->proximo->nOperation) {
                    aux = FALSE;
                }
            }
            listHead = listHead->proximo;
        }
    } else {
        printf("Nao existem operacoes!\n");
    } 

}

/**
 * @brief libera da memória todos os nós da lista de maquinas
 * 
 * @param list 
 */
void freeList(ListMachines *list) {
    ListMachines *aux = NULL;
    while (list != NULL) {
        aux = list;
        list = list->proximo;
        free(aux);
    }
}

/**
 * @brief libera da memória todos os nós da lista de operações com a media
 * 
 * @param list 
 */
void freeListAv(ListAverageOp *list) {
    ListAverageOp *aux = NULL;
    while (list != NULL) {
        aux = list;
        list = list->proximo;
        free(aux);
    }
}

/**
 * @brief Recebe o número de uma operação e remove a mesma
 * 
 * @param nOperation 
 */
void removeOperation(int nOperation, ListJobs *job) {

    ListMachines *previousNode = NULL;
    ListMachines *nodeToRemove = NULL;
    ListMachines *listHead = job->machineHead;
    ListMachines *listHead2 = NULL;
    bool removed = FALSE;
    char option;
                
    if (listHead != NULL && listHead->nOperation == nOperation) {

        while (listHead != NULL && listHead->nOperation == nOperation) {

            nodeToRemove = listHead;
            listHead2 = nodeToRemove->proximo;
            listHead = listHead->proximo;
            free(nodeToRemove);
            removed = TRUE;
            job->machineHead = listHead;
        }
    } 
    else
    {
        while (listHead != NULL) {                                                                                                                 
            if (listHead->nOperation == nOperation) {
                nodeToRemove = listHead;
                listHead2 = nodeToRemove->proximo;
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

    //Loop para reordenar numero das operacoes
    listHead = job->machineHead;
    while (listHead != NULL && listHead->nOperation != (nOperation - 1)) {
        listHead->nOperation = listHead->nOperation - 1;
        listHead = listHead->proximo;
    }

    if (removed == TRUE) {
        printf("Operacao n %d removida com sucesso!\n", nOperation);
    } else {
        printf("Nenhuma operacao foi removida!\n");
    }

    printf("Pressione 'v' para voltar: ");

    do {
        scanf("%c", &option);
    } while (option != 'v' && option != 'V');
}

void removeOperation2(int nOperation, ListJobs *job) {

    ListMachines *previousNode = NULL;
    ListMachines *nodeToRemove = NULL;
    ListMachines *listHead = job->machineHead;
    ListMachines *listHead2 = NULL;
    bool removed = FALSE;
    char option;
                
    if (listHead != NULL && listHead->nOperation == nOperation) {

        while (listHead != NULL && listHead->nOperation == nOperation) {

            nodeToRemove = listHead;
            listHead2 = nodeToRemove->proximo;
            listHead = listHead->proximo;
            free(nodeToRemove);
            removed = TRUE;
            job->machineHead = listHead;
        }
    } 
    else
    {
        while (listHead != NULL) {                                                                                                                 
            if (listHead->nOperation == nOperation) {
                nodeToRemove = listHead;
                listHead2 = nodeToRemove->proximo;
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

    //Loop para reordenar numero das operacoes
    listHead = job->machineHead;
    while (listHead != NULL && listHead->nOperation != (nOperation - 1)) {
        listHead->nOperation = listHead->nOperation - 1;
        listHead = listHead->proximo;
    }
}

/**
 * @brief Recebe o número de uma operação e permite ao utilizador editar uma maquina da operação
 * 
 * @param nOperation 
 */
void editOperation(int nOperation, ListMachines *listMachinesHead) {

    ListMachines *listHead = listMachinesHead;
    char option;
    bool aux = FALSE;
    int newMachineNumber, newTimeNumber, machineToEdit;

    do {

        while (listHead != NULL && listHead->nOperation != nOperation) {
            listHead = listHead->proximo;
        }
    
        if (listHead != NULL) {

            //Print maquinas para a operacao
            printOperationMachines(listHead, nOperation);

            //Descobrir a maquina
            do {
                printf("Qual maquina que deseja editar:");
                scanf("%d", &machineToEdit);

                if (verifyInputValues(machineToEdit) == FALSE) {
                    printf("Insira um numero maior que 0!\n");
                }

            } while ((verifyInputValues(machineToEdit) == FALSE));

            while (listHead != NULL && listHead->nMachine != machineToEdit) {
                listHead = listHead->proximo;
            }

            if (listHead != NULL) {

                do {
                    printf("Novo numero: ");
                    scanf("%d", &newMachineNumber);

                    if (verifyInputValues(newMachineNumber) == FALSE) {
                        printf("Valor invalido, insira um valor maior que 0\n");
                    }

                    if (verifyIfMachineExistInOperation(nOperation, newMachineNumber, listMachinesHead) == TRUE && (listHead->nMachine != newMachineNumber)) {
                        printf("Maquina ja existe!\n");
                        aux = TRUE;
                    } else {
                        aux = FALSE;
                    } 

                } while ((verifyInputValues(newMachineNumber) == FALSE) || (aux == TRUE));

                do {
                    printf("Novo tempo: ");
                    scanf("%d", &newTimeNumber);

                    if (verifyInputValues(newTimeNumber) == FALSE)
                        printf("Valor invalido, insira um valor maior que 0\n ");
                }while (verifyInputValues(newTimeNumber) == FALSE);

                listHead->nMachine = newMachineNumber;
                listHead->vTime = newTimeNumber;

                remove("job.txt");
                saveJobFromList(listMachines);

            } else {
                printf("Nao existe maquina com o n: %d\n", machineToEdit);
            }

        } else {
            printf("Nao existem operacao com o n: %d\n", nOperation);
        }

        printf("Pressione 'v' para voltar:");
        scanf(" %c", &option);
        
    } while (option != 'v' && option != 'V');
}

/*-----  Helpers  ------------------------------------------------------------------------------------------------------------------
Funcoes para realizar tarefas de verificação e afins
| verifyInputValues | -> Recebe um inteiro e verifica se é maior que 0
| verifyIfOperationExist | -> Recebe o numero da operacao e verifica se esta ja existe
| verifyIfMachineExistInOperation | -> Recebe o valor da operacao e da maquina e verifica se esta maquina ja esta inserida na operacao
| findPreviousNode | -> Recebe o valor da operacao e da maquina e verifica se esta maquina ja esta inserida na operacao
| sumMachineTime -> retorna a soma a unidade de tempo de todas as maquinas da operação
| verifyIfFileExist| -> Verifica se um determinado ficheiro existe
*/

/**
 * @brief Recebe um inteiro e verifica se é maior que 0
 * 
 * @param input 
 * @return true 
 * @return false 
 */
bool verifyInputValues(int input) {
    if (input > 0)
    {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * @brief Recebe o numero da operacao e verifica se esta ja existe
 * 
 * @param operationNumber 
 * @return true 
 * @return false 
 */
bool verifyIfOperationExist(int operationNumber, ListMachines *listMachineHead) {

    ListMachines *listHead = listMachineHead;

    if (listHead != NULL) {
        while(listHead != NULL) {

            if (listHead->nOperation == operationNumber) {
                return TRUE;
            }
            listHead = listHead->proximo;
        }
    } else {
        return FALSE;
    }
}

/**
 * @brief Recebe o valor da operacao e da maquina e verifica se esta maquina ja esta inserida na operacao
 * 
 * @param operationNumber 
 * @param machineNumber 
 * @return true 
 * @return false 
 */
bool verifyIfMachineExistInOperation(int operationNumber, int machineNumber, ListMachines *listMachinesHead) {

    ListMachines *listHead = listMachinesHead;

    if (listHead != NULL) {
        while(listHead != NULL) {
           if (listHead->nOperation == operationNumber) {
               if (listHead->nMachine == machineNumber) {
                   return TRUE;
                }
           }
           listHead = listHead->proximo;
        }
    } else {
        return FALSE;
    }
}

/**
 * @brief Encontra o nó anterior de uma operação
 * 
 * @param nOperation 
 * @param listMachines 
 * @return ListMachines* 
 */
ListMachines *findPreviousNode(int nOperation, ListMachines *listMachines) {

    ListMachines *previousNode = NULL;
    ListMachines *currentNode = listMachines;

    while(currentNode != NULL) {

        if (currentNode->nOperation == nOperation) {
            return previousNode;
        }
        
        previousNode = currentNode;
        currentNode = currentNode->proximo;
    }
}

/**
 * @brief Retorna a soma a unidade de tempo de todas as maquinas da operação
 * 
 * @param list 
 * @return int 
 */
int sumMachineTime(ListMachines *list) {

    ListMachines *listHead = list;
    int sum;

    while (listHead != NULL) {
        sum += listHead->vTime;
        listHead = listHead->proximo;
    }

    return sum;
}

/**
 * @brief Verifica se um determinado ficheiro existe
 * 
 * @param fileName 
 * @return true 
 * @return false 
 */
bool verifyIfFileExist(char *fileName) {

    FILE *f;

    if (f = fopen(fileName, "r")) {
        fclose(f);
        return TRUE;
    } else {
        return FALSE;
    }
}

/*-----  Views and Inputs  ------------------------------------------------------------------------------------------------
Menus de visualização e processos de scanf estão aqui:
| printMenu | -> Faz print das opções disponiveis
| newOperationInputs | -> Recebe todos os inputs do utilizador relativos a uma nova operação
*/

/**
 * @brief Faz print das opções disponiveis
 * 
 */
void printMenu(ListJobs *job) {
    printf("---------------------------------------------\n");
    printf("---------------  JOB -> [%d]  ---------------\n", job->nJob);
    printf("---------------------------------------------\n");
    printf("  [1] -> Inserir nova Operacao\n");
    printf("  [2] -> Remover Operacao\n");
    printf("  [3] -> Alterar Operacao\n");
    printf("  [4] -> Quantidade minima e listagem\n");
    printf("  [5] -> Quantidade maxima e listagem\n");
    printf("  [6] -> Quantidade media\n");
    printf("  [7] -> Ver operacoes\n");
    printf("  [8] -> Adicionar maquina\n");
    printf("  [9] -> Remover maquina\n");
    printf("  [0] -> Voltar\n");
    printf("opcao: ");
}

/**
 * @brief Recebe todos os inputs do utilizador relativos a uma nova operação
 * 
 */
void newMachineInputs(ListJobs *job) {

    char opcao;

    system("clear");

    do
    {
        printf("Numero operacao(> 0): ");
        scanf("%d", &nOperationInput);

        if (verifyInputValues(nOperationInput) == FALSE)
        {
            printf("Valor invalido!\n");
        }
            
        if (verifyIfOperationExist(nOperationInput, job->machineHead) == TRUE) {
            printf("Operacao ja existe!\n");
        }
                
    } while ((verifyInputValues(nOperationInput) == FALSE) || (verifyIfOperationExist(nOperationInput, job->machineHead) == TRUE));

    do {
        system("clear");

        do {
            printf("Numero Maquina: ");
            scanf("%d", &nMachineInput);

            if (verifyInputValues(nMachineInput) == FALSE) {
                printf("Valor invalido, insira um valor maior que 0\n");
            } else if(verifyIfMachineExistInOperation(nOperationInput, nMachineInput, job->machineHead) == TRUE) {
                printf("Maquina ja existe!\n");
            }
        } while ((verifyInputValues(nMachineInput) == FALSE) || (verifyIfMachineExistInOperation(nOperationInput, nMachineInput, job->machineHead) == TRUE));

        do {
            printf("Tempo: ");
            scanf("%d", &vTimeInput);

            if (verifyInputValues(vTimeInput) == FALSE)
                printf("Valor invalido, insira um valor maior que 0\n ");

        } while (verifyInputValues(vTimeInput) == FALSE);

        job->machineHead = insertAtBegin(nOperationInput, nMachineInput, vTimeInput, job->machineHead);

        if (job->machineHead != NULL) {
            printf("Nova maquina inserida com sucesso!\n");
        } else {
            printf("Erro ao inserir maquina!!");
        }

        do {
            printf("Deseja inserir (s/n): ");
            scanf(" %c", &opcao);
        } while (opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N');

    } while(opcao == 's' || opcao == 'S');
}


/**
 * @brief Remover máquina da lista de operações
 * 
 */
void removeMachine(int nMachine, int nOperationInput, ListJobs *job) {
    char opcao;

    ListMachines *previousNode = NULL;
    ListMachines *nodeToRemove = NULL;
    ListMachines *listHead = job->machineHead;
    bool removed = FALSE;
    char option;
                
    if (listHead != NULL && listHead->nOperation == nOperationInput && listHead->nMachine == nMachine) {

        while (listHead != NULL && listHead->nMachine == nMachine) {

            nodeToRemove = listHead;
            listHead = listHead->proximo;
            free(nodeToRemove);
            removed = TRUE;
        }
        job->machineHead = listHead;
    } 
    else
    {
        while (listHead != NULL) {                                                                                                                 
            if (listHead->nMachine == nMachine && listHead->nOperation == nOperationInput) {
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
        printf("Maquina n %d removida com sucesso!\n", nMachine);
    } else {
        printf("Nenhuma maquina foi removida!\n");
    }

    printf("Pressione 'v' para voltar: ");

    do {
        scanf("%c", &option);
    } while (option != 'v' && option != 'V');
}

/*-----  Calculos  ------------------------------------------------------------------------------------------------
Todos os cálculos estção aqui:
| MinimumAmountOfTime | -> Percorre a lista principal e cria uma nova somente com as maquinas de menor tempo e apresenta o resultado;
| MaximumAmountOfTime | -> Percorre a lista principal e cria uma nova somente com as maquinas de maior tempo e apresenta o resultado;
| averageOperationTime | -> Percorre a lista principal e cria uma nova somente com as as medias das operações;
*/

/**
 * @brief Percorre a lista principal e cria uma nova somente com as maquinas de menor tempo e apresenta o resultado;
 * 
 */
void minimumAmountOfTime(ListMachines *listMachines) {

    ListMachines *listHead = listMachines;
    ListMachines *aux = listMachines;
    ListMachines *newList = NULL;

    if (listHead != NULL) {

        while (listHead != NULL) {

            if (listHead->proximo != NULL && listHead->nOperation == listHead->proximo->nOperation) {
                if (aux->vTime >= listHead->proximo->vTime) {
                    aux = listHead->proximo;
                }

            } else {
                //Guardar na lista o aux
                newList = insertAtBegin(aux->nOperation, aux->nMachine, aux->vTime, newList);
                aux = listHead->proximo;
            }

            listHead = listHead->proximo;
        }
    }

    if (newList != NULL) {
        printf("> Quantidade minima: %d\n", sumMachineTime(newList));
        printf("\n"); 
    }

    printListMachines(newList); 
    freeList(newList);
}

/**
 * @brief Percorre a lista principal e cria uma nova somente com as maquinas de maior tempo e apresenta o resultado;
 * 
 */
void maximumAmountOfTime(ListMachines *listMachines) {
    ListMachines *listHead = listMachines;
    ListMachines *aux = listMachines;
    ListMachines *newList = NULL;

    if (listHead != NULL) {

        while (listHead != NULL) {

            if (listHead->proximo != NULL && listHead->nOperation == listHead->proximo->nOperation) {
                if (aux->vTime <= listHead->proximo->vTime) {
                    aux = listHead->proximo;
                }

            } else {
                //Guardar na lista o aux
                newList = insertAtBegin(aux->nOperation, aux->nMachine, aux->vTime, newList);
                aux = listHead->proximo;
            }

            listHead = listHead->proximo; 
        }
    }

    if (newList != NULL) {
        printf("> Quantidade maxima: %d\n", sumMachineTime(newList));
        printf("\n"); 
    }

    printListMachines(newList);
    freeList(newList);
}

/**
 * @brief Percorre a lista principal e cria uma nova somente com as as medias das operações;
 * 
 */
void averageOperationTime(ListMachines *listMachines) {
    ListMachines *listHead = listMachines;
    ListAverageOp *newList = NULL;

    int count = 0;
    int sum = 0;
    float average = 0;
    char opcao;

    if (listHead != NULL) {

        while (listHead != NULL) {

            sum += listHead->vTime;

            if (listHead->proximo != NULL && listHead->nOperation == listHead->proximo->nOperation) {
                count++;             
            } else {
                count++;
                average = (float)sum / count;
                newList = insertAtBeginOp(listHead->nOperation, average, newList);
                average = 0;
                sum = 0;
                count = 0;
            }
            listHead = listHead->proximo;
        }

    } else {
        printf("Nao existem operacoes!\n");
    }

    while(newList != NULL) {

        printf("> Operacao: %d\n", newList->nOperation);
        printf("    > tempo medio: %.2f\n", newList->vTime);

        newList = newList->proximo;
    }

    freeListAv(newList);

    do {
        printf("Pressione 'v' para voltar:");
        scanf(" %c", &opcao);

    } while (opcao != 'v' && opcao != 'V');
}

/*-----  Manipulação de ficheiros  ------------------------------------------------------------------------------------------------
| saveJob | -> Salva as operacoes de um job no ficheiro txt
| saveJobFromList | -> Salva no ficheiro todas as operações do job que estão na memória
| readJob | -> Lê de um ficheiro txt com as operações de um job e salva na memória
*/

/**
 * @brief Salva as operacoes de um job no ficheiro txt
 * 
 * @param nOperation 
 * @param nMachine 
 * @param vTime 
 */
void saveJob(int nOperation, int nMachine, int vTime) {

    if (verifyIfFileExist("job.txt") == FALSE) {

        FILE *f = fopen("job.txt", "a");

        fclose(f);
        
    }

    if (verifyIfFileExist("job.txt")) {

        FILE *f = fopen("job.txt", "a");

        fprintf(f, "(%d,%d,%d)\n", nOperation, nMachine, vTime);

        fclose(f);
    }
}

/**
 * @brief Salva no ficheiro todas as operações do job que estão na memória
 * 
 * @param list 
 */
void saveJobFromList(ListMachines *list) {

    ListMachines *listHead = list;

    if (listMachines != NULL) {

        FILE *f = fopen("job.txt", "a");

        while (listHead != NULL) {

            fprintf(f, "(%d,%d,%d)\n", listHead->nOperation, listHead->nMachine, listHead->vTime);

            listHead = listHead->proximo;
        }
        fclose(f);
    }
}

/**
 * @brief Lê de um ficheiro txt com as operações de um job e salva na memória
 * 
 */
void readJob() {

    FILE *f = fopen("job.txt", "r");
    int nMachine;
    int vTime;
    int nOperation;

    if (f == NULL) {
        printf("Nao existe job!\n");
    } else {
        while(!feof(f)) {
            fscanf(f, "(%d,%d,%d)\n", &nOperation, &nMachine, &vTime);
            listMachines = insertAtBegin(nOperation, nMachine, vTime, listMachines);
        }
        fclose(f);
    }
}

//Adicionar maquina
void newMachineInputs2(int nOperation, ListJobs *job) {

    char opcao;

    system("clear");

    do
    {
        printf("Numero operacao(> 0): ");
        scanf("%d", &nOperationInput);

        if (verifyInputValues(nOperationInput) == FALSE)
        {
            printf("Valor invalido!\n");
        }
            
        if (verifyIfOperationExist(nOperationInput, job->machineHead) == TRUE) {
            
            printListMachines4(nOperation, job->machineHead);

        }
                
    } while ((verifyInputValues(nOperationInput) == FALSE));

    do {
        system("clear");

        do {
            printf("Numero Maquina: ");
            scanf("%d", &nMachineInput);

            if (verifyInputValues(nMachineInput) == FALSE) {
                printf("Valor invalido, insira um valor maior que 0\n");
            } else if(verifyIfMachineExistInOperation(nOperationInput, nMachineInput, job->machineHead) == TRUE) {
                printf("Maquina ja existe!\n");
            }
        } while ((verifyInputValues(nMachineInput) == FALSE) || (verifyIfMachineExistInOperation(nOperationInput, nMachineInput, job->machineHead) == TRUE));

        do {
            printf("Tempo: ");
            scanf("%d", &vTimeInput);

            if (verifyInputValues(vTimeInput) == FALSE)
                printf("Valor invalido, insira um valor maior que 0\n ");

        } while (verifyInputValues(vTimeInput) == FALSE);

        job->machineHead = insertAtBegin2(nOperationInput, nMachineInput, vTimeInput, job->machineHead);

        if (job->machineHead != NULL) {
            printf("Nova maquina inserida com sucesso!\n");
        } else {
            printf("Erro ao inserir maquina!!");
        }

        do {
            printf("Deseja inserir (s/n): ");
            scanf(" %c", &opcao);
        } while (opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N');

    } while(opcao == 's' || opcao == 'S');
}