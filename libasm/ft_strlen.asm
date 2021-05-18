BITS 64

section .text
global _ft_strlen
extern ___error

_ft_strlen:

mov rcx, 0

while1: cmp byte[rdi + rcx], 0
		je endwhile
		inc rcx
		jmp while1

endwhile:	mov rax, rcx
			ret


