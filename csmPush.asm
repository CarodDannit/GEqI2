section .text
    global _start       ; Declare the entry point for the linker

_start:
    ; --- The Calculation ---
    mov eax, 1          ; Move 1 into the EAX register
    add eax, 1          ; Add 1 to EAX. EAX is now 2.

    ; --- The Exit (Linux System Call) ---
    ; To verify the result in Linux, we can use the result as the exit status.
    ; ebx holds the exit code in a Linux sys_exit call.
    
    mov ebx, eax        ; Move the result (2) from EAX to EBX
    mov eax, 1          ; System call number for sys_exit is 1
    int 0x80            ; Interrupt to wake up the kernel and run the command
