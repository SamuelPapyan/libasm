section .text
    global  _ft_list_sort
; void	ft_list_sort(t_list **begin_list, int (*cmp)());
; begin_list == rdi, cmp == rsi

_ft_list_sort:
init:
    push    rbx
    mov     rbx, rsi
    push    r8
    mov r8, [rdi]
    push    r9

loop_i:
    mov     r9, [r8+8]
    cmp     r9, 0
    je      end

loop_j:
    cmp     r9, 0
    je      loop_i_end
    push    rdi
    mov     rdi, [r8]
    push    rsi
    mov     rsi, [r9]
    push    r8
    push    r9
    call    rbx
    cmp     rax, 0
    pop     r9
    pop     r8
    jle     else

swap:
    mov     rsi, [r8]
    mov     rdi, [r9]
    mov     [r8], rdi
    mov     [r9], rsi

else:
    pop     rsi
    pop     rdi
    mov     r9, [r9+8]
    jmp     loop_j

loop_i_end:
    mov     r8, [r8+8]
    cmp     r8, 0
    je      end
    jmp     loop_i

end:
    pop     r9
    pop     r8
    pop     rbx
    xor     rax, rax
    ret