	.file	"stack.c"
	.comm	stack,512,32
	.globl	top
	.bss
	.align 4
	.type	top, @object
	.size	top, 4
top:
	.zero	4
	.text
	.globl	push
	.type	push, @function
push:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, %eax
	movb	%al, -4(%rbp)
	movl	top(%rip), %eax
	movslq	%eax, %rdx
	leaq	stack(%rip), %rax
	movzbl	-4(%rbp), %ecx
	movb	%cl, (%rdx,%rax)
	movl	top(%rip), %eax
	addl	$1, %eax
	movl	%eax, top(%rip)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	push, .-push
	.globl	pop
	.type	pop, @function
pop:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	top(%rip), %eax
	subl	$1, %eax
	movl	%eax, top(%rip)
	movl	top(%rip), %eax
	movslq	%eax, %rdx
	leaq	stack(%rip), %rax
	movzbl	(%rdx,%rax), %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	pop, .-pop
	.globl	is_empty
	.type	is_empty, @function
is_empty:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	top(%rip), %eax
	testl	%eax, %eax
	sete	%al
	movzbl	%al, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	is_empty, .-is_empty
	.globl	buf
	.data
	.type	buf, @object
	.size	buf, 3
buf:
	.byte	97
	.byte	98
	.byte	99
	.text
	.globl	print_backward
	.type	print_backward, @function
print_backward:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	cmpl	$3, -4(%rbp)
	je	.L9
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, %edi
	call	print_backward
	movl	-4(%rbp), %eax
	movslq	%eax, %rdx
	leaq	buf(%rip), %rax
	movzbl	(%rdx,%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	putchar@PLT
	jmp	.L6
.L9:
	nop
.L6:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	print_backward, .-print_backward
	.section	.rodata
.LC0:
	.string	"%x\n"
.LC1:
	.string	"%d\n"
.LC2:
	.string	"-----------mask-------------"
	.text
	.globl	main
	.type	main, @function
main:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	$97, %edi
	call	push
	movl	$98, %edi
	call	push
	movl	$99, %edi
	call	push
	jmp	.L11
.L12:
	call	pop
	movsbl	%al, %eax
	movl	%eax, %edi
	call	putchar@PLT
.L11:
	call	is_empty
	testl	%eax, %eax
	je	.L12
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, %edi
	call	print_backward
	movl	$10, %edi
	call	putchar@PLT
	movl	$-805306381, -20(%rbp)
	movl	$872415228, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-20(%rbp), %eax
	sarl	$2, %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$1073741824, -16(%rbp)
	sall	-16(%rbp)
	movl	-16(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-16(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$-2147483648, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$-2147483648, %esi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	movl	$65280, -12(%rbp)
	movl	$305419896, -8(%rbp)
	movl	-8(%rbp), %eax
	andl	-12(%rbp), %eax
	shrl	$8, %eax
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7-20170407-0ubuntu2) 7.0.1 20170407 (experimental) [trunk revision 246759]"
	.section	.note.GNU-stack,"",@progbits
