#pragma once // Aparentemente é boa prática, ele não deixa criar mais de 1 include do mesmo tipo
#include <cstdint>

#include "Memory.h"

class godmode {
private:

    Memory& mem; // Aqui é pra guardar uma referência ao objeto Memory original, é a própria injeção de dependência
    uintptr_t hpOffset = 0xEC;
    uintptr_t armorOffset = 0xF0;
    uintptr_t pAmmoOffset = 0x12C;
    uintptr_t pMagOffset = 0x108;
    uintptr_t granadeOffset = 0x144;
    uintptr_t dpAmmoOffset = 0x148;
    uintptr_t cAmmoOffset = 0x140;
    uintptr_t dpMagOffset = 0x124;
    uintptr_t cMagOffset = 0x11C;
    uintptr_t ttrCOffset = 0x164;
    uintptr_t ttrPOffset = 0x150;

    int dpMagChange = 1337;
    int pAmmoChange = 1337;
    int pMagChange = 1337;
    int granadeChange = 1337;
    int dpAmmoChange = 1337;
    int hpChange = 1337;
    int armorChange = 1337;
    int cAmmoChange = 1337;
    int cMagChange = 1337;
    int ttrCChange = 1;
    int ttrPChange = 1;
public:
    // Depois de guardar a referência, o construtor vai EXIGIR um objeto Memory
    godmode(Memory& memoryTool) : mem(memoryTool) {
        //Depois de tentar fazer funcionar, descobri que para poder ativar um godmode, precisamos ler sempre a memoria
        // Por mesmo que mude o valor, ele sempre precisa ficar ali lendo e reescrevendo o HP pro desejado
        // Então esse construtor só serve pra pegarmos a referência e usar as coisas de memory
        //------------------------------------------------------------------------------------
    }


    void ativar() {
        //Lógica de inicialização:
        //Pegamos o endereço base (baseAddr) que vem da classe Memory
        //Ou seja, pra pegar coisas de Memory, usamos mem.att;

        uintptr_t staticPtr = mem.baseAddr;

        //Ou seja, depois de pegar o base adress, precisamos refazer aquela lógica de:
        //Ler o que tem dentro do endereço, guardar ele e depois somar com o offSet
        //Dessa forma pegamos então o endereço final para fazer a mudança de Vida.

        // Descobri que como o assault cube é 32 bits, precisamos ler em 32 bits
        // o uintptr_t lê em 64 bits, ou seja, 8 bytes. ai os 4 bytes que sobra, ele joga no lixo
        // e ai o calculo do baseAdress ou calculos de Offsets, vão dar errado, por que ele ta calculando
        // tudo em 64 bits. Por isso a mudança de uintptr_t pra uint32_t. Poderia ser DWORD também.

        uintptr_t addrLido = mem.Read<uint32_t>(staticPtr);
        //Ou seja, aqui estamos fazendo a leitura de staticPtr usando a função read dentro de Memory
        //E guardando o endereço lido dentro de "addrLido"

        // Agora sim a gente pode gerar o endereço final que vai bater lá pra alterar o HP realmente
        // Por questões de segurança, só tentamos escrever se o "Player" existir
        // Evita crashar o jogo

        if (addrLido == 0) {
            return;
        }

        if (addrLido != 0) {
            // Calculando o endereço da vida atual, que é basicamente o addrbase + offset
            // guarda dentro do currentHpAddr e depois usa pra escrever
            uintptr_t currentHpAddr = addrLido + this->hpOffset;
            uintptr_t currentArmorAddr = addrLido + this->armorOffset;
            uintptr_t currentPAmmoAddr = addrLido + this->pAmmoOffset;
            uintptr_t currentPMagAddr = addrLido + this->pMagOffset;
            uintptr_t currentGranadeAddr = addrLido + this->granadeOffset;
            uintptr_t currentpDpAmmoAddr = addrLido + this->dpAmmoOffset;
            uintptr_t currentCAmmoAddr = addrLido + this->cAmmoOffset;
            uintptr_t currentdpMagAddr = addrLido + this->dpMagOffset;
            uintptr_t currentcMagAddr = addrLido + this->cMagOffset;
            uintptr_t currentttrCAddr = addrLido + this->ttrCOffset;
            uintptr_t currentttrPAddr = addrLido + this->ttrPOffset;


            // E como já guardamos a referência de Memory lá no private, é só usar ela:
            mem.Write<int>(currentHpAddr, this->hpChange);
            mem.Write<int>(currentArmorAddr, this->armorChange);
            mem.Write<int>(currentPAmmoAddr, this->pAmmoChange);
            mem.Write<int>(currentPMagAddr, this->pMagChange);
            mem.Write<int>(currentGranadeAddr, this->granadeChange);
            mem.Write<int>(currentpDpAmmoAddr, this->dpAmmoChange);
            mem.Write<int>(currentCAmmoAddr, this->cAmmoChange);
            mem.Write<int>(currentdpMagAddr, this->dpMagChange);
            mem.Write<int>(currentcMagAddr, this->cMagChange);
            mem.Write<int>(currentttrCAddr, this->ttrCChange);
            mem.Write<int>(currentttrPAddr, this->ttrPChange);

        }
    }

};
