BITS 64

section .text
global _ft_read
extern ___error

_ft_read:

mov rax, 0x2000003
syscall
ret
