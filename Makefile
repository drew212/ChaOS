# Makefile for NuMu OS
# Author - Drew Cross


SOURCES = Multiboot.o NuMuKernel.o screen.o common.o

CFLAGS = -Wall -Wextra -nostdlib -nostdinc -fno-stack-protector -nostartfiles -nodefaultlibs
LDFLAGS = -m elf_i386 -T linker.ld
ASFLAGS = -elf




all : $(SOURCES) link

Multiboot.o : Multiboot.s
	nasm -f elf -o Multiboot.o Multiboot.s

NuMuKernel.o : NuMuKernel.c
	gcc -m32 -o NuMuKernel.o -c NuMuKernel.c $(CFLAGS)

screen.o : screen.c
	gcc -m32 -o screen.o -c screen.c $(CFLAGS)

common.o : common.c
	gcc -m32 -o common.o -c common.c $(CFLAGS)

#.s.o:
#	nasm $(ASFLAGS) $<

link:
	ld $(LDFLAGS) -o NuMuKernel.bin $(SOURCES)

clean :
	rm *.o *.bin
