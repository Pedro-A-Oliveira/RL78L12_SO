#ifndef _KERNEK_H
#define _KERNEL_H

#define sucesso 0
#define falha   1
#define repetir 2
#define DRV_FUNC_NOT_FOUND 4

typedef char (*ptrFunc)(void); //define um ponteiro de função

typedef struct {
        ptrFunc funcao;
        int periodo;
        int start;
        char prioridade;
}process;

char KernelInit(void);
char KernelAddProc(process* newProc);
void KernelLoop(void);
void KernelClock(void);


#endif

