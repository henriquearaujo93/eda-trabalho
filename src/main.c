#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
#include "jobs.h"

int main() {

    ListJobs *job = NULL;

    int opcao;

    readJob();

    do {   
        jobMenu();
        
        scanf("%d", &opcao);
                    
        switch (opcao) {

            case 1: 
            //TODO:
            system("clear");
            listJobs = insertJobsAtBegin(newJobInputs(), NULL, listJobs);
            menuOperations(listJobs);
            break; 
            case 2:
            //TODO:
            break;
            case 3:
            //TODO:
            break;
            case 4:
            system("clear");
            printListJobs(listJobs);
            system("clear");
            break;
            case 5:
            //TODO:
            break;
            case 6:
            //TODO:
            break;
            case 7:
            //TODO:
             default:
             break;
        }

        if (opcao == 0) {
            system("clear");
        }
                
    } while (opcao != 0);
    
    freeList(listMachines);

    return(0);
}

void menuOperations(ListJobs *job) {

    int operationToRemove;
    int operationToEdit;

    int opcao;
    
    do
    {
        printMenu(job);

        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                newMachineInputs(job);
                system("clear");
                break;
            case 2:
                system("clear");

                if (listMachines == 0) {
                    printf("Nao existem operacoes!\n");
                } else {

                    do {
                        printf("Insira o numero da operacao:");
                        scanf("%d", &operationToRemove);

                        if (verifyInputValues(operationToRemove) == FALSE) {
                            printf("O numero tem de ser maior que 0\n");
                        }

                    } while(operationToRemove == FALSE);
                }

                removeOperation(operationToRemove);
                system("clear");
                break;
            case 3:

                system("clear");

                if (listMachines == NULL) {
                    printf("Nao existem operacoes!\n");
                } else {
                    do {
                        printf("Insira o numero da operacao:");
                        scanf("%d", &operationToEdit);

                        if (verifyInputValues(operationToEdit) == FALSE) {
                            printf("O numero tem de ser maior que 0\n");
                        }
                    } while (operationToEdit == FALSE);
                }

                editOperation(operationToEdit);
                system("clear");
                
                break;
            case 4:
                system("clear");
                minimumAmountOfTime();
                system("clear");
                break;
            case 5:
                system("clear");
                maximumAmountOfTime();
                system("clear");
                break;
            case 6:
                system("clear");
                averageOperationTime();
                system("clear");
                break;
            case 7:
                system("clear");
                printListMachines(listMachines);
                system("clear");
                break;
            case 8:
                /*
                listMachines = insertAtBegin(1, 1, 4, listMachines);
                listMachines = insertAtBegin(1, 3, 5, listMachines);
                listMachines = insertAtBegin(2, 2, 4, listMachines);
                listMachines = insertAtBegin(2, 4, 5, listMachines);
                listMachines = insertAtBegin(3, 3, 5, listMachines);
                listMachines = insertAtBegin(3, 5, 6, listMachines);
                listMachines = insertAtBegin(4, 4, 5, listMachines);
                listMachines = insertAtBegin(4, 5, 5, listMachines);
                listMachines = insertAtBegin(4, 6, 4, listMachines);
                listMachines = insertAtBegin(4, 7, 5, listMachines);
                listMachines = insertAtBegin(4, 8, 9, listMachines);
                */
                //saveJobFromList(listMachines);
                system("clear");
            
                break;
            default:
                break;
        }
    } while (opcao != 0);

    system("clear");

}