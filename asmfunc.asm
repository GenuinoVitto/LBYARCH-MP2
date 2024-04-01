section .text
    global dotProduct

dotProduct:
    ; rdi - pointer to A
    ; rsi - pointer to B
    ; rdx - n
    ; rcx - pointer to sdot

    push rbp                        ; Preserve the base pointer
    mov rbp, rsp                    ; Set up a new base pointer

    xor rax, rax                    ; Clear rax for loop counter
    xorps xmm0, xmm0                ; Clear xmm0 for accumulating the sum

dotProduct_loop:
    cmp rax, rdx                    ; Compare loop counter with n
    je dotProduct_done             ; If loop counter equals n, jump to done

    movss xmm1, dword [rdi + 4 * rax]  ; Load A[i] into xmm1
    mulss xmm1, dword [rsi + 4 * rax]  ; Multiply A[i] with B[i]
    addss xmm0, xmm1                ; Add the result to the sum in xmm0

    inc rax                         ; Increment loop counter
    jmp dotProduct_loop            ; Jump back to loop

dotProduct_done:
    movss [rcx], xmm0               ; Store the final result in sdot

    pop rbp                         ; Restore the base pointer
    ret
