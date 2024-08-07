section .text
global	ft_write
extern	__errno_location
; size_t   write(int fd, const void *buf, size_t count);
; fd == rdi, buf == rsi, count == rdx

ft_write:
	mov	rax, 1
	syscall
	jc	err

err:
	push	rax
	call	__errno_location
	pop		rdx
	mov		[rax], rdx
	mov		rax, -1
	ret
