#pragma once // Aparentemente é boa prática, ele não deixa criar mais de 1 include do mesmo tipo
#include "Memory.h"

class godmode {
private:

    Memory& mem; // Aqui é pra guardar uma referência ao objeto Memory original, é a própria injeção de dependência
    uintptr_t hpOffset = 0xEC;
    uintptr_t finalHpAddr = 0;
     int hpChange = 1337;

public:
    // Depois de guardar a referência, o construtor vai EXIGIR um objeto Memory
    godmode(Memory& memoryTool) : mem(memoryTool) {
        //Lógica de inicialização:
        //Pegamos o endereço base (baseAddr) que vem da classe Memory
        //Ou seja, pra pegar coisas de Memory, usamos mem.att;

        uintptr_t staticPtr = mem.baseAddr;

        //Ou seja, depois de pegar o base adress, precisamos refazer aquela lógica de:
        //Ler o que tem dentro do endereço, guardar ele e depois somar com o offSet
        //Dessa forma pegamos então o endereço final para fazer a mudança de Vida.

        uintptr_t addrLido = mem.Read<uintptr_t>(staticPtr);
        //Ou seja, aqui estamos fazendo a leitura de staticPtr usando a função read dentro de Memory
        //E guardando o endereço lido dentro de "addrLido"

        //Agora sim a gente pode gerar o endereço final que vai bater lá pra alterar o HP realmente
        this->finalHpAddr = addrLido + this->hpOffset;

    }

    void ativar() {
        // E como já guardamos a referência de Memory lá no private, é só usar ela:
        mem.Write<int>(this->finalHpAddr, this->hpChange);
    }

};
