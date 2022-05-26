#ifndef JOBS_H
#define JOBS_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

typedef struct job { //Lista de jobs
    int nJob;
    struct machine *machineHead;
    struct job *proximo;
} ListJobs;

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

#endif