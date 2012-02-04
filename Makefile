# Makefile for ChaOS OS
#
# This work is licensed under the Creative Commons Attribution-NonCommercial-
# ShareAlike 3.0 Unported License. To view a copy of this license, visit
# http://creativecommons.org/licenses/by-nc-sa/3.0/ or send a letter to:
# Creative Commons
# 444 Castro Street, Suite 900
# Mountain View, California, 94041, USA.
#
# Author(s): Drew Cross <drew@ddcross.com>



SOURCES = Multiboot.o ChaOSKernel.o screen.o common.o ChaOSKernelasm.o

CFLAGS = -Wall -Wextra -nostdlib -nostdinc -fno-stack-protector -nostartfiles -nodefaultlibs
LDFLAGS = -m elf_i386 -T linker.ld
ASFLAGS = -elf




all : $(SOURCES) link

Multiboot.o : Multiboot.s
	nasm -f elf -o Multiboot.o Multiboot.s

ChaOSKernel.o : ChaOSKernel.c ChaOSKernel.s
	gcc -m32 -o ChaOSKernel.o -c ChaOSKernel.c $(CFLAGS)

ChaOSKernelasm.o : ChaOSKernel.s
	nasm -f elf -o ChaOSKernelasm.o ChaOSKernel.s

screen.o : screen.c
	gcc -m32 -o screen.o -c screen.c $(CFLAGS)

common.o : common.c
	gcc -m32 -o common.o -c common.c $(CFLAGS)

#.s.o:
#	nasm $(ASFLAGS) $<

link:
	ld $(LDFLAGS) -o ChaOSKernel.bin $(SOURCES)

clean :
	rm *.o *.bin
