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

    killall ativarKill(mem);
    // E depois é só chamar a "ativar" que criamos dentro d godmode.h
    //vidaInfinita.ativar();

    // NUMPAD 1 ativa, NUMPAD2 desativa (quebra o loop)


    bool gGodMode = false;
    bool killAll = false;

    cout << "Trainer Iniciado." << endl;
    cout << "[NUMPAD 1] - Ativar GODMODE (NUMPAD2 para parar)" << endl;
    cout << "[NUMPAD 8] - Matar GERAL" << endl;
    cout << "[NUMPAD 9] - Sair fora" << endl;

    while (true) {
        if (GetAsyncKeyState(VK_NUMPAD1) & 1) {
            gGodMode = !gGodMode;

            if (gGodMode) cout << "GodMode: [ON]" << endl;
            else cout << "GodMode: [OFF]" << endl;
        }

        if (GetAsyncKeyState(VK_NUMPAD8) & 1) {
            killAll = !killAll;

            if (killAll) cout << "KillAll: [ON]" << endl;
            else cout << "KillAll: [OFF]" << endl;
        }

        if (GetAsyncKeyState(VK_NUMPAD9) & 1) {
            return 0;
        }

        if (gGodMode) {
            vidaInfinita.ativar();
        }

        if (killAll) {
            ativarKill.ativar();
        }
        Sleep(5);
    }
    return 0;
}