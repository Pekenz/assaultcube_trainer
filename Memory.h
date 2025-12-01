#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

using namespace std;

class Memory {
private:
    DWORD pid;
    HANDLE hProcess;

public:

    uintptr_t gameBaseAddr = 0x400000;
    uintptr_t entityListOffset = 0x591FCC;
    uintptr_t baseAddr = 0x57E0A8;

    Memory(const wchar_t* processName) {

        this->pid = GetProcId(processName);

        if (this-> pid != 0) {
            this->hProcess = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, this->pid);
            if (this->hProcess) {
                cout << "PID: " << this->pid << endl;
            } else {
                cout << "erro ao abrir o pid" << endl;
            }
        } else {
            cout << "Processo nao encontrado" << endl;
        }
    }

    ~Memory() {
        if (this->hProcess) {
            CloseHandle(this->hProcess);
        }
    }
    template <typename T>
    T Read(uintptr_t adress) {
        T value ={};
        ReadProcessMemory(this->hProcess, (LPVOID) adress, &value, sizeof(T), NULL);
        return value;
    }

    template <typename T>
    void Write(uintptr_t adress, T value) {
        WriteProcessMemory(this->hProcess, (LPVOID) adress, &value, sizeof(T), NULL);
    }

private:
    // Função auxiliar escondida (aquela sua GetProcId antiga)
    DWORD GetProcId(const wchar_t* procName) {
        DWORD procId = 0;
        HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
        if (hSnap != INVALID_HANDLE_VALUE) {
            PROCESSENTRY32W procEntry;
            procEntry.dwSize = sizeof(procEntry);
            if (Process32FirstW(hSnap, &procEntry)) {
                do {
                    if (!_wcsicmp(procEntry.szExeFile, procName)) {
                        procId = procEntry.th32ProcessID;
                        break;
                    }
                } while (Process32NextW(hSnap, &procEntry));
            }
        }
        CloseHandle(hSnap);
        return procId;
    }
};


