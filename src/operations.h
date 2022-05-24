#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef enum { FALSE, TRUE } bool;

// Struct e Variaveis globais
typedef struct machine { 
    int nMachine;
    int nOperation;
    bool inUse;
    int vTime;
    struct machine *proximo;
} ListMachines;

typedef struct averageOp {
    int nOperation;
    float vTime;
    struct averageOp *proximo;
} ListAverageOp;

extern ListMachines *listMachines;
extern int nOperationInput;
extern int nMachineInput;
extern int vTimeInput;

//Functions Prototypes
ListMachines *insertAtBeginAndFile(int nOperation, int nMachine, int vTime, ListMachines *list);
ListMachines *insertAtBegin(int nOperation, int nMachine, int vTime, ListMachines *list);
void printListMachines(ListMachines *list);
bool verifyInputValues(int input);
//void newMachineInputs(ListMachines *listMachinesHead);
bool verifyIfOperationExist(int operationNumber, ListMachines *listMachineHead);
bool verifyIfMachineExistInOperation(int operationNumber, int machineNumber, ListMachines *listMachinesHead);
void removeOperation(int nOperation);
void editOperation(int nOperation);
void printOperationMachines(ListMachines *list, int nOperation);
void minimumAmountOfTime();
void insertAtEnd(int nOperation, int nMachine, int vTime, ListMachines *newList);
int sumMachineTime(ListMachines *list);
void freeList(ListMachines *list);
void freeListAv(ListAverageOp *list);
void maximumAmountOfTime();
void averageOperationTime();
ListAverageOp *insertAtBeginOp(int nOperation, float vTime, ListAverageOp *list);
void saveJob(int nOperation, int nMachine, int vTime);
bool verifyIfFileExist(char *fileName);
void readJob();
void saveJobFromList(ListMachines *list);
//-------------------------------------------------------------------------------PARTE 2




#endif