#pragma once
#include <cstdint>
#include "Memory.h"

class killall {
private:

    Memory& mem;
    uintptr_t botHealthOffset = 0xEC;

    int maxPlayersLoop = 32;
    int botHpChange = -100;

public:
    killall(Memory& memoryTool) : mem(memoryTool) {
    }

    void ativar(){
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
};