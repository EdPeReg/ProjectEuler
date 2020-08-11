global _start

section .data
	TARGET equ 1000
	dSum   dw  0 

section .text
_start:
	mov eax, 1
	mov ecx, [TARGET]	

again:
	mov eax, 1
	inc eax
	loop again

	; Exit.
	mov rax, 60
	mov rdi, 0
	syscall


