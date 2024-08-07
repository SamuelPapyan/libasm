global  ft_strcpy
extern  ft_strlen
; char  *ft_strcpy(char *dest, const char *src);
; dest == rdi, src == rsi

section .text

ft_strcpy:
    push    rdi             ; rdi register save for using
    mov     rdi, rsi        ; set rdi for call ft_strlen(rdi)
    call    ft_strlen      ; call ft_strlen
    mov     rcx, rax        ; set rcx for movsb
    pop     rdi             ; pop rdi
    mov     rax, rdi        ; set return value
    cld                     ; clear DF
    rep     movsb           ; mov desc <- src (while rcx)
    mov     BYTE [rdi], 0   ; set null
    ret                     ; return rax
