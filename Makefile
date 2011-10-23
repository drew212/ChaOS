# Makefile for ChaOS OS
# Author - Drew Cross


SOURCES = Multiboot.o ChaOSKernel.o screen.o common.o

CFLAGS = -Wall -Wextra -nostdlib -nostdinc -fno-stack-protector -nostartfiles -nodefaultlibs
LDFLAGS = -m elf_i386 -T linker.ld
ASFLAGS = -elf




all : $(SOURCES) link

Multiboot.o : Multiboot.s
	nasm -f elf -o Multiboot.o Multiboot.s

ChaOSKernel.o : ChaOSKernel.c
	gcc -m32 -o ChaOSKernel.o -c ChaOSKernel.c $(CFLAGS)

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
