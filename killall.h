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

    void ativar();
};