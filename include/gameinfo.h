#ifndef GAMEINFO_H
#define GAMEINFO_H

#include "module2.h"

void findGameId();

int readGameIdFromDisc();

// Patch Game ID Getter
void patchGameInfoGetter(SceModule * mod);

// Fixed Game Info Getter Function
void * SysMemForKernel_EF29061C_Fixed(void);

#endif