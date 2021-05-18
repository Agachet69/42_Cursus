BITS 64

section .text
global _ft_strcpy
extern ___error

_ft_strcpy:

mov rcx, 0

while1:	cmp byte[rsi + rcx], 0
		je endwhile
		mov bh, byte[rsi + rcx]
		mov byte[rdi + rcx], bh
		inc rcx
		jmp while1

endwhile:	mov byte[rdi + rcx], 0
			mov rax, rdi
			ret
