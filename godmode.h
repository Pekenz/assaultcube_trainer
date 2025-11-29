#include "Memory.h"

class godmode {
private:
    uintptr_t hpOffset = 0xEC;
    uintptr_t hpAddr;
    const int hpChange = 1337;
public:
    godmode(uintptr_t baseAddr) {
        this->hpOffset = hpOffset;
        this->hpAddr = baseAddr + hpOffset;
    }
asdasfasfa
    void* setVida(uintptr_t hpAddr, int hpChange) {
        WriteProcessMemory(this->hProcess, (LPVOID)hpAddr, hpChange, sizeof(int), NULL);
    }

};
