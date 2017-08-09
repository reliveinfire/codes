	.file	"permutation.c"
.globl myString
	.data
	.type	myString, @object
	.size	myString, 9
myString:
	.ascii	"123456789"
.globl used
	.bss
	.align 32
	.type	used, @object
	.size	used, 36
used:
	.zero	36
	.comm	sol,9,1
	.text
.globl swap
	.type	swap, @function
swap:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	-20(%rbp), %eax
	cltq
	movzbl	myString(%rax), %eax
	movb	%al, -1(%rbp)
	movl	-20(%rbp), %ecx
	movl	-24(%rbp), %eax
	cltq
	movzbl	myString(%rax), %edx
	movslq	%ecx, %rax
	movb	%dl, myString(%rax)
	movl	-24(%rbp), %eax
	cltq
	movzbl	-1(%rbp), %edx
	movb	%dl, myString(%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	swap, .-swap
	.section	.rodata
.LC0:
	.string	"MAX:%d\n"
	.text
.globl permutation
	.type	permutation, @function
permutation:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	%edx, -28(%rbp)
	movl	$.LC0, %eax
	movl	$128, %esi
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf
	movl	-20(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jne	.L4
	movl	$0, -8(%rbp)
	jmp	.L5
.L6:
	movl	-8(%rbp), %eax
	cltq
	movzbl	myString(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	putchar
	addl	$1, -8(%rbp)
.L5:
	movl	-8(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L6
	movl	$10, %edi
	call	putchar
.L4:
	movl	-20(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.L7
.L8:
	movl	-8(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	swap
	movl	-20(%rbp), %eax
	leal	1(%rax), %ecx
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	movl	%ecx, %edi
	call	permutation
	movl	-8(%rbp), %edx
	movl	-20(%rbp), %eax
	movl	%edx, %esi
	movl	%eax, %edi
	call	swap
	addl	$1, -8(%rbp)
.L7:
	movl	-8(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jle	.L8
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	permutation, .-permutation
.globl enum_permutation
	.type	enum_permutation, @function
enum_permutation:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movl	%esi, -24(%rbp)
	movl	-20(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jne	.L11
	movl	$0, -4(%rbp)
	jmp	.L12
.L13:
	movl	-4(%rbp), %eax
	cltq
	movzbl	sol(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	putchar
	addl	$1, -4(%rbp)
.L12:
	movl	-4(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jl	.L13
	movl	$10, %edi
	call	putchar
	jmp	.L18
.L11:
	movl	$0, -4(%rbp)
	jmp	.L15
.L17:
	movl	-4(%rbp), %eax
	cltq
	movl	used(,%rax,4), %eax
	testl	%eax, %eax
	jne	.L16
	movl	-4(%rbp), %eax
	cltq
	movl	$1, used(,%rax,4)
	movl	-20(%rbp), %ecx
	movl	-4(%rbp), %eax
	cltq
	movzbl	myString(%rax), %edx
	movslq	%ecx, %rax
	movb	%dl, sol(%rax)
	movl	-20(%rbp), %eax
	leal	1(%rax), %edx
	movl	-24(%rbp), %eax
	movl	%eax, %esi
	movl	%edx, %edi
	call	enum_permutation
	movl	-4(%rbp), %eax
	cltq
	movl	$0, used(,%rax,4)
.L16:
	addl	$1, -4(%rbp)
.L15:
	movl	-4(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jl	.L17
.L18:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	enum_permutation, .-enum_permutation
.globl main
	.type	main, @function
main:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	jmp	.L20
.L21:
	movl	-4(%rbp), %eax
	cltq
	movl	$0, used(,%rax,4)
	addl	$1, -4(%rbp)
.L20:
	cmpl	$8, -4(%rbp)
	jle	.L21
	movl	$3, %esi
	movl	$0, %edi
	call	enum_permutation
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-4)"
	.section	.note.GNU-stack,"",@progbits
