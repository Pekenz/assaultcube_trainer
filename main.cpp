#include <format>
#include "godmode.h"
#include "Memory.h"

using namespace std;


int main() {

    Memory processName(L"ac_client.exe");
    godmode infiniteLife(processName.baseAddr);


asdasdasdasdasd
    uintptr_t hpOffset = 0xEC;
    uintptr_t finalHpAdress = value + hpOffset;

    processName.Write<int>(finalHpAdress, hpChange);


    cout << "O HP sera mudado para: " << hpChange << endl;
}