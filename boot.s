
# Copyright (c) 2015 Connor Taffe <cpaynetaffe@gmail.com>
# The following code is adapted from code found at wiki.osdev.org.

.set ALIGN, 1<<0 # align loaded modules on page boundary
.set MEMINFO, 1<<1 # provide memory map
.set FLAGS, ALIGN | MEMINFO # multiboot "flag"
.set MAGIC, 0x1BADB002 # magic number, yes it's bad.
.set CHECKSUM, -(MAGIC + FLAGS) # checksum to prove we are in multiboot

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# C setup
.section .bootstrap_stack, "aw", @nobits
stack_bottom:
.skip 16384 # 16 kb stack
stack_top:

.section .text
.global _start
.type _start, @function
_start:
# kernel mode:

	movl $stack_top, %esp # esp points to top of stack
	call main # C entry point (main)

	cli # clear interrupts
	hlt # halt CPU until next interrupt

# infinite loop
.Lhang:
	jmp .Lhang

.size _start, . - _start # set size of start symbol (from here to _start).
