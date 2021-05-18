BITS 64

extern ___error
extern _malloc
extern _ft_strlen
extern _ft_strcpy
section .text
global _ft_strdup

_ft_strdup:

push rsi
push rdi

call _ft_strlen
mov r9, rdi
mov rdi, rax
inc rdi
push r9

call _malloc
pop r9
mov rsi, r9
mov rdi, rax

call _ft_strcpy
pop rdi
pop rsi
ret
