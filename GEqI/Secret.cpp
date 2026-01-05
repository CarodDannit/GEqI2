#include <iostream>
#include <iomanip>
#include "Secret.h"

using namespace std;

void runAssemblySecret() {
    int secretCode = 0;
    int hackingStatus = 0;

    cout << "\033[31m[!] SYSTEM BREACH DETECTED [!]\033[0m\n";
    cout << "Injecting Assembly code from external file...\n";

    // --- ASSEMBLY BLOCK START ---
    // (Remember: Set Visual Studio to x86 or Win32 mode!)
    __asm {
        mov eax, 0xCAFE; // load CAFE hex into EAX
        mov ebx, 0xBABE; // load BABE hex into EBX
        add eax, ebx; // add (CAFEBABE is a famous magic number)
        mov secretCode, eax; // store result

        mov ecx, 1;
        mov hackingStatus, ecx;
    }
    // --- ASSEMBLY BLOCK END ---

    if (hackingStatus == 1) {
        cout << "\033[33m"; 
        cout << "CPU EAX REGISTER: 0x" << hex << secretCode << dec << "\n";
        cout << "STATUS: HANTU DETECTED\n";
        cout << "\n";
        cout << "      (  )   \n";
        cout << "     (    )  \n";
        cout << "    (      ) \n";
        cout << "    |      | \n";
        cout << "    |  RIP | \n";
        cout << "    |      | \n";
        cout << "   _|______|_ \n";
        cout << "\033[0m";
        cout << "\nPress any key to escape...\n";
        system("pause > nul");
    }
}