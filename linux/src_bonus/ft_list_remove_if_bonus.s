global ft_list_remove_if
extern free

; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
; rdi = **begin_list, rsi = *data_ref, rdx = (*cmp) 

section .text

ft_list_remove_if:
    cmp rdi, 0
    je exit
    cmp rsi, 0
    je exit
    jmp start
    
start:
    mov r10, [rdi]
    cmp r10, 0
    je stop
    push rdi
    push rsi
    push rdx
    mov rdi, [r10]
    call rdx
    pop rdx
    pop rsi
    pop rdi
    cmp rax, 0
    jne stop
    mov r10, [rdi]
    mov r11, [r10 + 8]
    mov [rdi], r11
    push rdi
    push rsi
    push rdx
    push r10
    push r11
    mov rdi, r10
    call free
    pop r11
    pop r10
    pop rdx
    pop rsi
    pop rdi
    jmp start

stop:
	mov r10, [rdi]
  jmp loop

loop:
    mov r11, [r10 + 8]
    cmp r10, 0
    je exit
    cmp r11, 0
    je exit
    push rdi
    push rsi
    push rdx
    push r10
    push r11
    mov rdi, [r11]
    call rdx
    pop r11
    pop r10
    pop rdx
    pop rsi
    pop rdi
    cmp rax, 0
    jne skip
    push rdi
    push rsi
    push rdx
    push r10
    push r11
    mov rdi, r11
    mov r11, [r11 + 8]
    mov [r10 + 8], r11
    call free
    pop r11
    pop r10
    pop rdx
    pop rsi
    pop rdi
    jmp loop

skip:
    mov r10, r11
    jmp loop

exit:
    ret