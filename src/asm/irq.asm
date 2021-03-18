global irq0
global irq1
global irq2
global irq3
global irq4
global irq5
global irq6
global irq7
global irq8
global irq9
global irq10
global irq11
global irq12
global irq13
global irq14
global irq15

; IRQ0
irq0:
    cli
    push byte 0
    push byte 32            ; Not pushing error code on the stack, pushing dummy error codes
    jmp irq_common_stub

; IRQ1
irq1:
    cli
    push byte 0
    push byte 33
    jmp irq_common_stub

; IRQ2
irq2:
    cli
    push byte 0
    push byte 34
    jmp irq_common_stub

; IRQ3
irq3:
    cli
    push byte 0
    push byte 35
    jmp irq_common_stub

; IRQ4
irq4:
    cli
    push byte 0
    push byte 36
    jmp irq_common_stub

; IRQ5
irq5:
    cli
    push byte 0
    push byte 37
    jmp irq_common_stub

; IRQ6
irq6:
    cli
    push byte 0
    push byte 38
    jmp irq_common_stub

; IRQ7
irq7:
    cli
    push byte 0
    push byte 39
    jmp irq_common_stub

; IRQ8
irq8:
    cli
    push byte 0
    push byte 40
    jmp irq_common_stub

; IRQ9
irq9:
    cli
    push byte 0
    push byte 41
    jmp irq_common_stub

; IRQ10
irq10:
    cli
    push byte 0
    push byte 42
    jmp irq_common_stub

; IRQ11
irq11:
    cli
    push byte 0
    push byte 43
    jmp irq_common_stub

; IRQ12
irq12:
    cli
    push byte 0
    push byte 44
    jmp irq_common_stub

; IRQ13
irq13:
    cli
    push byte 0
    push byte 45
    jmp irq_common_stub

; IRQ14
irq14:
    cli
    push byte 0
    push byte 46
    jmp irq_common_stub

; IRQ15
irq15:
    cli
    push byte 0
    push byte 47
    jmp irq_common_stub

extern irq_handler

; A stub created for IRQ based ISRs. It calls irq_handler in the C code
; that is declared in irq.c
irq_common_stub:
    pusha
    push ds
    push es
    push fs
    push gs
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov eax, esp
    push eax
    mov eax, irq_handler
    call eax
    pop eax
    pop gs
    pop fs
    pop es
    pop ds
    popa
    add esp, 8
    iret
