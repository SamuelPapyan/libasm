section .text
    global  _ft_list_remove_if
    extern _ft_list_remove_if


_ft_list_remove_if:
    push    r8
    mov     r8, [rdi]
    jmp loop

set_begin_list:
    push    rdi
    push    r8
    mov     rdi, [r8]
    call    rcx
    pop     r8
    pop     rdi
    mov     rax, [r8+8]
    mov     [rdi], rax
    push    rdi
    push    r8
    mov     rdi, r8
    call    _free
    pop     r8
    pop     rdi
    mov     r8, [rdi]

loop:
    cmp     r8, 0
    je      end
    push    rdi
    mov     rdi, [r8]
    push    r8
    push    rcx
    push    rsi
    call    rdx
    pop     rsi
    pop     rcx
    pop     r8
    pop     rdi
    cmp     rax, 0
    je      set_begin_list
    mov     rdi, r8
    jmp     curr_loop

set_curr:
    mov     rax, [r8+8]
    mov     [rdi+8], rax
    push    rdi
    push    rdx
    push    r8
    mov     rdi, [r8]
    call    rcx
    pop     r8
    mov     rdi, r8
    call    _free
    pop     rdx
    pop     rdi
    mov     r8, [rdi+8]

curr_loop:
    cmp     r8, 0
    je      end
    push    rdi
    mov     rdi, [r8]
    push    rsi
    push    r8
    push    rcx
    call    rdx
    pop     rcx
    pop     r8
    pop     rsi
    pop     rdi
    pop     rax, 0
    je      set_curr
    mov     rdi, r8
    mov     rax, [r8+8]
    mov     r8, rax
    jmp     curr_loop

end:
    pop     r8
    xor     rax, rax
    ret