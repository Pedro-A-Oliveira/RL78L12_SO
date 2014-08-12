#include "kernel.h"


#define POOLSIZE 10
#define MIN_INT -30000

process* pool[POOLSIZE];
process* tempProc;
int ini, fim;

char KernelInit(void){
    ini = 0;
    fim = 0;
    return  sucesso;
}

char KernelAddProc(process* newProc){
    if (((fim+1)%POOLSIZE) != fim){
        pool[fim] = newProc;
        pool[fim]->start += newProc->periodo;
        fim = (fim+1)%(POOLSIZE);
        return sucesso;
    }
    return falha;
}

void KernelLoop(void){
    int j, next;  
    for(;;){
      if(ini != fim){
//Procurando processo com menor tempo
        j = (ini+1)%POOLSIZE;
        next = ini;
        while(j!=fim){
			if((pool[j]->prioridade < pool[next]->prioridade) && (pool[j]->start <= 0) ){
				next = j;
			}else if(pool[j]->start < pool[next]->start){
				next = j;
			}
          j = (j+1)%POOLSIZE;
        }
//Troca posições na Pool
        tempProc = pool[next];
        pool[next] = pool[ini];
        pool[ini] = tempProc;
        
        while(pool[ini]->start > 0){
        }
 
        if(pool[ini]->funcao() == repetir){
            KernelAddProc(pool[ini]);
        }
        ini = (ini+1)%POOLSIZE;
        }
     }
}

void KernelClock(void){
  unsigned char i;
  i = ini;
  while(i!=fim){
      if((pool[i]->start)>(MIN_INT)){
        pool[i]->start--;
      }
      i = (i+1)%POOLSIZE;
  }
}
