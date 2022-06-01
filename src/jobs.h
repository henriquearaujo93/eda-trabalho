#ifndef JOBS_H
#define JOBS_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operations.h"

typedef struct job { //Lista de jobs
    int nJob;
    struct machine *machineHead;
    struct job *proximo;
} ListJobs;

//Operacoes para cada maquina do escalonamento
typedef struct escOperation {
    int nOperation;
    int nJob;
    int time;
    int begin;
    int end;
    struct escOperation *proximo;
}ListescOperation;

//Lista de maquinas para escalonamento
typedef struct escMachine {
    int nMachine;
    struct escOperation *escOperationHead;
    struct escMachine *proximo;
} ListescMachines;

extern ListJobs *listJobs;

//Assinaturas
void jobMenu();
void printMenu(ListJobs *job);
void menuOperations(ListJobs *job);
ListJobs *insertJobsAtBegin(int nJob, ListMachines *listmachines, ListJobs *list);
bool verifyIfJobExist(int jobNumber);
int newJobInputs();
void printListJobs(ListJobs *list);
void newMachineInputs(ListJobs *job);
void addTableJobs();
ListJobs *alterarJob(int nJob);
void printListJobs2(ListJobs *list);
void removeJob(int nJob, ListJobs *jobsHead);
void newMachineInputs2(int nOperation, ListJobs *job);
void removeOperation(int nOperation, ListJobs *job);
void removeMachine(int nMachine, int nOperationInput, ListJobs *job);
void saveJobOnTxt(ListJobs *list);
void loadJobsFromFile();
void freeListJobs(ListJobs *list);
ListescMachines *criarListaMaquinas();
bool verifyIfMachineEscExist(int nMachine, ListescMachines *list);
ListescMachines *insertMachineEscAtBegin(int nMachine, ListescMachines *list);
void escalonamento();
void removeOperation2(int nOperation, ListJobs *job);

#endif