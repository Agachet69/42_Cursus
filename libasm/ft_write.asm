BITS 64

section .text
global _ft_write
extern ___error

_ft_write:

mov rax, 0x2000004
syscall
ret
