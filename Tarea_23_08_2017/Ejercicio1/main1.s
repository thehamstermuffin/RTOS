	.file	"main1.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$64, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	$3, -64(%ebp)
	movl	$67, -60(%ebp)
	movl	$34, -56(%ebp)
	movl	$222, -52(%ebp)
	movl	$45, -48(%ebp)
	movl	$75, -44(%ebp)
	movl	$54, -40(%ebp)
	movl	$34, -36(%ebp)
	movl	$44, -32(%ebp)
	movl	$33, -28(%ebp)
	movl	$22, -24(%ebp)
	movl	$11, -20(%ebp)
	movl	$66, -16(%ebp)
	movl	$0, -12(%ebp)
	movl	-64(%ebp), %eax
	movl	%eax, -4(%ebp)
	movb	$1, -5(%ebp)
	jmp	.L2
.L4:
	movsbl	-5(%ebp), %eax
	movl	-64(%ebp,%eax,4), %eax
	cmpl	-4(%ebp), %eax
	jle	.L3
	movsbl	-5(%ebp), %eax
	movl	-64(%ebp,%eax,4), %eax
	movl	%eax, -4(%ebp)
.L3:
	movzbl	-5(%ebp), %eax
	addl	$1, %eax
	movb	%al, -5(%ebp)
.L2:
	movsbl	-5(%ebp), %eax
	movl	-64(%ebp,%eax,4), %eax
	testl	%eax, %eax
	jne	.L4
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.section	.text.__x86.get_pc_thunk.ax,"axG",@progbits,__x86.get_pc_thunk.ax,comdat
	.globl	__x86.get_pc_thunk.ax
	.hidden	__x86.get_pc_thunk.ax
	.type	__x86.get_pc_thunk.ax, @function
__x86.get_pc_thunk.ax:
.LFB1:
	.cfi_startproc
	movl	(%esp), %eax
	ret
	.cfi_endproc
.LFE1:
	.ident	"GCC: (Debian 6.3.0-12) 6.3.0 20170406"
	.section	.note.GNU-stack,"",@progbits
