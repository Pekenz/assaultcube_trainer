//
// Created by Pekenz on 30/11/2025.
//

#include "killall.h"

void killall::ativar() {
    uintptr_t staticPtr = mem.entityListOffset;

    uintptr_t addrBotList = mem.Read<uint32_t>(staticPtr);

    if (addrBotList == 0) {
        return;
    }

    uintptr_t myPlayerAddr = mem.Read<uint32_t>(mem.baseAddr);

    for (int i = 0; i < maxPlayersLoop; i++) {
        uintptr_t currentBotPtrAddr = addrBotList + (i * 0x04);
        uintptr_t botAddr = mem.Read<uint32_t>(currentBotPtrAddr);

        if (botAddr == 0) continue;

        if (botAddr == myPlayerAddr) continue;

        uintptr_t botHealthAddr = botAddr + botHealthOffset;

        mem.Write<int>(botHealthAddr, this->botHpChange);
    }
}