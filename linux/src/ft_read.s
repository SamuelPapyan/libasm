section .text
global	ft_read
extern	__errno_location
; size_t   read(int fd, const void *buf, size_t nbyte);
; fd == rdi, buf == rsi, nbyte == rdx


ft_read:
	mov	rax, 0
	syscall
	jc err_read
	ret

err_read:
	push	rax
	call	__errno_location
	pop		rdx
	mov		[rax], rdx
	mov		rax, -1
	ret
