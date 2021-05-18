BITS 64

section .text
global _ft_strcmp
extern ___error

_ft_strcmp:

mov rcx, 0

while1:	cmp byte[rdi + rcx], 0
		je endwhile1
		mov bh, byte[rsi + rcx]
		if: cmp byte[rdi + rcx], bh
			jne endwhile1
		inc rcx
		jmp while1

endwhile1:	mov bh, byte[rsi + rcx]
			cmp byte[rdi + rcx], bh
			je retzero
			jl retless
			jg retgreater

retzero:	mov rax, 0
			ret

retless:	mov rax, -1
			ret

retgreater: mov rax, 1
			ret
