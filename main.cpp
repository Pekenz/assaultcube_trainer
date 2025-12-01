#include <iostream>
#include "godmode.h"
#include "Memory.h"
#include "killall.h"

using namespace std;


int main() {

    // isso aqui já tinha sido feito, tava correto, só mudei pra "mem" pra testar
    // O erro que tava dando, era por que chamando Memory a gente tava reescrevendo ele no main
    // Colocando #pragma once nos outros arquivos, o erro desapareceu
    Memory mem(L"ac_client.exe");

    // Ai aqui criamos o GodMode e passamos o objeto de Memory dentro dele
    godmode vidaInfinita(mem);

    killall matarTodos(mem);
    // E depois é só chamar a "ativar" que criamos dentro d godmode.h
    //vidaInfinita.ativar();

    // NUMPAD 1 ativa, NUMPAD2 desativa (quebra o loop)

    cout << "Trainer Iniciado." << endl;
    cout << "[NUMPAD 1] - Ativar GODMODE (NUMPAD2 para parar)" << endl;
    cout << "[NUMPAD 8] - Matar GERAL" << endl;
    cout << "[NUMPAD 9] - Sair fora" << endl;
    while (true) {
        if (GetAsyncKeyState(VK_NUMPAD1)) {
            while (true) {
                vidaInfinita.ativar();
                Sleep(10);
                if (GetAsyncKeyState(VK_NUMPAD2)) {
                    break;
                }
            }
        }

        if (GetAsyncKeyState(VK_NUMPAD8)) {
            matarTodos.ativar();
            Sleep(1000);
        }

        if (GetAsyncKeyState(VK_NUMPAD9)) {
            return 0;
        }


    }

}