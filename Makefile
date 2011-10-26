# Makefile for ChaOS OS
# Author - Drew Cross

SOURCES = $(MULTIBOOT).o $(CHAOSKERNEL).o $(SCREEN).o $(COMMON).o $(STARTUPUTILS).o $(TABLES).o $(ISR).o $(INTERRUPTS).o
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
ISR = isr
INTERRUPTS = interrupts

CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-Tlink.ld
ASFLAGS=-felf

all: $(SOURCES) link

clean:
		-rm *.o kernel

link:
		ld $(LDFLAGS) -o kernel.bin $(SOURCES)

.s.o:
		nasm $(ASFLAGS) $<
