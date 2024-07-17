section .text
	global	_ft_atoi_base
	extern	_ft_strlen

_ft_atoi_base:

check_base_len:
	push rdi
	mov rdi, rsi
	call	_ft_strlen
	cmp		rax, 2
	pop		rdi
	jb		error

check_base_dup:
	push	rcx
	xor		rcx, rcx

check_base_dup_loop_i:
	cmp	BYTE[rsi+rcx], 0
	je	check_base_dup_loop_i_end
	mov	rax, rcx
	inc	rax

check_white_space:
	cmp		BYTE[rsi+rcx], 9
	je		skip_str_white_space_inc
	cmp		BYTE[rsi+rcx], 10
	je		skip_str_white_space_inc
	cmp		BYTE[rsi+rcx], 11
	je		skip_str_white_space_inc
	cmp		BYTE[rsi+rcx], 12
	je		skip_str_white_space_inc
	cmp		BYTE[rsi+rcx], 13
	je		error_dup_loop
	cmp		BYTE[rsi+rcx], ' '
	je		error_dup_loop
	cmp		BYTE[rsi+rcx], '+'
	je		error_dup_loop
	cmp		BYTE[rsi+rcx], '-'
	je		error_dup_loop

check_base_dup_loop_j:
	cmp		BYTE[rsi, rax], 0
	je		check_base_dup_loop_j_end
	push	rax
	mov		al, BYTE[rsi+rax]
	cmp		al, BYTE[rsi+rcx]
	pop		rax
	je		error_dup_loop
	inc		rax
	jmp		check_base_dup_loop_j

chack_base_dup_loop_j_end:
	inc		rcx
	jmp		check_base_dup_loop_i

check_base_dup_loop_i_end:
	jmp		skip_str_white_space

skip_str_white_space_inc:
	inc		rdi

skip_str_white_space:
	cmp		BYTE[rdi], 9
	je		skip_str_white_space_inc
	cmp		BYTE[rdi], 10
	je		skip_str_white_space_inc
	cmp		BYTE[rdi], 11
	je		skip_str_white_space_inc
	cmp		BYTE[rdi], 12
	je		skip_str_white_space_inc
	cmp		BYTE[rdi], 13
	je		skip_str_white_space_inc
	cmp		BYTE[rdi], ' '
	je		skip_str_white_space_inc

check_flag:
	push	r8
	xor		r8, r8
	jmp		check_flag_loop

is_minus:
	xor		r8b, 0x00000001

is_plus:
	inc		rdi

check_flag_loop:
	cmp		BYTE[rdi], '-'
	je		is_minus
	cmp		BYTE[rdi], '+'
	je		is_plus
	xor		rax, rax
	jmp		atoi_loop

atoi_loop:
	push	r9
	mov		r9, rcx

check_is_valid_str:
	dec		r9
	cmp		r9, -1
	je		atoi_end
	push	rax
	mov		al, BYTE[rdi]
	mov		r15b, BYTE[rsi+r9]
	cmp		al, BYTE[rsi+r9]
	pop		rax
	je		atoi
	jmp		check_is_valid_str

atoi:
	imul	rax, rcx
	add		rax, r9
	pop		r9
	inc		rdi
	jmp		atoi_loop

atoi_end:
	pop		r9
	cmp		r8, 0
	pop		r8
	pop		rcx
	jne		mul_minus
	ret

mul_minus:
	imul	rax, -1
	ret

error_dup_loop:
	pop		rcx

error:
	mov		rax, 0
	ret
