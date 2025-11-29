#include <iostream>
#include "godmode.h"
#include "Memory.h"

using namespace std;


int main() {

    // isso aqui já tinha sido feito, tava correto, só mudei pra "mem" pra testar
    // O erro que tava dando, era por que chamando Memory a gente tava reescrevendo ele no main
    // Colocando #pragma once nos outros arquivos, o erro desapareceu
    Memory mem(L"ac_client.exe");

    // Ai aqui criamos o GodMode e passamos o objeto de Memory dentro dele
    godmode vidaInfinita(mem);

    // E depois é só chamar a "ativar" que criamos dentro d godmode.h
    //vidaInfinita.ativar();

    // NUMPAD 1 ativa, NUMPAD2 desativa (quebra o loop)
    while (true) {
        if (GetAsyncKeyState(VK_NUMPAD1)) {
            while (true) {
                vidaInfinita.ativar();
                Sleep(10);
                if (GetAsyncKeyState(VK_NUMPAD2)) {
                    goto end_godmode;
                }
            }
        }
        Sleep(100);
    }
    end_godmode:
        return 0;
}