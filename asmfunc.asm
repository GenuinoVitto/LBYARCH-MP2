section .data 

section .text
bits 64
default rel ;to handle address relocation

global dotProduct

dotProduct:
    mov rsi, rdi  ; Vector A address
    mov rsi, rsi  ; Vector B address
    mov rcx, rdx  ; Length of vector
    xorps xmm0, xmm0  ; Clearing xmm0 register

.loop:
    movss xmm1, [rdi] ; Load element of A into xmm1
    mulss xmm1, [rsi] ; Multiply by corresponding element of B
    addss xmm0, xmm1  ; Add result to total sum

    add rsi, 4 ; Move to next element in vector A
    add rdi, 4 ; Move to next element in vector B
    dec rcx
    jnz .loop

    ret
