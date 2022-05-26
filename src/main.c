#include <stdio.h>
#include <stdlib.h>
#include "operations.h"
#include "jobs.h"

int main() {

    ListJobs *job = NULL;

    int opcao;
    int jobToEdit, jobToRemove;
    char c;

    //readJob();

    do {   
        jobMenu();
        
        scanf("%d", &opcao);
                    
        switch (opcao) {

            case 1: 
            system("clear");
            listJobs = insertJobsAtBegin(newJobInputs(), NULL, listJobs);
            menuOperations(listJobs);
            break; 
            case 2:
            system("clear");    
            printListJobs2(listJobs);
            
            if (listJobs == 0) {
                printf("Nao existem jobs!\n");
            } else {
                do {
                    printf("Insira o numero do job:");
                    scanf("%d", &jobToRemove);

                    if (verifyInputValues(jobToRemove) == FALSE) {
                        printf("O numero tem de ser maior que 0\n");
                    }

                } while(jobToRemove == FALSE);
            }
            removeJob(jobToRemove, listJobs);
            system("clear");
            break;

            case 3:
            system("clear");
            printListJobs2(listJobs);
            if (listJobs == NULL) {
                printf("Nao existem jobs!\n");
            } else {
                do {
                    printf("Insira o numero do Job:");
                    scanf("%d", &jobToEdit);

                    if (verifyInputValues(jobToEdit) == FALSE) {
                        printf("O numero tem de ser maior que 0\n");
                    }
                } while (jobToEdit == FALSE);
            }

                if (alterarJob(jobToEdit) == NULL) {
                    printf("Nao existem jobs com o numero %d\n", jobToEdit);

                    do {

                        printf("Pression 'v' para voltar:");
                        scanf(" %c", &c);

                    } while (c != 'v' && c != 'V');

                    system("clear");

                } else {
                    system("clear");
                    menuOperations(alterarJob(jobToEdit));
                }
            
            break;
            case 4:
            system("clear");
            printListJobs(listJobs);
            system("clear");
            break;
            case 5:
            //TODO: ESCALONAMENTO
            break;
            case 6:
            saveJobOnTxt(listJobs);
            break;
            case 8: 
            addTableJobs(); //ADD DATA COM JOBS DA TABELA
            system("clear");
            break;
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

    int operationToRemove, machineToRemove;
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

                //Listar operações do job
                printListMachines2(job->machineHead);

                if (job->machineHead == 0) {
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

                removeOperation(operationToRemove, job);
                system("clear");
                break;
            case 3:

                system("clear");

                printListMachines3(job->machineHead);

                if (job->machineHead == NULL) {
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

                system("clear");

                editOperation(operationToEdit, job->machineHead);
                system("clear");
                
                break;
            case 4:
                system("clear");
                minimumAmountOfTime(job->machineHead);
                system("clear");
                break;
            case 5:
                system("clear");
                maximumAmountOfTime(job->machineHead);
                system("clear");
                break;
            case 6:
                system("clear");
                averageOperationTime(job->machineHead);
                system("clear");
                break;
            case 7:
                system("clear");
                printListMachines(job->machineHead);
                system("clear");
                break;
            case 8:
                //TODO: Adicionar maquina
                system("clear");

                newMachineInputs2(nOperationInput, job);



                break;
            case 9:
                //Listar operações do job
                system("clear");
                printListMachines2(job->machineHead);

                //Escolher Operacao
                if (job->machineHead == 0) {
                    printf("Nao existem operacoes!\n");
                } else {

                    do {

                        printf("Insira o numero da operacao:");
                        scanf("%d", &nOperationInput);

                        if (verifyInputValues(nOperationInput) == FALSE) {
                            printf("O numero tem de ser maior que 0\n");
                        }

                    } while (nOperationInput == FALSE);

                    
                    system("clear");

                    if (printListMachines4(nOperationInput, job->machineHead) == TRUE) {
                        do {
                            printf("Insira o numero da Maquina:");
                            scanf("%d", &machineToRemove);

                            if (verifyInputValues(machineToRemove) == FALSE) {
                                printf("O numero tem de ser maior que 0\n");
                            }

                        } while(machineToRemove == FALSE);

                    } else {
                        printf("Nao existem operacoes com o n %d\n", nOperationInput);
                    }
                }

                removeMachine(machineToRemove, nOperationInput, job);
                system("clear");
                break;
            default:
                break;
        }
    } while (opcao != 0);

    system("clear");

}