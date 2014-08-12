/*
 * ctrdrv.c
 *
 *  Created on: May 18, 2014
 *      Author: Pedro
 */
#include "ctrdrv.h"
#include "kernel.h"

static driver* driversLoaded[QNTD_DRV];
static char qntDrvLoaded;

char initCtrDrv(void){
    qntDrvLoaded = 0;
    return sucesso;
}

char initDriver(char newDriver) {
    char resp = falha;
    if (qntDrvLoaded < QNTD_DRV) {
        driversLoaded[qntDrvLoaded] = drvGetFunc[newDriver]();
        resp = driversLoaded[qntDrvLoaded]->drv_init(&newDriver);
        driversLoaded[qntDrvLoaded]->drv_id = newDriver;  //Linha adicionada para adicionar id
        qntDrvLoaded++;
    }
    return resp;
}

char callDriver(char drv_id, char func_id, void *parameters) {
    char i;

    for (i = 0; i < qntDrvLoaded; i++) {
        if (drv_id == driversLoaded[i]->drv_id) {
             return driversLoaded[i]->drv_func[func_id](parameters);
        }
    }
    return DRV_FUNC_NOT_FOUND;
}
