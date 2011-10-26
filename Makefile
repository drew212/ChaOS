# Makefile for ChaOS OS
# Author - Drew Cross


SOURCES = $(MULTIBOOT).o $(CHAOSKERNEL).o $($(SCREEN)).o $(COMMON).o $(STARTUPUTILS).o
CFLAGS = -Wall -Wextra -nostdlib -nostdinc -fno-stack-protector -nostartfiles -nodefaultlibs
LDFLAGS = -m elf_i386 -T linker.ld
ASFLAGS = -elf


# FILENAMES
STARTUPUTILS = StartupUtils
MULTIBOOT = Multiboot
CHAOSKERNEL = ChaOSKernel
SCREEN = screen
COMMON = common
TABLES = tables

all : $(SOURCES) link

$(MULTIBOOT).o : $(MULTIBOOT).s
	nasm -f elf -o $(MULTIBOOT).o $(MULTIBOOT).s

$(CHAOSKERNEL).o : $(CHAOSKERNEL).c $(CHAOSKERNEL).h $(STARTUPUTILS).s
	gcc -m32 -o $(CHAOSKERNEL).o -c $(CHAOSKERNEL).c $(CFLAGS)

$(STARTUPUTILS).o : $(STARTUPUTILS).s
	nasm -f elf -o $(STARTUPUTILS).o $(STARTUPUTILS).s

$($(SCREEN)).o : $(SCREEN).c $(SCREEN).h
	gcc -m32 -o $($(SCREEN)).o -c $(SCREEN).c $(CFLAGS)

$(COMMON).o : $(COMMON).c
	gcc -m32 -o $(COMMON).o -c $(COMMON).c $(CFLAGS)

$(TABLES).o : $(TABLES).c $(TABLES).h $(STARTUPUTILS).s
	gcc -m32 -o $(TABLES).o -c $(TABLES).c  $(CFLAGS)
#.s.o:
#	nasm $(ASFLAGS) $<

link:
	ld $(LDFLAGS) -o $(CHAOSKERNEL).bin $(SOURCES)

clean :
	rm *.o *.bin
